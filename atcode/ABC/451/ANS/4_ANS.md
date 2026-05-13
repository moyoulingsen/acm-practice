# 英文原题解（Markdown格式）
## D - Concat Power of 2 Editorial by en_translator
Sample Input / Output 3 implies that the 1099898-th smallest good integer is $819264512 \approx 0.8 \times 10^9$, so we can infer that there are not so many good integers below $10^9$. Therefore, we may enumerate all good integers and sort them to retrieve the $N$-th element among them.

Since $10^9$ is not a good integer, it suffices to enumerate good integers with 9 digits or less. Let $X_k$ be the set of good integers with exactly $k$ digits, and $P_k$ be the set of powers of two with exactly $k$ digits. For convenience, let $X_0 = \{0\}$. Then for all $k \ge 1$:

$$
X_k = \bigcup_{i=1}^{k} \left\{ x \cdot 10^i + p \mid x \in X_{k-i},\ p \in P_i \right\}.
$$

The good integers can be enumerated by appropriately implementing the equation above.

By actually enumerating, we find that there are 1257874 good integers up to $10^9$, which can be computed fast enough.

### Sample code (Python)
```python
P = [[] for _ in range(10)]
for k in range(1, 10):
    l = (10 ** (k - 1) - 1).bit_length()
    r = (10 ** k - 1).bit_length()
    P[k] = [1 << i for i in range(l, r)]
X = [set() for _ in range(10)]
X[0] = {0}
A = []
for k in range(1, 10):
    for i in range(1, k + 1):
        X[k] |= {x * (10 ** i) + p for x in X[k - i] for p in P[i]}
    A += list(X[k])
A.sort()
N = int(input())
print(A[N - 1])
```

### Estimation of the number
We describe how we can estimate the number of good integers.

We will evaluate the number of good integers with $k$ digits or less: $S_k = |X_1| + \cdots + |X_k|$.

Since $|P_i| \le \lceil \log_2 10 \rceil = 4$, for $k \ge 1$ we have:

$$
\begin{align*}
S_k - S_{k-1} &= |X_k| \\
&= \left| \bigcup_{i=1}^{k} \left\{ x \cdot 10^i + p \mid x \in X_{k-i},\ p \in P_i \right\} \right| \\
&\le \sum_{i=1}^{k} \left| \left\{ x \cdot 10^i + p \mid x \in X_{k-i},\ p \in P_i \right\} \right| \\
&= \sum_{i=1}^{k} |X_{k-i}| \cdot |P_i| \\
&\le 4(|X_{k-1}| + \cdots + |X_1| + |X_0|) = 4(S_{k-1} + 1).
\end{align*}
$$

With this inequality,

$$
S_k + 1 \le 5(S_{k-1} + 1) \le \cdots \le 5^k (S_0 + 1) = 5^k,
$$

implying that there are at most $5^k - 1$ good integers with $k$ digits or less. Since $5^9 - 1 = 1953124$ and this is a rough estimation, we can guess that enumerating all of them will finish within the time limit.

---

# 中文翻译（Markdown格式）
## D - 拼接 2 的幂 题解 by en_translator
从样例输入/输出 3 可以看出，第 1099898 小的好数是 $819264512 \approx 0.8 \times 10^9$，由此可以推断：$10^9$ 以内的好数数量并不多。因此，我们可以**枚举所有好数并排序**，直接取出第 $N$ 小的数即可。

由于 $10^9$ 本身不是好数，我们只需要枚举**位数不超过 9 位**的好数即可。
设 $X_k$ 表示**恰好 $k$ 位**的好数集合，$P_k$ 表示**恰好 $k$ 位**的 2 的幂集合。为方便计算，令 $X_0 = \{0\}$。那么对于所有 $k \ge 1$，有如下公式：

$$
X_k = \bigcup_{i=1}^{k} \left\{ x \cdot 10^i + p \mid x \in X_{k-i},\ p \in P_i \right\}.
$$

合理实现上述公式，即可枚举所有好数。

实际枚举后可以发现，$10^9$ 以内共有 1257874 个好数，计算速度完全满足要求。

### 示例代码（Python）
```python
P = [[] for _ in range(10)]
for k in range(1, 10):
    l = (10 ** (k - 1) - 1).bit_length()
    r = (10 ** k - 1).bit_length()
    P[k] = [1 << i for i in range(l, r)]
X = [set() for _ in range(10)]
X[0] = {0}
A = []
for k in range(1, 10):
    for i in range(1, k + 1):
        X[k] |= {x * (10 ** i) + p for x in X[k - i] for p in P[i]}
    A += list(X[k])
A.sort()
N = int(input())
print(A[N - 1])
```

### 数量估算
我们来讲解如何估算好数的数量。

定义 $S_k$ 为**位数不超过 $k$ 位**的好数总数：$S_k = |X_1| + \cdots + |X_k|$。

已知 $|P_i| \le \lceil \log_2 10 \rceil = 4$，对于 $k \ge 1$，有以下推导：

$$
\begin{align*}
S_k - S_{k-1} &= |X_k| \\
&= \left| \bigcup_{i=1}^{k} \left\{ x \cdot 10^i + p \mid x \in X_{k-i},\ p \in P_i \right\} \right| \\
&\le \sum_{i=1}^{k} \left| \left\{ x \cdot 10^i + p \mid x \in X_{k-i},\ p \in P_i \right\} \right| \\
&= \sum_{i=1}^{k} |X_{k-i}| \cdot |P_i| \\
&\le 4(|X_{k-1}| + \cdots + |X_1| + |X_0|) = 4(S_{k-1} + 1).
\end{align*}
$$

根据这个不等式，可以推出：

$$
S_k + 1 \le 5(S_{k-1} + 1) \le \cdots \le 5^k (S_0 + 1) = 5^k,
$$

这意味着**位数不超过 $k$ 位**的好数最多有 $5^k - 1$ 个。
由于 $5^9 - 1 = 1953124$，这只是一个粗略估算，由此可以确定：枚举所有好数的操作能在时间限制内完成。