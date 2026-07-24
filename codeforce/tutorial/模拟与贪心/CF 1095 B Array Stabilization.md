# CF 1095 B - Array Stabilization

**题目链接**：<https://codeforces.com/problemset/problem/1095/B>

**题型**：排序 / 贪心

**难度体感**：B 题经典观察题。

---

## 题意压缩

给一个数组，你可以删掉**一个**元素。

定义数组的不稳定度为：

\[
\max(a)-\min(a)
\]

要求删掉一个元素后，让这个值尽量小。

---

## 关键观察

删掉中间元素没有意义。

因为不稳定度只和：

- 最小值
- 最大值

有关。

所以你只可能删：

- 当前最小值
- 或当前最大值

设排序后数组为：

\[
a_0 \le a_1 \le ... \le a_{n-1}
\]

那么答案只可能是：

- 删最小值：`a[n-1] - a[1]`
- 删最大值：`a[n-2] - a[0]`

取最小即可。

---

## 思路步骤

1. 排序数组
2. 计算两种删法
3. 输出较小值

---

## 复杂度

排序占主导：

\[
O(n\log n)
\]

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());
    cout << min(a[n - 1] - a[1], a[n - 2] - a[0]) << '\n';
    return 0;
}
```

---

## 一句话总结

这题核心是：**只可能删最小值或最大值，中间元素不影响极差。**
