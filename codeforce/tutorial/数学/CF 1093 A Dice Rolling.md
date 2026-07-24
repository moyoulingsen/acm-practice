# CF 1093 A - Dice Rolling

**题目链接**：<https://codeforces.com/problemset/problem/1093/A>

**题型**：数学 / 贪心

**难度体感**：A 题，结论型。

---

## 题意压缩

给你一个整数 `x`，要把它拆成若干个数，使某个目标量最大/最优。

这题最后会化成一个非常直接的结论：

\[
\left\lfloor \frac{x}{2} \right\rfloor
\]

---

## 关键观察

最优策略是尽量多地取 `2`。

因为：

- 取更大的数不会更优；
- 取 `1` 又会浪费结构；
- 所以最终最优值就是 `x` 能拆出多少个 `2`。

因此答案就是：

\[
\lfloor x/2 \rfloor
\]

---

## 思路步骤

1. 读入 `x`
2. 输出 `x/2`

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
        int x;
        cin >> x;
        cout << x / 2 << '\n';
    }
    return 0;
}
```

---

## 一句话总结

这题就是：**答案直接等于 `x/2` 向下取整。**
