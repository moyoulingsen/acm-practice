# CF 2222 D - Permutation Construction

**题目链接**：<https://codeforces.com/problemset/problem/2222/D>

**对应题单**：Codeforces Round 1094 D

**题型**：构造 / 排序 / 前缀和

**难度**：1800（蓝）

---

## 题意压缩

给定数组 `a`，需要构造一个排列 `p`，使题目中的目标表达式最优。

---

## 关键观察

把目标式整理后，每个位置 `i` 的权重只和它前面的前缀和有关。

令：

\[
pre_i = a_1 + a_2 + \cdots + a_i
\]

位置 `i` 对应的关键值是 `pre_{i-1}`。

要让整体最优，就应该：

- `pre_{i-1}` 越小的位置，放越大的排列值；
- `pre_{i-1}` 越大的位置，放越小的排列值。

所以直接按 `pre_{i-1}` 排序即可。

---

## 思路步骤

1. 从左到右计算每个位置前面的前缀和 `preBefore`。
2. 存 `(preBefore, i)`。
3. 按 `preBefore` 从小到大排序。
4. 排在越前的位置分配越大的数。

---

## 易错点

- 用的是 `pre_{i-1}`，不是 `pre_i`。
- 前缀和可能很大，要用 `long long`。
- 前缀和相等时顺序任意。

---

## 复杂度

`O(n log n)`。

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
        vector<long long> a(n);
        for (auto &x : a) cin >> x;

        vector<pair<long long, int>> order;
        long long pref = 0;
        for (int i = 0; i < n; ++i) {
            order.push_back({pref, i});
            pref += a[i];
        }

        sort(order.begin(), order.end());

        vector<int> p(n);
        for (int rank = 0; rank < n; ++rank) {
            p[order[rank].second] = n - rank;
        }

        for (int i = 0; i < n; ++i) {
            cout << p[i] << " \n"[i + 1 == n];
        }
    }
    return 0;
}
```

---

## 一句话总结

目标式化简后只看每个位置前面的前缀和：前缀越小，分配的排列值越大。
