# CF 1091 A - New Year and the Christmas Ornament

**题目链接**：<https://codeforces.com/problemset/problem/1091/A>

**题型**：贪心 / 枚举

**难度体感**：A 题，关键是把三个数之间的关系翻译成连续值。

---

## 题意压缩

有三种颜色的装饰品，数量分别是 `y,b,r`。

你要选出三个数：

- 黄色选 `x`
- 蓝色选 `x+1`
- 红色选 `x+2`

要求都不能超过各自库存，并使总数最大。

也就是最大化：

\[
x + (x+1) + (x+2) = 3x+3
\]

---

## 关键观察

既然三种颜色必须是连续的：

- 黄：`x`
- 蓝：`x+1`
- 红：`x+2`

那么 `x` 不能太大，必须同时满足：

\[
x \le y
\]
\[
x+1 \le b \Rightarrow x \le b-1
\]
\[
x+2 \le r \Rightarrow x \le r-2
\]

所以最优的 `x` 就是：

\[
x = \min(y, b-1, r-2)
\]

答案自然就是：

\[
3x+3
\]

---

## 思路步骤

1. 读入 `y,b,r`
2. 取 `x=min(y,b-1,r-2)`
3. 输出 `3*x+3`

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

    long long y, b, r;
    cin >> y >> b >> r;

    long long x = min({y, b - 1, r - 2});
    cout << 3 * x + 3 << '\n';
    return 0;
}
```

---

## 一句话总结

这题就是：**把三种颜色都表示成 `x,x+1,x+2`，再取最大的可行 `x`。**
