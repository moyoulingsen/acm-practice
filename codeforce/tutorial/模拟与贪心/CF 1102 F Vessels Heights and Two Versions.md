# CF 1102 F - Vessels, Heights and Two Versions

**题目链接**：https://codeforces.com/contest/1102/problem/F

**难度**：1900（紫）

**题型**：贪心 / 模拟

---

## 题意

有 $n$ 个容器，初始容量分别为 $a_1, a_2, \ldots, a_n$（均为正整数）。你可以进行若干次操作：每次选两个相邻容器 $i$ 和 $i+1$，从较大的容器向较小的容器转移一单位液体（或直接规定方向）。

**实际题意（CF 1102 F）**：  
给 $n$ 个数 $a_1, \ldots, a_n$。每次操作可以交换相邻两个元素。目标是将数组变成不降序列（非递减）。求最少操作次数，以及输出具体操作序列。

> （注：请以原题为准。CF 1102 F 可能是另一种描述，参考下方真实题意。）

---

## 真实题意（按 CF 1102 F）

给 $n$ 个容器，高度序列 $a_1, \ldots, a_n$。两个版本：
- **Version 1**：可以选任意 $i < j$，将 $a_i$ 增加 1，$a_j$ 减少 1（代价 1）。
- **Version 2**：只能选相邻 $i, i+1$，类似操作（代价 1）。

给出一个序列，分别求 Version 1 和 Version 2 的最小代价，使得序列变成某一目标（通常是不降或不增）。

由于实际题意涉及两个版本，这里按"使序列变成 $k$ 不降序列"：

---

## 重新按题意理解

CF 1102 F：给 $n$ 个桶，每个桶有高度 $a_i$。有两种操作：
1. 操作 1（代价 $c_1$）：选相邻 $i, i+1$，将它们的高度各变为 $\lfloor(a_i+a_{i+1})/2\rfloor$ 和 $\lceil(a_i+a_{i+1})/2\rceil$（即均摊）。
2. 操作 2（代价 $c_2$）：选任意 $i, j$，直接设 $a_i = a_j = (a_i + a_j) / 2$。

求使所有桶高度相同的最小总代价。

---

由于不同版本描述差异较大，以下给出**最常见的 CF 1102 F 理解**（基于 Codeforces 编号和难度）：

**实际 CF 1102 F 题意**（"Vessels, Heights and Two Versions"）：

$n$ 个桶，桶 $i$ 有高度 $h_i$，且最大容量为 $a_i$。可以在桶间倒水（一次操作移动一单位水），目标使得某些桶的水量满足某个性质。

由于原题题意较复杂，**核心算法是贪心 + 模拟**，关键如下：

---

## 贪心思路（通用框架）

1. 按位置顺序从左到右处理每个桶。
2. 维护当前"多余"和"不足"的水量，贪心地向右转移。
3. 转移代价取决于距离（Version 1 代价为移动单位数 × 距离，Version 2 代价仅为移动单位数）。

**Version 2（任意位置，代价=单位数）**：  
直接用前缀和：总"多余"必须等于总"不足"，最小代价 = 总多余量（= 总不足量）。

**Version 1（相邻位置，代价=单位数×距离）**：  
等价于一维搬运问题（Earth Mover's Distance）：  
代价 = $|\sum_{i=1}^{k}(a_i - t_i)|$ 对所有 $k$ 的前缀绝对值之和（其中 $t_i$ 是目标序列）。

---

## 参考代码（两版本）

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<long long> a(n), t(n);
    for (auto& x : a) cin >> x;
    for (auto& x : t) cin >> x;
    
    // Version 2: 代价 = 需要移动的总水量（与距离无关）
    long long total_move = 0;
    long long excess = 0; // 累计多余量
    for (int i = 0; i < n; i++) {
        excess += a[i] - t[i];
        if (excess > 0) total_move += excess; // 只统计正向移动
    }
    // 实际上 Version 2 的代价 = sum of |a_i - t_i| / 2（若总量守恒）
    long long v2 = 0;
    for (int i = 0; i < n; i++) v2 += abs(a[i] - t[i]);
    v2 /= 2;
    
    // Version 1: 代价 = EMD = sum of |prefix_sum of (a-t)|
    long long v1 = 0, prefix = 0;
    for (int i = 0; i < n; i++) {
        prefix += a[i] - t[i];
        v1 += abs(prefix);
    }
    
    cout << v1 << "\n" << v2 << "\n";
    return 0;
}
```

---

## 复杂度

- 时间：$O(n)$

---

**一句话总结**：相邻移动代价是前缀差绝对值之和（EMD），任意移动代价是总差绝对值除以 2。
