# E - Fibonacci String 题解（官方英文翻译版）
原作者：toam

---

## 英文原文
This problem can be solved with a recursive function.

For a string $T$, let $|T|$ denote its length.

For $i\ge2$, $S_i$ is a prefix of $S_{i+1}$. Thus, we can take the minimum $K$ with $|S_K|\ge\max R_i$ and inspect $S_K$ instead of $S_{10^{18}}$. Since $|S_i|$ is at least the $i$-th Fibonacci number, $K=O(\log\max R_i)$. (Particularly, in our problem $K=88$.)

The number of occurrences within the $L$-th through $R$-th characters is the number of occurrences within the first $R$ characters, subtracted by that within the first $(L-1)$. Therefore, the original problem can be answered by solving the following question twice: “how many occurrences are there within the first $N$ characters?” We will now tackle this problem.

Let $f_c(k,n)$ be the number of occurrences of character $c$ among the first $n$ characters of $S_k$. For $k\ge3$, $S_k$ is a concatenation of $S_{k-1}$ and $S_{k-2}$ in this order, so depending on $n\le|S_{k-1}|$ we obtain:

$$
f_c(k,n)=
\begin{cases}
\text{#(}c\text{ in the first }n\text{ characters of }X) & \text{if } k=1 \\
\text{#(}c\text{ in the first }n\text{ characters of }Y) & \text{if } k=2 \\
f_c(k-1,n) & \text{if } k\ge3 \text{ and } n\le|S_{k-1}| \\
\text{#(}c\text{ in }S_{k-1}\text{)}+f_c(k-2,n-|S_{k-1}|) & \text{if } k\ge3 \text{ and } n>|S_{k-1}|.
\end{cases}
$$

(The notation #($c$…) reads “the number of occurrences of character $c$….”) Therefore, we may precalculate
$|S_1|,\dots,|S_K|$,
#($c$ in the first $i$ characters of $X$),
#($c$ in the first $i$ characters of $Y$),
#($c$ in $S_K$)
and memorize them for $O(1)$ retrieval, the recursive relations allow us to compute $f_c(K,n)$ in $O(K)$ time.

Hence, the problem has been solved in a total of $O(\sigma(|X|+|Y|+\log\max R_i)+Q\log\max R_i)$ time including the precalculation, where $\sigma$ is the size of the alphabet.

---

## 中文翻译
这道题可以通过**递归函数**解决。

对于字符串 $T$，用 $|T|$ 表示它的长度。

对于 $i\ge2$，$S_i$ 是 $S_{i+1}$ 的**前缀**。因此我们只需要找到满足 $|S_K| \ge \max R_i$ 的最小下标 $K$，直接用 $S_K$ 代替 $S_{10^{18}}$ 计算即可。
由于 $|S_i|$ 至少等于第 $i$ 个斐波那契数，$K$ 的量级为 $O(\log\max R_i)$（在本题中，$K$ 具体为 **88**）。

---

区间 $[L,R]$ 内的字符出现次数 = 前 $R$ 个字符的出现次数 - 前 $L-1$ 个字符的出现次数。
因此原问题可以转化为：**求解字符串前 $N$ 个字符中目标字符的出现次数**，对每个询问计算两次该值即可得到答案。

---

### 核心递归定义
设 $f_c(k,n)$ 表示：字符串 $S_k$ 的**前 $n$ 个字符**中，字符 $c$ 的出现次数。
对于 $k\ge3$，$S_k = S_{k-1} + S_{k-2}$（拼接），由此得到递归公式：

$$
f_c(k,n)=
\begin{cases}
X \text{ 前 }n\text{ 个字符中 }c\text{ 的数量} & k=1 \\
Y \text{ 前 }n\text{ 个字符中 }c\text{ 的数量} & k=2 \\
f_c(k-1,n) & k\ge3 \text{ 且 } n \le |S_{k-1}| \\
S_{k-1}\text{ 中 }c\text{ 的总数量} + f_c(k-2,\ n-|S_{k-1}|) & k\ge3 \text{ 且 } n > |S_{k-1}|
\end{cases}
$$

---

### 预处理与复杂度
我们可以提前预处理以下内容，实现 $O(1)$ 查询：
1. $S_1 \sim S_K$ 的长度；
2. $X$、$Y$ 的字符前缀计数数组；
3. 每个 $S_k$ 中所有字符的总数量。

通过记忆化预处理，递归计算 $f_c(K,n)$ 的时间复杂度为 $O(K)$。

最终，包含预处理在内的总时间复杂度为：
$$O(\sigma(|X|+|Y|+\log\max R_i)+Q\log\max R_i)$$
其中 $\sigma$ 为字母表大小（本题中 $\sigma=26$）。