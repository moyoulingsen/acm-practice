# ABC459 F - -1, +1

## 网址

https://atcoder.jp/contests/abc459/tasks/abc459_f

## 题解

一次操作可以选择 `i`，令：

```text
A_i -= 1
A_{i+1} += 1
```

每次操作相当于把 `1` 向右移动一步。要求最少操作次数，使序列严格递增。

令下标从 `0` 开始，定义：

```text
D_i = A_i - i
```

则 `A_i < A_{i+1}` 等价于：

```text
D_i <= D_{i+1}
```

所以目标变成把 `D` 变成非降序列。操作把一个单位从 `D_i` 移到 `D_{i+1}`，总和不变。一次操作会使加权和 `sum i*D_i` 增加 `1`，因此最少操作数等于最终非降序列加权和减去初始加权和。

需要在所有总和不变的非降序整数序列中，找到加权和最小的一个。这可以用“相邻块平均值不下降”的栈维护。每个块用 `(值, 个数)` 表示。新加入一个值后，如果前一个块的值大于等于当前块，就合并，并把合并后的总和尽量平均分配：

```text
q = floor(sum / len)
r = sum - q*len
```

块内最终为 `q` 重复 `len-r` 次，`q+1` 重复 `r` 次。

时间复杂度：所有测试总 `O(N)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using i128 = __int128_t;

pair<ll, ll> floor_div_mod(ll s, ll w) {
    ll q = s / w;
    ll r = s % w;
    if (r < 0) {
        q--;
        r += w;
    }
    return {q, r};
}

void print_i128(i128 x) {
    if (x == 0) {
        cout << 0;
        return;
    }
    if (x < 0) {
        cout << '-';
        x = -x;
    }

    string s;
    while (x > 0) {
        s.push_back(char('0' + x % 10));
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<ll> D(N);
        for (int i = 0; i < N; i++) {
            ll a;
            cin >> a;
            D[i] = a - i;
        }

        vector<pair<ll, ll>> st;
        st.push_back({LLONG_MIN / 4, 0});

        for (ll x : D) {
            ll total = x;
            ll width = 1;
            auto [height, rem] = floor_div_mod(total, width);

            while (st.back().first >= height) {
                auto [h, w] = st.back();
                st.pop_back();

                total += h * w;
                width += w;
                tie(height, rem) = floor_div_mod(total, width);
            }

            st.push_back({height, width - rem});
            if (rem > 0) st.push_back({height + 1, rem});
        }

        i128 before = 0;
        for (int i = 0; i < N; i++) before += (i128)i * D[i];

        i128 after = 0;
        ll pos = 0;
        for (int i = 1; i < (int)st.size(); i++) {
            auto [h, w] = st[i];
            i128 sumPos = (i128)(pos + pos + w - 1) * w / 2;
            after += sumPos * h;
            pos += w;
        }

        print_i128(after - before);
        cout << '\n';
    }

    return 0;
}
```

## 样例验证

代码把严格递增转成非降序整数序列投影，并用加权和差值表示操作次数。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
