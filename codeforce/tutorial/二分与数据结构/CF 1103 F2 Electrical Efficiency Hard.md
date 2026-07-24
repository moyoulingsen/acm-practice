# CF 1103 F2 - Electrical Efficiency Hard

**题目链接**：<https://codeforces.com/problemset/problem/1103/F2>

**题型**：数据结构 / 优化 DP / 数学贡献

**难度体感**：超出“稳定紫名”一些，但作为 F1 的升级版很适合纳入复盘体系。

---

## 这题的学习重点

F2 的重点不是新想法，而是：

- **同一个核心式子，怎么从 F1 的较慢做法优化到可过大数据。**

因此刷这题的价值主要在于训练：

- 识别瓶颈；
- 找到可以被维护的数据；
- 用更强结构把枚举缩掉。

---

## 常见升级路线

F1 -> F2 常见升级方式：

- 朴素枚举改成前缀最值；
- 暴力合并改成线段树 / 树状数组；
- 全局重算改成局部维护；
- 二重循环改成按贡献排序或离线处理。

所以复盘时要重点问：

> F1 到底慢在哪一层？那一层能不能被维护？

---

## 参考代码

下面给一份“线段树维护区间最优值”的 F2 风格参考框架：

```cpp
#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<long long> tree;
    SegTree(int n = 0) : n(n), tree(4 * n + 4, 0) {}

    void update(int idx, int l, int r, int pos, long long val) {
        if (l == r) {
            tree[idx] = max(tree[idx], val);
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid) update(idx << 1, l, mid, pos, val);
        else update(idx << 1 | 1, mid + 1, r, pos, val);
        tree[idx] = max(tree[idx << 1], tree[idx << 1 | 1]);
    }

    long long query(int idx, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return tree[idx];
        int mid = (l + r) >> 1;
        long long res = -(1LL << 60);
        if (ql <= mid) res = max(res, query(idx << 1, l, mid, ql, qr));
        if (qr > mid) res = max(res, query(idx << 1 | 1, mid + 1, r, ql, qr));
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    SegTree seg(n);
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        long long best = seg.query(1, 1, n, 1, i);
        ans = max(ans, best + a[i]);
        seg.update(1, 1, n, i, a[i]);
    }

    cout << ans << '\n';
    return 0;
}
```

> 这份代码是“F1 核心不变，F2 用数据结构提速”的典型模板。你之后精修原题时，建议把它替换成完全贴题的状态维护。

---

## 适合写在 tutorial 里的点

如果以后你把这题完整补掉，建议教程里一定单独写：

1. F1 核心思路；
2. F2 比 F1 多了什么数据范围；
3. 朴素瓶颈在哪里；
4. 优化后的维护结构是什么；
5. 复杂度怎么降下来的。

---

## 一句话总结

F2 的本质是：**在不改变核心思路的前提下，把 F1 的瓶颈那一层优化掉。**
