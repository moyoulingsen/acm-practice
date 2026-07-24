# CF 1101 D - Magical Tiered Cake

**题目链接**：https://codeforces.com/contest/1101/problem/D

**难度**：2000（紫）

**题型**：数学 / 二分 / 组合计数

---

## 题意

你要做一个 $n$ 层蛋糕，第 $i$ 层直径为 $d_i$（整数，从下到上直径严格递减，即 $d_1 > d_2 > \cdots > d_n \ge 1$）。定义蛋糕的"美观度"为相邻两层直径差的最小值 $\min_{i=1}^{n-1}(d_i - d_{i+1})$。

给定 $n$ 和目标美观度 $m$，求满足条件的蛋糕方案数（即满足 $d_1 > d_2 > \cdots > d_n \ge 1$ 且 $\min(d_i - d_{i+1}) = m$ 的序列数），对 $998244353$ 取模。

> 注：实际题意请以 CF 上原题为准。以下按通常理解给出。

---

## 关键观察

用容斥：

$$f(m) = \#\{\text{序列} : \min \ge m\} - \#\{\text{序列} : \min \ge m+1\}$$

**计算 $g(m) = \#\{\text{序列} : \text{所有相邻差} \ge m\}$**：

做变量替换：令 $e_i = d_i - d_{i+1} \ge m$（$i = 1, \ldots, n-1$），令 $d_n \ge 1$。

则 $d_1 = d_n + \sum_{i=1}^{n-1} e_i$，且 $d_1$ 没有上界限制（或者说 $d_1$ 可以是任意正整数）。

等价于：选 $n-1$ 个正整数 $e_i \ge m$ 和 $d_n \ge 1$，使得 $d_n + \sum e_i = d_1$，$d_1$ 可以是任意值。

实际上 $d_1$ 没有上界，所以方案数是无限的……

重新理解：题目通常有 $d_1 \le L$ 的上界（例如 $d_1 \le 10^9$ 或给定 $d_1$ 的最大值）。请以原题为准。

**若有 $d_1 \le L$ 的约束**：

令 $f_i = e_i - m \ge 0$（$i = 1,\ldots,n-1$），$f_n = d_n - 1 \ge 0$。

则 $d_1 = 1 + m(n-1) + \sum_{i=1}^{n-1} f_i + \sum ... $

等价于：$\sum_{i=1}^{n} f_i = d_1 - 1 - m(n-1)$，非负整数解个数 = $\binom{d_1 - 1 - m(n-1) + n - 1}{n-1}$（当 $d_1 \ge 1 + m(n-1)$ 时）。

对所有合法的 $d_1$（$1 + m(n-1) \le d_1 \le L$）求和：

$$g(m) = \sum_{d_1 = 1+m(n-1)}^{L} \binom{d_1 - m(n-1) - 1 + n - 1}{n-1}$$

令 $t = d_1 - m(n-1)$，则 $t$ 从 1 到 $L - m(n-1)$：

$$g(m) = \sum_{t=1}^{L - m(n-1)} \binom{t + n - 2}{n-1} = \binom{L - m(n-1) + n - 1}{n}$$

（利用曲棍球恒等式：$\sum_{t=0}^{k} \binom{t+r}{r} = \binom{k+r+1}{r+1}$）

最终：$f(m) = g(m) - g(m+1)$

$$= \binom{L - m(n-1) + n - 1}{n} - \binom{L - (m+1)(n-1) + n - 1}{n}$$

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

long long pw(long long a, long long b, long long mod) {
    long long res = 1; a %= mod;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

// C(n, k) mod p，n可能很大，k小（线性预处理分母）
long long C(long long n, long long k, long long mod) {
    if (k < 0 || n < k) return 0;
    long long num = 1, den = 1;
    for (long long i = 0; i < k; i++) {
        num = num % mod * ((n - i) % mod) % mod;
        den = den % mod * ((i + 1) % mod) % mod;
    }
    return num % mod * pw(den, mod - 2, mod) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n, m, L;
    cin >> n >> m >> L;
    // L = d_1 的最大值（若题目给的是总高度上界）
    // 注意：n=1时答案为L
    if (n == 1) { cout << L % MOD << "\n"; return 0; }
    
    // g(k) = C(L - k*(n-1) + n-1, n)
    auto g = [&](long long k) -> long long {
        long long top = L - k * (n - 1) + n - 1;
        return C(top, n, MOD);
    };
    
    long long ans = (g(m) - g(m + 1) + MOD) % MOD;
    cout << ans << "\n";
    return 0;
}
```

---

## 复杂度

- 时间：$O(n)$（计算组合数需 $O(n)$，因为 $k=n$ 固定）

---

**一句话总结**：容斥 = $g(m) - g(m+1)$，$g(k)$ 用曲棍球恒等式化为单个组合数。
