# ABC458 E - Count 123

## 网址

https://atcoder.jp/contests/abc458/tasks/abc458_e

## 题解

要求由恰好 `X1` 个 `1`、`X2` 个 `2`、`X3` 个 `3` 组成，且不能出现相邻的 `1,3` 或 `3,1`。

只看由 `1` 和 `3` 构成的子序列 `B`。`B` 中每一处相邻的不同块之间，原序列里必须至少插入一个 `2`。

按 `B` 的首尾分类：

1. `B` 以 `1` 开始、以 `1` 结束；
2. `B` 以 `3` 开始、以 `3` 结束；
3. `B` 以 `1` 开始、以 `3` 结束；
4. `B` 以 `3` 开始、以 `1` 结束。

用隔板法计算 `1` 和 `3` 分成若干非空块的方案数，再把必要的 `2` 插入相邻异值块之间，剩余位置任意放 `2`。

设 `part(n,k)=C(n-1,k-1)` 表示把 `n` 个相同元素分成 `k` 个非空块。

时间复杂度：`O(X1+X2+X3)` 预处理组合数，`O(X1+X3)` 枚举块数。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 998244353;

ll mod_pow(ll a, ll e) {
    ll r = 1;
    while (e > 0) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

vector<ll> fact, ifact;

void init_comb(int n) {
    fact.assign(n + 1, 1);
    ifact.assign(n + 1, 1);

    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;

    ifact[n] = mod_pow(fact[n], MOD - 2);
    for (int i = n; i >= 1; i--) ifact[i - 1] = ifact[i] * i % MOD;
}

ll C(ll n, ll k) {
    if (n < 0 || k < 0 || k > n) return 0;
    return fact[n] * ifact[k] % MOD * ifact[n - k] % MOD;
}

ll part(ll n, ll k) {
    return C(n - 1, k - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll X1, X2, X3;
    cin >> X1 >> X2 >> X3;

    ll N = X1 + X2 + X3;
    init_comb((int)N);

    ll ans = 0;

    for (ll i = 1; i <= X1; i++) {
        ll term = part(X1, i) * part(X3, i - 1) % MOD;
        term = term * C(N - (2 * i - 2), X1 + X3) % MOD;
        ans = (ans + term) % MOD;
    }

    for (ll i = 1; i <= X3; i++) {
        ll term = part(X3, i) * part(X1, i - 1) % MOD;
        term = term * C(N - (2 * i - 2), X1 + X3) % MOD;
        ans = (ans + term) % MOD;
    }

    for (ll i = 1; i <= min(X1, X3); i++) {
        ll term = part(X1, i) * part(X3, i) % MOD;
        term = term * C(N - (2 * i - 1), X1 + X3) % MOD;
        ans = (ans + 2 * term) % MOD;
    }

    cout << ans << '\n';
    return 0;
}
```

## 样例验证

```text
输入
2 2 1

输出
9
```

```text
输入
5 3 4

输出
204
```

```text
输入
998244 998353 998107

输出
701926019
```
