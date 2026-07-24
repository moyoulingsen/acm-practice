# CF 1099 D - Maximum Sum of Digits

**题目链接**：https://codeforces.com/contest/1099/problem/D

**难度**：1900（紫）

**题型**：数学 / 贪心

---

## 题意

给定正整数 $n$，找两个正整数 $a, b$，使得 $a + b = n$ 且 $S(a) + S(b)$ 最大，其中 $S(x)$ 是 $x$ 的各位数字之和。

---

## 关键观察

数字和的最大值发生在数字尽量多 9 时：令 $a = 10^k - 1$（全是 9 的数），令 $b = n - a$。

具体来说：
1. 令 $a$ 为不超过 $n$ 的、位数与 $n$ 相同的"全 9" 数，即 $a = 10^{\lfloor\log_{10}n\rfloor} - 1$。
2. $b = n - a$。
3. 此时 $S(a) = 9 \times \lfloor\log_{10}n\rfloor$，而 $b$ 的首位是 $n$ 的首位减去 1 后的结果，其余位全是 9——$S(b)$ 也得到最大化。

**为什么最优解一定是这种结构？**

对任意拆分 $a + b = n$，考虑进位：有进位时数字和会减少。要让总数字和最大，就要让进位最少。全 9 的 $a$ 保证了 $b = n - a$ 在计算时不会产生任何借位，$b$ 的每一位都是 $n$ 对应位减去 9 后的自然结果，数字和之和等于 $9 \times (位数-1) + S(n)$，这已是理论上界。

---

## 思路

1. 求 $n$ 的位数 $d = \lfloor\log_{10}n\rfloor + 1$。
2. 令 $a = 10^{d-1} - 1$（$d-1$ 个 9）。
3. $b = n - a$。
4. 输出 $S(a) + S(b)$。

特判：$n$ 本身就是个位数时，$a=0$ 不合法，直接输出 $S(n)$（取 $a=n, b=0$ 不合法，实际取 $a=n-1, b=1$）。

---

## 复杂度

- 时间：$O(\log n)$

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

long long digitSum(long long x) {
    long long s = 0;
    while (x > 0) { s += x % 10; x /= 10; }
    return s;
}

int main() {
    long long n;
    cin >> n;
    // a = 10^(digits-1) - 1，即 n 位数下的全9数（少一位）
    long long a = 1;
    while (a * 10 <= n) a *= 10;
    a -= 1; // a = 10^(d-1) - 1
    long long b = n - a;
    cout << digitSum(a) + digitSum(b) << "\n";
    return 0;
}
```

---

**一句话总结**：令 $a$ 为比 $n$ 少一位的全 9 数，剩下给 $b$，可以保证数字和最大。
