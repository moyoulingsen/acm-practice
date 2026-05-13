# 英文原题解（Markdown格式）
## E - Tree Distance Editorial by en_translator
Let $A_{i,j} = A_{j,i}$ to define the distance for $i>j$ too. Notice that by the constraints all edge weights are positive.

Consider actually constructing a conforming tree $T$. Due to the properties that a tree must satisfy, $T$ can be uniquely determined if it exists, and can be constructed by the following steps.

Regard vertex $1$ as the root. Consider how we can identify, for each vertex $i$ ($i \neq 1$), its parent $p_i$ and the edge weight between the parent $w_{i,p_i}$:

For any vertex $i$, a vertex $j$ is eligible as an ancestor of $i$ if and only if $A_{1,j} + A_{j,i} = A_{1,i}$. Let $S_i$ be the set of vertices $j$ ($j \neq i$) satisfying this condition.

Among the vertices in this set $S_i$, only those satisfying
$$p_i = \mathop{\arg\min}_{j \in S_i} A_{i,j}$$
is eligible as a parent of $i$. The edge toward it has a weight $w_{i,p_i} = A_{i,p_i}$.

If $S_i$ is empty, there is no parent, so $T$ cannot be constructed, and the answer is No. The answer is also No when there are multiple candidates of $p_i$ (in which case we may just adopt an arbitrary tie-breaking, so that inconsistency is detected on the final verification).

By the steps above, one can obtain a candidate of tree $T$ in $O(N^2)$ time.

Finally, verify if the constructed tree actually satisfies the conditions. Perform a DFS (Depth-First Search) to check if the distances between all vertex pairs perfectly match with $A$. The overall time complexity is $O(N^2)$.

posted: 2 months ago
last update: 2 months ago

---

# 中文翻译（Markdown格式）
## E - 树的距离 题解 by en_translator
我们补充定义 $A_{i,j} = A_{j,i}$，使得 $i>j$ 时距离也有定义。注意题目约束保证了所有边权均为正数。

我们尝试直接构造一棵符合要求的树 $T$。根据树的固有性质，若合法的树存在，则它是唯一确定的，可通过以下步骤构造：

将**节点 1** 作为根节点。对于每个节点 $i$（$i \neq 1$），我们需要确定它的父节点 $p_i$，以及父节点与它之间的边权 $w_{i,p_i}$：

对于任意节点 $i$，节点 $j$ 能成为 $i$ 的祖先节点，当且仅当满足等式：$A_{1,j} + A_{j,i} = A_{1,i}$。
我们将满足该条件的所有节点 $j$（$j \neq i$）组成的集合记作 $S_i$。

在集合 $S_i$ 的所有节点中，**满足下式的节点 $j$** 才可以作为 $i$ 的父节点：
$$p_i = \mathop{\arg\min}_{j \in S_i} A_{i,j}$$
连接父节点的边权为：$w_{i,p_i} = A_{i,p_i}$。

若集合 $S_i$ 为空，说明节点 $i$ 没有合法父节点，无法构造出树 $T$，答案为 `No`。
若父节点 $p_i$ 存在多个候选值，答案也为 `No`（这种情况下我们可以任意选择一个候选值，最终的验证步骤会检测出矛盾）。

通过上述步骤，我们可以在 $O(N^2)$ 的时间内得到一棵候选树 $T$。

最后，**验证构造出的树是否满足题目条件**：通过深度优先搜索（DFS）计算所有节点对之间的距离，检查是否与给定的矩阵 $A$ 完全一致。
算法的总时间复杂度为 $O(N^2)$。

发布时间：2 个月前
最后更新：2 个月前

