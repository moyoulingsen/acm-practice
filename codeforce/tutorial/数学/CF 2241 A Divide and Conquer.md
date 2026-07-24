# CF 2241 A - Divide and Conquer

**题目链接**：<https://codeforces.com/problemset/problem/2241/A>

**题型**：数学 / 因子判断

**难度体感**：A 题，核心是看清一次操作能把 `x` 变成它的任意因子。

---

## 题意压缩

给两个整数 `x,y`。一次操作可以选择 `x` 的一个因子 `z`，然后令：

\[
x := \frac{x}{z}
\]

问能不能通过若干次操作把 `x` 变成 `y`。

---

## 关键观察

因为每次操作后的新值仍然是原来 `x` 的因子，所以不管操作多少次，最终能到达的数都必须是初始 `x` 的因子。

反过来，如果 `y` 本身是 `x` 的因子，那么直接选择：

\[
z = \frac{x}{y}
\]

一次就能到达 `y`。

所以答案只取决于：

\[
x \bmod y = 0
\]

---

## 思路步骤

1. 读入 `x,y`。
2. 如果 `x % y == 0`，输出 `YES`。
3. 否则输出 `NO`。

---

## 易错点

- 不需要真的模拟多次操作；
- 因子的因子仍然是原数的因子。

---

## 复杂度

\[
O(1)
\]

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
        long long x, y;
        cin >> x >> y;
        cout << (x % y == 0 ? "YES" : "NO") << '\n';
    }

    return 0;
}
```

---

## 一句话总结

能到达的数正好是原数的因子，所以只要判断 `y | x`。
