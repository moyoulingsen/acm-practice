# CF 1096 A - Find Divisible

**题目链接**：<https://codeforces.com/problemset/problem/1096/A>

**题型**：构造 / 数学

**难度体感**：A 题标准送分，关键是把条件直接翻译成构造。

---

## 题意压缩

给你一个区间 `[l,r]`。

要找到两个整数 `x,y`，满足：

- `l \le x < y \le r`
- `y` 能被 `x` 整除

---

## 关键观察

最简单的想法就是直接取：

\[
x=l,\quad y=2l
\]

因为这样必然有：

\[
y \bmod x = 0
\]

所以问题只剩下：

- `2l` 是否还在区间里？

题目保证有解时，直接输出 `(l,2l)` 就行。

---

## 为什么这样一定对

因为：

- `x=l` 合法；
- `y=2l > l`；
- `2l` 显然是 `l` 的倍数。

所以只要 `2l \le r`，答案就是成立的。

而本题的测试保证这种构造可行。

---

## 思路步骤

1. 读入 `l,r`
2. 输出 `l, 2l`

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
        long long l, r;
        cin >> l >> r;
        cout << l << ' ' << 2 * l << '\n';
    }
    return 0;
}
```

---

## 一句话总结

这题就是：**直接构造 `(l,2l)`。**
