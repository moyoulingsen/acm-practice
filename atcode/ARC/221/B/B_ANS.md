# B - Two-Powered Sum 官方题解整理

- 题目链接：https://atcoder.jp/contests/arc221/tasks/arc221_b
- 官方题解 1：https://atcoder.jp/contests/arc221/editorial/21042
- 官方题解 2：https://atcoder.jp/contests/arc221/editorial/21043
- 作者：evima

## 先做等价转化

因为对一个集合 `S` 做操作时：

\[
x=\sum_{i\in S}2^{i-1}
\]

这个二进制表示唯一对应于集合 `S`。

所以可以把序列 `A` 改写成一个“集合序列” `B`：

- `B_i = ∅` 表示位置 `i` 仍为 `0`；
- 如果 `A_i = x`，则 `B_i` 就是 `x` 对应的集合。

于是操作变成：

> 选一个集合 `S ⊆ {1,2,...,N}`，并对所有 `i ∈ S` 令 `B_i = S`。

问题就变成：有多少种最终集合序列 `B` 能被构造出来。

---

# 题解一：逆过程 + DP

先只考虑所有 `B_i ≠ ∅` 的情况。

## 1. 逆过程判定

维护已经“删除”的下标集合 `I`，初始为空。

反向做操作时，寻找某个集合 `S`，满足：

- 对每个 `i ∈ S`，要么 `B_i = S`，要么 `i` 已经在 `I` 中；
- 且 `S` 中至少有一个元素还没被删除。

然后把这些元素加入 `I`。

如果最后能得到 `I = {1,2,...,N}``，则这个 `B` 可以被构造出来。

## 2. 为了计数，让逆过程唯一化

官方把一次操作扩展成：

- 在当前状态下，把所有满足条件的集合 `S_1, S_2, ...` 一次性找出；
- 统一加入 `I`。

这样逆过程分层后就唯一了。

设：

- `I_j`：第 `j` 次逆操作后已删除的集合；
- `C_j = I_j \setminus I_{j-1}`：这一层新加入的元素。

然后讨论在 `I_{j-1}` 和 `C_j` 固定时，这一层有多少种构造方法。

## 3. DP 定义

定义：

- `dp'[x][y]`：在固定 `x` 个下标最终非空的前提下，经过若干次逆操作，达到 `|I|=x` 且最近新增层大小为 `y` 的方案数。

### 初始层

如果第一次就删掉 `a` 个元素，那么这些元素需要被划分成若干非空块，因此：

\[
dp'[a][a] = \sum_{b=1}^{a} \left\{ {a \atop b} \right\}
\]

这里 `\left\{ {a \atop b} \right\}`` 是第二类 Stirling 数。

### 转移

当前已有：

- `|I| = x`
- 最近一层大小 `y`

下一层加入 `a` 个元素。

若把这 `a` 个元素分成 `b` 块，则贡献为：

1. 选这 `a` 个新元素：
   \[
   \binom{x+a}{a}
   \]
2. 把它们分成 `b` 个非空块：
   \[
   \left\{ {a \atop b} \right\}
   \]
3. 每个块对应的原集合 `S_k` 的可选方式：
   \[
   (2^x - 2^{x-y})^b
   \]

于是：

\[
dp'[x+a][a] \leftarrow \binom{x+a}{a}
\sum_{b=1}^{a}
\left\{ {a \atop b} \right\}
(2^x-2^{x-y})^b
 dp'[x][y]
\]

为了优化，官方预处理：

\[
coef[x][b] = \sum_{y=1}^{x} dp'[x][y](2^x - 2^{x-y})^b
\]

这样总复杂度可以做到 `O(N^3)`。

## 4. 补上允许空集的位置

若最终恰好有 `i` 个位置非空：

- 先从 `N` 个位置中选出这 `i` 个：`\binom{N}{i}`
- 再乘上这 `i` 个位置内部的构造数 `\sum_y dp'[i][y]`

最后还要加上“所有位置都为空”的 1 种方案。

因此答案为：

\[
1 + \sum_{i=1}^{N} \binom{N}{i} \sum_y dp'[i][y]
\]

---

# 题解二：容斥 + 递推

这版思路更偏组合。

仍然只先考虑所有 `B_i ≠ ∅` 的情况，设方案数为 `C_n`。

在整个操作过程中，存在一个偏序关系：

- 如果某个集合 `S_1` 必须先于 `S_2` 被操作，那么它们之间就有依赖；
- 这些依赖构成一个 DAG。

官方不直接枚举 DAG，而是对“入度为 0 的那些集合”做容斥。

## 容斥思路

选定一批入度为 0 的集合：

- 集合个数为 `a`
- 这些集合覆盖的总元素数为 `s`

则：

1. 把 `s` 个元素划分成 `a` 个非空集合的方法数是：
   \[
   \left\{ {s \atop a} \right\}
   \]
2. 每个集合必须包含自己那部分元素；
3. 不能包含其他被选中的入度 0 集合中的元素；
4. 但可以任意包含剩余 `n-s` 个元素。

因此这部分的选择数为：

\[
2^{a(n-s)}
\]

剩下的 `n-s` 个元素又形成同类子问题。

所以得到递推：

\[
C_n=
\sum_{s=1}^{n}\binom{n}{s}C_{n-s}
\sum_{a=1}^{s}(-1)^{a+1}
\left\{ {s \atop a} \right\}2^{a(n-s)}
\]

这个式子也能在 `O(N^3)` 内计算。

---

## 官方代码（题解二）

```python
N, mod = map(int, input().split())

S = [[0] * (N + 1) for i in range(N + 1)]
binom = [[0] * (N + 1) for i in range(N + 1)]
for n in range(N + 1):
    S[n][n] = 1
    binom[n][0] = 1
    if n != 0:
        S[n][1] = 1
    for k in range(2, n):
        S[n][k] = (S[n - 1][k - 1] + k * S[n - 1][k]) % mod
    for k in range(1, n + 1):
        binom[n][k] = (binom[n - 1][k - 1] + binom[n - 1][k]) % mod

pow2 = [1] * (N * N + 1)
for i in range(1, N * N + 1):
    pow2[i] = pow2[i - 1] * 2 % mod

C = [0] * (N + 1)
C[0] = 1
ans = 1
for n in range(1, N + 1):
    for s in range(1, n + 1):
        tmp = 0
        sgn = 1
        for a in range(1, s + 1):
            tmp += sgn * S[s][a] * pow2[a * (n - s)]
            tmp %= mod
            sgn = -sgn
        C[n] += binom[n][s] * C[n - s] % mod * tmp
        C[n] %= mod
    ans += binom[N][n] * C[n]
    ans %= mod

print(ans)
```
