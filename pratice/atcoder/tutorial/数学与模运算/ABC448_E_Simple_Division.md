# ABC448 E - Simple Division

## 网址

https://atcoder.jp/contests/abc448/tasks/abc448_e

## 题解

只需求出 `r = N mod (M * 10007)`，答案就是 `r / M`。

设 `N = qM + s`，其中 `0 <= s < M`，则：

```text
N mod (M * 10007) = (q mod 10007) * M + s
```

因此对这个余数整除 `M`，就得到 `floor(N/M) mod 10007`。

接下来根据游程压缩构造 `N mod MOD`。如果当前值是 `cur`，后面追加 `l` 个数字 `c`，则：

```text
cur' = cur * 10^l + c * 111...111
```

用倍增预处理 `10^(2^k)` 和长度为 `2^k` 的 repunit，即可 `O(log l)` 处理一段。

时间复杂度：`O(K log max(l_i))`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    int64 M;
    cin >> K >> M;

    vector<int64> c(K), l(K);
    for (int i = 0; i < K; i++) cin >> c[i] >> l[i];

    int64 MOD = M * 10007LL;
    const int LOG = 31;

    vector<int64> pow10(LOG), rep(LOG);
    pow10[0] = 10 % MOD;
    rep[0] = 1 % MOD;

    for (int i = 1; i < LOG; i++) {
        pow10[i] = pow10[i - 1] * pow10[i - 1] % MOD;
        rep[i] = (rep[i - 1] * pow10[i - 1] + rep[i - 1]) % MOD;
    }

    auto calc = [&](int64 len) {
        int64 p = 1 % MOD;
        int64 r = 0;

        for (int i = 0; i < LOG; i++) {
            if ((len >> i) & 1LL) {
                r = (r * pow10[i] + rep[i]) % MOD;
                p = p * pow10[i] % MOD;
            }
        }

        return pair<int64, int64>(p, r);
    };

    int64 cur = 0;
    for (int i = 0; i < K; i++) {
        auto [p, r] = calc(l[i]);
        cur = (cur * p + c[i] * r) % MOD;
    }

    cout << cur / M << '\n';
    return 0;
}
```

## 样例验证

代码直接实现模数压缩与倍增追加数字。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
