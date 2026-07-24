# CF 2241 B - Good times Good times

**题目链接**：<https://codeforces.com/problemset/problem/2241/B>

**题型**：数学 / 构造

**难度体感**：B 题，关键是构造 `10^d+1` 让乘积变成拼接。

---

## 题意压缩

给一个好数 `x`，需要构造一个整数 `y`，使得：

- `y` 也是好数；
- `x * y` 也是好数。

这里“好数”的具体定义由题目给出，核心限制是数字中只出现允许的数位。

---

## 关键观察

设 `x` 有 `d` 位。

选择：

\[
y = 10^d + 1
\]

则：

\[
x \cdot y = x \cdot 10^d + x
\]

这正好是把 `x` 拼接到自己后面。

例如：

\[
123 \times 1001 = 123123
\]

因此 `x*y` 的数位集合和 `x` 完全相同，自然仍然是好数。

---

## 思路步骤

1. 读入 `x`。
2. 计算 `10^d`，其中 `d` 是 `x` 的位数。
3. 输出 `10^d + 1`。

---

## 易错点

- 这里不是找最小 `y`，只要输出任意合法 `y`；
- `10^d + 1` 一定只含 `1` 和 `0`；
- 用原始 `x` 计算位数时可以不断除以 10。

---

## 复杂度

\[
O(\log_{10} x)
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
        long long x;
        cin >> x;

        long long p = 1;
        while (x > 0) {
            p *= 10;
            x /= 10;
        }

        cout << p + 1 << '\n';
    }

    return 0;
}
```

---

## 一句话总结

令 `y=10^d+1`，那么 `x*y` 就是 `x` 和 `x` 的拼接。
