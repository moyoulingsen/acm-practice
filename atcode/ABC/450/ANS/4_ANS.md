# D - Minimize Range 题解（官方英文翻译版）
原作者：vwxyz

---

## 英文原文
The remainder when dividing $A_i$ by $K$ is invariant by an operation.
Compare the following two sequences:
the sequence obtained by subtracting $K$ from $A_i$
the sequence obtained by adding $K$ to $A_j$ for all $j$ except for $i$
The relative positions of $A_i$ , and the maximum minus the minimum, are equal between them. Therefore, answer does not change if we allow an operation of choosing $i$ and subtracting $K$ from $A_i$ .
We can go further: we may replace $A_i$ with any integer as long as the remainder divided by $K$ is invariant.

Fix an $i$ such that the minimum value of $A$ is $A_i$ .
Since $\max(A)-\min(A)$ does not change by subtracting $K$ from $A_i$ for $i=1,2,\dots,N$, we may assume $0\le A_i <K$.
Then, we can perform operations to make $A_i \le A_j <A_i +K$ for all $j$ between $1$ and $N$ except for $i$. Such an $A_j$ is unique; this is either the remainder when dividing $A_j$ by $K$, or the remainder plus $K$.
By replacing $A_j$ with the value satisfying $A_i \le A_j <A_i +K$ computing $\max(A)-\min(A)$ for all $i$, the answer can be obtained.

On its own, it costs $O(N^2)$ time; however, the following optimization speeds it up to about $O(N)$:

Replace each element in $A$ with the remainder divided by $K$.
Sort $A$ in ascending order.
Using a deque, perform the following operation $N$ times: retrieve (and remove) the first element of $A$, add $K$ to it, and push the result to the end of $A$.
After each operation, compute $\max(A)-\min(A)$. Report the minimum value among them as the answer.
The first and last elements of $A$ correspond to the minimum and maximum values in a final $A$, respectively.

---

## 中文翻译
对数组元素执行题目规定的**加 $K$ 操作**后，**$A_i$ 除以 $K$ 的余数始终保持不变**。

对比以下两个序列：
1. 将 $A_i$ 减去 $K$ 得到的序列；
2. 对除 $i$ 以外的所有下标 $j$，将 $A_j$ 加上 $K$ 得到的序列。

两个序列中元素的相对大小、以及最大值与最小值的差值完全相等。因此，**新增「选择下标 $i$ 并将 $A_i$ 减去 $K$」的操作，不会改变最终答案**。

进一步结论：我们可以将 $A_i$ 替换为**任意除以 $K$ 余数相同的整数**，结果不受影响。

---

固定一个下标 $i$，使得 $A_i$ 为数组 $A$ 的最小值。
由于对所有元素反复减去 $K$ 不会改变 $\max(A)-\min(A)$，我们可以直接假设所有元素满足 $0\le A_i < K$。

此时，我们可以通过操作，让**除 $i$ 外的所有下标 $j$ 都满足 $A_i \le A_j < A_i+K$**。满足该条件的 $A_j$ 是唯一的：它要么是 $A_j$ 除以 $K$ 的余数，要么是余数加 $K$。

对每一个下标 $i$，将所有 $A_j$ 替换为满足 $A_i \le A_j < A_i+K$ 的值，计算 $\max(A)-\min(A)$，最终取所有结果的最小值即为答案。

---

暴力枚举的时间复杂度为 $O(N^2)$，会超时；通过以下优化可将复杂度降至**近似 $O(N)$**：
1. 将数组 $A$ 中每个元素替换为**自身除以 $K$ 的余数**；
2. 将数组**升序排序**；
3. 使用双端队列（deque）执行 $N$ 次操作：取出数组首元素，给它加上 $K$，再放回数组末尾；
4. 每次操作后计算当前数组的最大值减最小值，输出所有结果中的最小值。

优化后，数组的**第一个元素就是最小值，最后一个元素就是最大值**。