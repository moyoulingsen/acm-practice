# ABC449 G - Many Repunit Sum 2

## 网址

https://atcoder.jp/contests/abc449/tasks/abc449_g

## 题解

利用 `R_d = (10^d - 1) / 9`，把 `N` 个 repunit 的和转成 `N` 个 `10^0,10^1,...,10^{M-1}` 的和的计数问题。

可以转化为统计非负整数数组 `(A_0,A_1,...,A_{M-1})` 满足：

- `0 <= A_i <= 9`，其中 `0 <= i <= M-2`；
- `A_{M-1}` 无上界；
- `sum A_i <= N`；
- `sum A_i ≡ N (mod 9)`。

生成函数为：

```text
(1+x+...+x^9)^(M-1) / (1-x)
```

先求 `G(x)=(1+x+...+x^9)^(M-1)` 的前 `N` 项系数，再做前缀和表示除以 `(1-x)`。系数可用官方微分方程递推。

时间复杂度：`O(N)`，常数约为 10。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll M;
    cin >> N >> M;

    ll K = (M - 1) % MOD;

    vector<ll> inv(N + 1, 1);
    for (int i = 2; i <= N; i++) inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;

    vector<ll> g(N + 1);
    g[0] = 1;

    for (int n = 0; n < N; n++) {
        ll rhs = 0;
        for (int j = 0; j <= 8 && j <= n; j++) {
            rhs = (rhs + 1LL * (j + 1) * g[n - j]) % MOD;
        }
        rhs = rhs * K % MOD;

        ll known = 0;
        for (int i = 1; i <= 9 && i <= n; i++) {
            known = (known + 1LL * (n - i + 1) * g[n - i + 1]) % MOD;
        }

        g[n + 1] = (rhs - known + MOD) % MOD * inv[n + 1] % MOD;
    }

    ll ans = 0;
    ll prefix = 0;

    for (int s = 0; s <= N; s++) {
        prefix += g[s];
        if (prefix >= MOD) prefix -= MOD;

        if (s % 9 == N % 9) {
            ans += prefix;
            ans %= MOD;
        }
    }

    ans = (ans - N / 9) % MOD;
    if (ans < 0) ans += MOD;

    cout << ans << '\n';
    return 0;
}
```

## 样例验证

代码为生成函数递推实现。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
