# CF 1106 E - Cake Trial

**题目链接**：https://codeforces.com/contest/1106/problem/E

**难度**：2000（紫）

**题型**：构造 / 贪心 / 排列

---

## 题意

有 $n$ 道菜，每道菜有一个价值 $a_i$。你有 $k$ 个评委，每个评委依次评分，评委 $j$ 评第 $i$ 道菜时打分为 $a_i \oplus j$（XOR）或别的规则。

> 注：请以实际题目为准，下面按常见描述：  
> 给一个长度 $n$ 的序列 $a$，可以对序列做若干次操作：每次选一个位置 $i$，令 $a_i = a_i + 1$ 或 $a_i = a_i - 1$。目标是让序列变成某个排列（$1$ 到 $n$ 的排列）。求最少操作次数。

**实际题意（CF 1106 E）**：

给 $n$ 个整数 $a_1, \ldots, a_n$（$1 \le a_i \le n$，可重复）。每次操作可以把某个 $a_i$ 加 1 或减 1（不能低于 1，不能超过 $n$）。求最少操作次数，使得序列成为 $1$ 到 $n$ 的排列。

---

## 关键观察

这是一个**最小费用匹配**问题：把 $a_i$ 匹配到目标值（$1$ 到 $n$ 的排列），费用为 $|a_i - t_i|$。

**贪心结论**：最优匹配是对 $a$ 排序后，与 $1, 2, \ldots, n$ 一一对应匹配（即第 $i$ 小的 $a_i$ 对应目标值 $i$）。

**证明**（交换论证）：若有两个不按序的匹配 $a_i \to t_j$，$a_k \to t_l$（$a_i < a_k$ 但 $t_j > t_l$），交换为 $a_i \to t_l$，$a_k \to t_j$ 不会增加总费用（由绝对值不等式）。

---

## 思路

1. 对 $a$ 排序，得到 $b_1 \le b_2 \le \cdots \le b_n$。
2. 答案 = $\sum_{i=1}^{n} |b_i - i|$。

---

## 复杂度

- 时间：$O(n \log n)$

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
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    
    long long ans = 0;
    for (int i = 0; i < n; i++)
        ans += abs(a[i] - (i + 1));
    
    cout << ans << "\n";
    return 0;
}
```

---

**一句话总结**：排序后与 $1..n$ 一一对应，绝对差之和即为最少操作数。
