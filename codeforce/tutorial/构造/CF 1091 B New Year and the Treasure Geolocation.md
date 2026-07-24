# CF 1091 B - New Year and the Treasure Geolocation

**题目链接**：<https://codeforces.com/problemset/problem/1091/B>

**题型**：构造 / 观察

**难度体感**：B 题里很典型的“答案被数据唯一锁死”的题。

---

## 题意压缩

给你两组点：

- 第一组有 `n` 个点 `a_i`
- 第二组有 `n` 个点 `b_i`

存在一个固定点 `p`，使得第一组中的每个点都能和第二组中的某个点配对，并满足：

\[
a_i + b_j = p
\]

要求输出这个固定点 `p=(x,y)`。

---

## 关键观察

因为答案点 `p` 对所有配对都一样，所以它一定等于：

- 某个 `a_i`
- 加上与它配对的那个 `b_j`

而题目保证答案唯一。

一个非常常见的做法是：

- 取第一组里任意一个点，比如 `a[0]`
- 枚举第二组每个点 `b[j]`
- 猜测答案是 `p = a[0] + b[j]`
- 检查第一组所有点是否都能在第二组里找到对应补点

因为 `n` 很小，这样直接枚举就够了。

---

## 怎么检查一个候选答案

如果候选答案是：

\[
p=(X,Y)
\]

那么对于第一组里的每个点 `(x_i,y_i)`，都必须存在第二组里的点：

\[
(X-x_i,\ Y-y_i)
\]

所以可以把第二组所有点放进一个集合里，然后逐个检查即可。

---

## 思路步骤

1. 读入两组点。
2. 用 `set` 存第二组点。
3. 固定第一组第一个点 `a[0]`。
4. 枚举第二组每个点 `b[j]`，令候选答案 `p=a[0]+b[j]`。
5. 检查所有 `a[i]` 是否都能在第二组中找到补点。
6. 找到后直接输出。

---

## 复杂度

设 `n` 为点数。

- 枚举候选答案：`n`
- 每次检查：`n` 次集合查询

总复杂度：

\[
O(n^2 \log n)
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
    vector<pair<int, int>> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
    for (int i = 0; i < n; ++i) cin >> b[i].first >> b[i].second;

    set<pair<int, int>> sb(b.begin(), b.end());

    for (int j = 0; j < n; ++j) {
        int X = a[0].first + b[j].first;
        int Y = a[0].second + b[j].second;
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            pair<int, int> need = {X - a[i].first, Y - a[i].second};
            if (!sb.count(need)) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << X << ' ' << Y << '\n';
            return 0;
        }
    }
    return 0;
}
```

---

## 一句话总结

这题核心是：**固定一个点，枚举它和第二组点配出来的候选答案，再验证全体。**
