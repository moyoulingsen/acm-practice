# ABC467 E - Adjacent Sums (hard)

## 网址

https://atcoder.jp/contests/abc467/tasks/abc467_e

## 题解

和 C 题一样，设最终每个位置模 `M` 后的值为 `C_i`，需要满足：

```text
C_i + C_{i+1} ≡ B_i (mod M)
```

只要确定 `C_1 = t`，整个数组 `C` 就唯一确定。递推可得：

```text
C_i ≡ (-1)^{i-1} t + d_i (mod M)
```

其中 `d_1 = 0`，并且 `d_{i+1} = B_i - d_i (mod M)`。

如果目标余数是 `C_i`，从 `A_i` 变到这个余数需要的最少操作数是：

```text
(C_i - A_i) mod M
```

于是答案变成在 `t = 0 ... M-1` 中最小化若干个形如：

```text
(t + p) mod M
(-t + p) mod M
```

的和。

这些函数都是锯齿状的分段线性函数。随着 `t` 从小到大：

- `(t + p) mod M` 每次通常增加 `1`，在 `t = M - p` 处跳回去，函数值减少 `M`；
- `(-t + p) mod M` 每次通常减少 `1`，在 `t = p + 1` 处跳上去，函数值增加 `M`。

因此只需要维护 `t = 0` 时的函数值、当前斜率，以及所有跳变事件，按事件位置从小到大扫描即可。

时间复杂度：`O(N log N)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll norm(ll x, ll m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll M;
    cin >> N >> M;

    vector<ll> A(N), B(N - 1);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i + 1 < N; i++) cin >> B[i];

    vector<pair<ll, ll>> events;
    ll d = 0;
    ll cur = 0;
    ll slope = 0;

    for (int i = 0; i < N; i++) {
        ll p = norm(d - A[i], M);
        cur += p;

        if (i % 2 == 0) {
            slope++;
            if (p != 0) events.push_back({M - p, -M});
        } else {
            slope--;
            if (p != M - 1) events.push_back({p + 1, M});
        }

        if (i + 1 < N) d = norm(B[i] - d, M);
    }

    sort(events.begin(), events.end());

    ll ans = cur;
    ll prev = 0;

    for (int i = 0; i < (int)events.size();) {
        ll pos = events[i].first;
        ll add = 0;

        while (i < (int)events.size() && events[i].first == pos) {
            add += events[i].second;
            i++;
        }

        if (prev <= pos - 1) {
            ans = min(ans, cur + slope * (pos - 1 - prev));
        }

        cur += slope * (pos - prev) + add;
        ans = min(ans, cur);
        prev = pos;
    }

    if (prev <= M - 1) {
        ans = min(ans, cur + slope * (M - 1 - prev));
    }

    cout << ans << '\n';
    return 0;
}
```

## 样例验证

代码没有枚举 `M` 个起点，而是只扫描函数斜率变化的位置，适合 `M` 很大的 hard 版。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
