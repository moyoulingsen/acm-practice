# CF 2218 D - The 67th OEIS Problem

**题目链接**：<https://codeforces.com/problemset/problem/2218/D>

**对应题单**：CF 1090 Div.4 D

**题型**：数学 / 构造 / gcd

**难度**：1100

---

## 题意压缩

需要构造长度为 `n` 的正整数序列，使相邻两项的 `gcd` 都两两不同。

---

## 关键观察

考虑构造：

\[
a_i = k(k+2)
\]

其中 `k` 依次取奇数：`1,3,5,...`。

相邻两项分别是：

\[
k(k+2),\quad (k+2)(k+4)
\]

它们的最大公因数至少有共同因子 `k+2`。由于相邻奇数只差 `2`，额外部分不会引入相同的大公共因子，构造出来的相邻 gcd 依次为：

\[
3,5,7,\dots
\]

所以所有相邻 gcd 两两不同。

---

## 思路步骤

1. 从 `k=1` 开始。
2. 每次输出 `k*(k+2)`。
3. `k += 2`。

---

## 复杂度

`O(n)`。

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        long long k = 1;
        for (int i = 0; i < n; ++i) {
            cout << k * (k + 2) << " \n"[i + 1 == n];
            k += 2;
        }
    }

    return 0;
}
```

---

## 一句话总结

输出相邻项共享不同奇因子的序列 `k(k+2)`，相邻 gcd 就会依次不同。
