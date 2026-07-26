# CF 1097 D - Makoto and a Blackboard

**题目链接**：<https://codeforces.com/problemset/problem/1097/D>

**题型**：数学 / 期望 DP / 质因数分解

---

## 题意压缩

从 `n` 开始，每次等概率选择当前数的一个约数替换当前数，求 `k` 次后的期望。

---

## 关键观察

随机约数等价于每个质因数指数独立地从 `0..e` 中选。对每个质因数单独做期望 DP，最后相乘。

---

## 思路步骤

1. 分解 `n`。
2. 对 `p^a` 初始化 `dp[j]=p^j`。
3. 转移 `ndp[j]=(dp[0]+...+dp[j])/(j+1)`。
4. 所有质因数贡献相乘。

---

## 复杂度

`O(sqrt(n) + kA)`，`A` 是质因数指数和。

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1000000007;

ll mod_pow(ll a, ll e) {
    ll r = 1;
    a %= MOD;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

ll solve(ll p, int a, int k, const vector<ll> &inv) {
    vector<ll> dp(a + 1);
    dp[0] = 1;
    for (int i = 1; i <= a; ++i) dp[i] = dp[i - 1] * (p % MOD) % MOD;
    while (k--) {
        vector<ll> ndp(a + 1);
        ll pref = 0;
        for (int j = 0; j <= a; ++j) {
            pref = (pref + dp[j]) % MOD;
            ndp[j] = pref * inv[j + 1] % MOD;
        }
        dp.swap(ndp);
    }
    return dp[a];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    int k;
    cin >> n >> k;
    vector<ll> inv(70);
    for (int i = 1; i < 70; ++i) inv[i] = mod_pow(i, MOD - 2);

    ll ans = 1, x = n;
    for (ll p = 2; p * p <= x; ++p) {
        if (x % p) continue;
        int c = 0;
        while (x % p == 0) x /= p, c++;
        ans = ans * solve(p, c, k, inv) % MOD;
    }
    if (x > 1) ans = ans * solve(x, 1, k, inv) % MOD;
    cout << ans << '\n';
    return 0;
}
```

---

## 一句话总结

把随机约数拆成质因数指数的独立期望 DP。
