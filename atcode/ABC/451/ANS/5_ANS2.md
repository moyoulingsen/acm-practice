# 英文原题解（Markdown格式）
## E - Tree Distance Editorial by en_translator
### Supplement to Official Editorial and Alternative Solution
To get straight to the point, it is sufficient to take a minimum spanning tree of the weighted complete graph with edge weights $w_{i,j} = A_{i,j}$, and check if it satisfies the condition in the problem statement.

### Proof
Let $T$ be such a minimum spanning tree. Suppose that there is a different but valid tree $U$.

Then this tree $U$ should contain (distinct) edges $(u,v)$ and $(x,y)$ such that adding edge $(u,v)$ to, and removing edge $(x,y)$ from $U$ makes the total weight not greater. Then $A_{u,v} \le A_{x,y}$.

Also, the graph obtained by adding edge $(u,v)$ to tree $U$ has exactly one cycle, and vertices $u,v,x,y$ must be contained in this cycle (although some of the variables may refer to the same vertex). Since the path on a tree is unique, the $u-v$ path on tree $U$ must contain edge $(x,y)$, so $A_{u,v} > A_{x,y}$.

This is a contradiction.

Hence, no tree other than $T$ is eligible for an answer, so it is sufficient to verify this tree.

In most languages, you should be able to solve the problem using an algorithm to find a minimum spanning tree in $O(N^2)$ time; moreover, $O(N^2 \log N)$ algorithms will probably be accepted too. (If it leads to TLE, try to use bucket sort instead, to reduce the complexity to $O(N^2 + \text{max}A)$.)

The verification can be done in the same way as described in the official editorial.

---

# 中文翻译（Markdown格式）
## E - 树的距离 题解 by en_translator
### 官方题解补充 & 替代解法
开门见山地说：我们只需要以 $w_{i,j}=A_{i,j}$ 为边权，构造**完全图的最小生成树（MST）**，再验证这棵树是否满足题目要求即可。

### 证明
设 $T$ 是上述完全图的最小生成树。假设存在另一棵合法的树 $U$。

那么树 $U$ 中必然存在两条不同的边 $(u,v)$ 和 $(x,y)$，满足：将边 $(u,v)$ 加入 $U$、并删除边 $(x,y)$ 后，树的总权值不增。此时可得 $A_{u,v} \le A_{x,y}$。

同时，在树 $U$ 中加入边 $(u,v)$ 后会形成**恰好一个环**，且节点 $u,v,x,y$ 都在这个环上（部分节点可能重合）。由于树的路径唯一，树 $U$ 中 $u$ 到 $v$ 的路径必然经过边 $(x,y)$，因此可得 $A_{u,v} > A_{x,y}$。

这就产生了**矛盾**。

因此，除了最小生成树 $T$ 之外，不存在其他合法的树。我们只需要验证这棵树即可。

在绝大多数编程语言中，使用 $O(N^2)$ 的最小生成树算法即可解决本题；$O(N^2 \log N)$ 的算法也大概率能通过。（若出现超时，可使用桶排序优化，将复杂度降至 $O(N^2 + \text{max}A)$。）

验证步骤与官方题解中描述的方法一致。