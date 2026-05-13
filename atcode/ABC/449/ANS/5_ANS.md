# E - A += v 题解（官方英文翻译版）
---

## 英文原文
Consider appending elements with the same frequency at once; then the operations can be described as follows:

Let $(P_1,P_2,\dots,P_M)$ be the sequence obtained by stable sorting $(1,2,\dots,M)$ by the frequencies in $A$. Let $V_i$ be the number of occurrences of $P_i$ in $A$.

For $k=1,2,\dots,M$ in order, do the following:
Perform the following operation $(V_{k+1} − V_k)$ times: append the sequence obtained by sorting $(P_1,P_2,\dots,P_k)$ in ascending order. Here, define $V_{M+1}=\infty$.

After the operation for $k=k_0$ ends, the length of $A$ can be represented as $N+\sum_{i=1}^{k_0} k(V_{k+1}−V_k)$. Thus, given $A_X$, the value $k$ when the element was appended, and the position in $(P_1,P_2,\dots,P_k)$ sorted in ascending order, can be found by binary searching.

Also, given $(k,v)$, off-line queries asking the $v$-th smallest element among $(P_1,P_2,\dots,P_k)$ can be answered fast using a Fenwick tree.

The problem can be solved by appropriately implementing the algorithm above.

### Sample code (Python 3)
```python
import sys
input = sys.stdin.readline
class BIT:
    def __init__(self, n: int):
        self.a = [0] * (n + 1)
    def add(self, i: int, x: int) -> None:
        i += 1
        while i < len(self.a):
            self.a[i] += x
            i += i & -i
    def sum(self, *args) -> int:
        if len(args) == 1:
            r = args[0]
            s = 0
            while r:
                s += self.a[r]
                r -= r & -i
            return s
        else:
            l, r = args
            return self.sum(r) - self.sum(l)
    # minimize i s.t. sum(i) >= w
    def lower_bound(self, w: int) -> int:
        x = 0
        n = len(self.a) - 1
        k = 1 << (n.bit_length() - 1)
        while k:
            if x + k <= n and self.a[x + k] < w:
                w -= self.a[x + k]
                x += k
            k >>= 1
        return x + 1
n, m = map(int, input().split())
a = [int(x) - 1 for x in input().split()]
c = [0] * m
for v in a:
    c[v] += 1
s = [(c[i], i) for i in range(m)]
s.sort()
r = [0] * (m + 1)
r[0] = n
for i in range(m - 1):
    r[i + 1] = (i + 1) * (s[i + 1][0] - s[i][0]) + r[i]
r[m] = 10**18 + 2026
q = int(input())
ans = [-1] * q
que = []
for i in range(q):
    x = int(input())
    if x <= n:
        ans[i] = a[x - 1]
        continue
    ng, ok = 0, m
    while ok - ng != 1:
        vs = (ok + ng) >> 1
        if r[vs] >= x:
            ok = vs
        else:
            ng = vs
    x -= r[ng] + 1
    x %= ok
    que.append((ok, x, i))
que.sort()
fw = BIT(m)
idx = 0
for ok, x, i in que:
    while idx < ok:
        fw.add(s[idx][1], 1)
        idx += 1
    ans[i] = fw.lower_bound(x + 1) - 1
for v in ans:
    print(v + 1)
```

---

## 中文翻译
我们可以**批量追加频率相同的元素**，将操作流程简化为如下步骤：

设将数字 $1,2,\dots,M$ 按照它们在序列 $A$ 中的**出现频率进行稳定排序**，得到序列 $(P_1,P_2,\dots,P_M)$；记 $V_i$ 为数字 $P_i$ 在 $A$ 中的出现次数。

按顺序对 $k=1,2,\dots,M$ 执行以下操作：
重复执行 $(V_{k+1} - V_k)$ 次操作：将**升序排序后的 $(P_1,P_2,\dots,P_k)$** 追加到序列 $A$ 末尾。
（规定 $V_{M+1}=\infty$）

当 $k=k_0$ 对应的所有操作执行完毕后，序列 $A$ 的总长度为：
$$N+\sum_{i=1}^{k_0} k(V_{k+1}−V_k)$$

因此，对于查询的位置 $A_X$，我们可以通过**二分查找**快速确定：该元素是在哪个 $k$ 阶段被追加的，以及它在排序后的 $(P_1,P_2,\dots,P_k)$ 中的位置。

此外，对于形如「求 $(P_1,P_2,\dots,P_k)$ 中第 $v$ 小的元素」的**离线查询**，可以使用**树状数组（Fenwick Tree）** 高效求解。

正确实现上述算法即可解决本题。

---

### 代码核心说明
1. **统计频率+排序**：统计每个数字的出现次数，按频率稳定排序得到候选序列；
2. **预处理长度数组**：计算每个 $k$ 阶段结束后序列的总长度，用于二分定位查询位置；
3. **二分定位**：对每个查询 $X$，二分找到其所属的阶段 $k$，并计算在循环段中的偏移量；
4. **离线处理+树状数组**：将所有查询按 $k$ 排序，用树状数组动态维护数字集合，快速查询第 $k$ 小元素。