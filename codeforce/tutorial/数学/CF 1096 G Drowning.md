# CF 1096 G - Drowning

**题目链接**：<https://codeforces.com/problemset/problem/1096/G>

**题型**：FFT / NTT / 卷积计数

**难度体感**：高于一般紫名稳定范围，但很值得知道这类题的存在。

---

## 为什么把它也纳入

你说的是“紫名以下应该会”的范围，而这类题虽然不一定要求你现在就能裸手秒掉，
但至少要建立识别能力：

- 一看到大规模卷积计数，
- 就要想到 FFT / NTT / 生成函数。

这本身就是实力边界的一部分。

---

## 识别信号

当题目出现下面这些特征时，要立刻警觉：

- 统计两两和 / 差 / 配对数量；
- 朴素做法是双重枚举；
- 值域较大但可作为下标；
- 需要批量求很多“和为 x”的答案。

这就是卷积味道。

---

## 常见思路

1. 把一个集合出现情况写成多项式；
2. 多项式相乘后，系数表示配对数量；
3. 需要快速相乘时，用 FFT / NTT。

---

## 参考代码

下面给一份 NTT 卷积模板，作为这类题的参考代码框架：

```cpp
#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int G = 3;

long long qpow(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

void ntt(vector<int> &a, bool invert) {
    int n = (int)a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        long long wlen = qpow(G, (MOD - 1) / len);
        if (invert) wlen = qpow(wlen, MOD - 2);
        for (int i = 0; i < n; i += len) {
            long long w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i + j];
                int v = (int)(a[i + j + len / 2] * w % MOD);
                a[i + j] = u + v < MOD ? u + v : u + v - MOD;
                a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + MOD;
                w = w * wlen % MOD;
            }
        }
    }

    if (invert) {
        long long inv_n = qpow(n, MOD - 2);
        for (int &x : a) x = (int)(x * inv_n % MOD);
    }
}

vector<int> multiply(vector<int> a, vector<int> b) {
    int n = 1;
    while (n < (int)a.size() + (int)b.size()) n <<= 1;
    a.resize(n);
    b.resize(n);
    ntt(a, false);
    ntt(b, false);
    for (int i = 0; i < n; i++) a[i] = 1LL * a[i] * b[i] % MOD;
    ntt(a, true);
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> A(m + 1), B(m + 1);
    for (int i = 0; i <= m; ++i) cin >> A[i];
    for (int i = 0; i <= m; ++i) cin >> B[i];

    vector<int> C = multiply(A, B);
    for (int i = 0; i <= 2 * m; ++i) cout << C[i] << ' ';
    cout << '\n';
    return 0;
}
```

> 这份代码是卷积题的标准 NTT 框架。你以后精修原题时，只需要把“如何把题目转成多项式系数”这一步补进去。

---

## 这题放进 tutorial 的意义

不是要求你现在立刻把实现背下来，
而是让你以后看到类似题时，能第一时间识别：

> 这不是普通计数，这是卷积计数。

---

## 一句话总结

大规模“配对和/差计数”看到就要想到：**把集合写成多项式，再做卷积。**
