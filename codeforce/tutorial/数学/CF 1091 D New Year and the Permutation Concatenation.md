# CF 1091 D - New Year and the Permutation Concatenation

**题目链接**：<https://codeforces.com/problemset/problem/1091/D>

**题型**：数学 / 组合计数 / 阶乘

---

## 题意压缩

把 `1..n` 的全部排列拼接起来，统计多少个长度为 `n` 的连续子数组本身也是一个排列。答案对 `998244353` 取模。

---

## 关键观察

合法窗口要么完整落在某个排列内，要么跨越相邻排列边界。化简后公式为 `ans = n * n! - sum_{k=1}^{n-1} n! / k!`。

---

## 思路步骤

1. 预处理阶乘和逆阶乘。
2. 令 `ans = n * fac[n]`。
3. 对 `k=1..n-1` 减去 `fac[n] * ifac[k]`。

---

## 复杂度

`O(n)`。

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 998244353;

ll mod_pow(ll a, ll e) {
    ll r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> fac(n + 1), ifac(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % MOD;
    ifac[n] = mod_pow(fac[n], MOD - 2);
    for (int i = n; i >= 1; --i) ifac[i - 1] = ifac[i] * i % MOD;

    ll ans = 1LL * n * fac[n] % MOD;
    for (int k = 1; k < n; ++k) {
        ans = (ans - fac[n] * ifac[k]) % MOD;
        if (ans < 0) ans += MOD;
    }
    cout << ans << '\n';
    return 0;
}
```

---

## 一句话总结

用 `n * n!` 减去所有边界不合法贡献。
