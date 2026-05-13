# 英文原题解（Markdown）
## E - LRUD Moving Editorial by en_translator
First, paint the grid in the checkerboard pattern: specifically, paint cell $(i,j)$ black if $i+j$ is even, and white if odd. Then the color of the cell where the piece is located always changes with every move.

Let us consider the necessary and sufficient condition for the answer being **Yes**.

### [1] If $N$ is odd
Cells $(1,1)$ and $(N,N)$ are both painted black, so the $(N^2-3)$ cells the piece visits must have colors white → black → white → … → white, but this is impossible because $N^2-3$ is even. Thus, the answer is **No**.

### [2] If $N$ is even
By the same discussion as [1], the $(N^2-3)$ cells on the way must be white → black → white → … → white. If $(A+B)$ is even, there will be more black cells than white cells, so the answer is **No**.

Therefore, the answer is **Yes** only if:
1. $N$ is even;
2. $A+B$ is odd.

In fact, this is a necessary and sufficient condition.

Given $N,A,B$ satisfying these conditions, let us construct a valid LRUD move string.

The original problem considers an $N\times N$ grid, but we generalize it into an $H\times W$ grid.

We will solve the problem recursively.

If $A>2$, we can begin the tour with `RR...RDLL...LD` so that the remaining problem is reduced to the case $(H,W,A,B) \leftarrow (H-2,W,A-2,B)$.
Also, if $H-A+1>2$, we can end the tour with `RR...RDLL...LD` to reduce it to $(H,W,A,B) \leftarrow (H-2,W,A,B)$.
By repeating these reductions, we can boil down the problem to the case $H=2$.

The same discussion applies to the $W$ axis, so that the problem is reduced to $(H,W)=(2,2)$.
In this case, $(A,B)$ is either $(1,2)$ or $(2,1)$, and both cases can be solved directly.

The problem can be solved by appropriately implementing this algorithm. The time complexity is $O(N^2)$ per test case.

In the following code, the recursive reduction is implemented as loops, where the prefixes and suffixes are maintained individually.

## Sample code (Python 3)
```python
for _ in range(int(input())):
    n, a, b = map(int, input().split())
    a, b = a - 1, b - 1
    if n % 2 == 1 or (a + b) % 2 == 0:
        print("No")
        continue
    s1 = []
    s2 = []
    for _ in range(n // 2 - 1):
        s = "R" * (n - 1) + "D" + "L" * (n - 1) + "D"
        if a >= 2:
            s1.append(s)
            a -= 2
        else:
            s2.append(s[::-1])
    for _ in range(n // 2 - 1):
        s = "DRUR"
        if b >= 2:
            s1.append(s)
            b -= 2
        else:
            s2.append(s[::-1])
    assert (a, b) in ((0, 1), (1, 0))
    if (a, b) == (0, 1):
        s1.append("DR")
    else:
        s1.append("RD")
    ans = "".join(s1) + "".join(s2[::-1])
    print("Yes")
    print(ans)
```

---

# 中文翻译（Markdown）
## E - LRUD 移动 题解 by en_translator
首先将网格按**国际象棋棋盘黑白相间**染色：规定格子 $(i,j)$ 若满足 $i+j$ 为偶数则染黑色，为奇数则染白色。棋子每移动一步，所在格子的颜色必然发生改变。

我们来推导答案为 **Yes** 的充要条件。

### 情况1：$N$ 为奇数
起点 $(1,1)$ 和终点 $(N,N)$ 都为黑色。
中途需要经过 $N^2-3$ 个格子，颜色序列必须是 白→黑→白→…→白，但 $N^2-3$ 是偶数，无法满足该交替规律。
因此答案一定是 **No**。

### 情况2：$N$ 为偶数
沿用上面的推导，中途经过的 $N^2-3$ 个格子同样要求颜色按 白→黑→白→…→白 交替。
若 $A+B$ 为偶数，则黑色格子数量多于白色格子，无法走通，答案为 **No**。

综上，答案为 **Yes** 的充要条件：
1. $N$ 是偶数；
2. $A+B$ 是奇数。

事实上这两个条件既是必要条件也是充分条件。

对于满足上述条件的 $N,A,B$，我们可以构造出合法的移动序列 LRUD。

原题是 $N\times N$ 方阵，我们先推广到 $H\times W$ 矩形网格来分析。

采用**递归缩规模**的思路解题：

若 $A>2$，可以先用一段 `RR...RDLL...LD` 的路径遍历上方区域，将原问题规模缩减为 $(H-2,W,A-2,B)$。
若 $H-A+1>2$，可以在路径末尾拼接 `RR...RDLL...LD`，将问题缩减为 $(H-2,W,A,B)$。

反复缩行规模，最终可以把问题化简到**行数 $H=2$** 的情形。

对列方向 $W$ 做完全相同的缩规模操作，最终问题会化简为 $2\times2$ 的网格。
此时障碍格 $(A,B)$ 只能是 $(1,2)$ 或 $(2,1)$，这两种情况都可以直接构造出答案。

直接实现该构造算法即可解题，每组测试用例时间复杂度 $O(N^2)$。

下方代码没有用递归，而是用循环模拟缩规模过程，分别维护路径的前缀和后缀部分。

## 示例代码（Python 3）
```python
for _ in range(int(input())):
    n, a, b = map(int, input().split())
    a, b = a - 1, b - 1
    if n % 2 == 1 or (a + b) % 2 == 0:
        print("No")
        continue
    s1 = []
    s2 = []
    for _ in range(n // 2 - 1):
        s = "R" * (n - 1) + "D" + "L" * (n - 1) + "D"
        if a >= 2:
            s1.append(s)
            a -= 2
        else:
            s2.append(s[::-1])
    for _ in range(n // 2 - 1):
        s = "DRUR"
        if b >= 2:
            s1.append(s)
            b -= 2
        else:
            s2.append(s[::-1])
    assert (a, b) in ((0, 1), (1, 0))
    if (a, b) == (0, 1):
        s1.append("DR")
    else:
        s1.append("RD")
    ans = "".join(s1) + "".join(s2[::-1])
    print("Yes")
    print(ans)
```