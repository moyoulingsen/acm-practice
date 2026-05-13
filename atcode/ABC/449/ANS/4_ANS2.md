# D - Make Target 2 题解（iastm 版）
---

## 英文原文
Consider a subproblem where $L=D=0$ (and $R,U≥0$). We want to count the number of black lattice points $(x,y)$ for which $0≤x≤R$ and $0≤y≤U$.

We assume $R≤U$ without loss of generality. The case $R>U$ can be treated similarly by symmetry.

Furthermore, we divide the subproblem into two cases: $0≤y≤R$ and $R<y≤U$.

For $0≤y≤R$, a lattice point $(x,y)$ is black if $\max(x,y)$ is even.

For an even number $k$ where $0≤k≤R$, lattice points with $\max(x,y)=k$ satisfy either $x=k$ or $y=k$.

If $x=k$, then $y$ can take $k+1$ possible values from $0$ to $k$, so there are $k+1$ lattice points.
Similarly, there are $k+1$ lattice points if $y=k$.
Subtracting the overlap at $(k,k)$ gives a total of $2k+1$.

Let $p$ be the greatest even number at most $R$. The number of black lattice points is the sum of the number of points corresponding to $k∈\{0,2,…,p\}$.

Since there are $\frac{p}{2} +1$ possible values of $k$, the total number of black lattice points can be written as the arithmetic series:
$$
\begin{align*}
&(2⋅0+1)+(2⋅2+1)+⋯+(2⋅p+1) \\
=& \frac{\left(\frac{p}{2} +1\right)(2p+2)}{2} \\
=&\left(\frac{p}{2} +1\right)(p+1).
\end{align*}
$$

For $R<y≤U$, since $0≤x≤R<y$, the color of a lattice point depends only on the parity of $y=\max(x,y)$.

Since there are $R+1$ lattice points for each value of $y$, the number of black lattice points is $q(R+1)$ where $q$ is the number of even numbers in the interval $(R,U]$.

Thus, we obtain a formula for the number of black lattice points in the subproblem where $L=D=0$.

We can reduce the original problem to the above subproblem via symmetry and the inclusion-exclusion principle. The time complexity is $O(1)$.

### An example reduction method
Let $f(L,R,D,U)$ be the number of black lattice points satisfying $L≤x≤R$ and $D≤y≤U$. We use $f$ to describe the computation steps below.

If $U<0$, reflect the $y$-coordinates to obtain $f(L,R,D,U)=f(L,R,−U,−D)$. After this step, we assume $U≥0$.
Similarly, if $R<0$, reflect the $x$-coordinates to obtain $f(L,R,D,U)=f(−R,−L,D,U)$. After this step, we assume $R≥0$.

Shift the lower bound of $y$ from $D$ to $0$:
If $D=0$, nothing changes, so $f(L,R,D,U)=f(L,R,0,U)$.
If $D>0$, subtract the black points in the interval $[0,D−1]$ to obtain $f(L,R,D,U)=f(L,R,0,U)−f(L,R,0,D−1)$.
If $D<0$, reflect the interval $[D,−1]$ to obtain $f(L,R,D,U)=f(L,R,0,U)+f(L,R,0,−D)−f(L,R,0,0)$.

Similarly, shift the lower bound of $x$ from $L$ to $0$:
If $L=0$, nothing changes, so $f(L,R,0,U)=f(0,R,0,U)$.
If $L>0$, subtract the black points in the interval $[0,L−1]$ to obtain $f(L,R,0,U)=f(0,R,0,U)−f(0,L−1,0,U)$.
If $L<0$, reflect the interval $[L,−1]$ to obtain $f(L,R,0,U)=f(0,R,0,U)+f(0,−L,0,U)−f(0,0,0,U)$.

After reduction, compute $f(0,R,0,U)$ using the formula described above.

---

## 中文翻译
我们先求解一个**子问题**：当 $L=D=0$（且 $R,U≥0$）时，统计满足 $0≤x≤R$、$0≤y≤U$ 的黑色格点 $(x,y)$ 的数量。

不失一般性，假设 $R≤U$；若 $R>U$，可通过**对称性**用相同方法处理。

我们将子问题拆分为两个区间计算：$0≤y≤R$ 和 $R<y≤U$。

---
### 情况1：$0≤y≤R$
格点 $(x,y)$ 为黑色的条件是 $\max(x,y)$ 为偶数。
对于 $0≤k≤R$ 的**偶数 $k$**，满足 $\max(x,y)=k$ 的格点分为两类：$x=k$ 或 $y=k$。
- 若 $x=k$，$y$ 可取 $0\sim k$ 共 $k+1$ 个值；
- 若 $y=k$，$x$ 可取 $0\sim k$ 共 $k+1$ 个值；
- 减去重复的点 $(k,k)$，总数量为 $2k+1$。

设 $p$ 为**不超过 $R$ 的最大偶数**，黑色点总数为所有偶数 $k$ 对应点数的和，这是一个等差数列：
$$
(2⋅0+1)+(2⋅2+1)+\dots+(2⋅p+1) = \left(\frac{p}{2}+1\right)(p+1)
$$

---
### 情况2：$R<y≤U$
此时 $0≤x≤R<y$，因此 $\max(x,y)=y$，格点颜色仅由 $y$ 的**奇偶性**决定。
每个 $y$ 对应 $R+1$ 个格点，设区间 $(R,U]$ 内偶数的个数为 $q$，则该区间黑色点数量为 $q \cdot (R+1)$。

综上，我们得到了子问题 $L=D=0$ 的黑色点计数公式。

---
### 原问题转化（对称性 + 容斥原理）
通过**坐标对称**和**容斥原理**，可以将任意范围的原问题转化为上述子问题，**时间复杂度为 $O(1)$**。

定义函数 $f(L,R,D,U)$ 表示满足 $L≤x≤R$ 且 $D≤y≤U$ 的黑色点数量，转化步骤如下：
1. **处理负坐标**
   - 若 $U<0$：对 $y$ 坐标翻转，$f(L,R,D,U)=f(L,R,-U,-D)$；
   - 若 $R<0$：对 $x$ 坐标翻转，$f(L,R,D,U)=f(-R,-L,D,U)$。

2. **将 $y$ 下界平移至 0**
   - $D=0$：无需修改，$f(L,R,D,U)=f(L,R,0,U)$；
   - $D>0$：减去 $[0,D-1]$ 区间的黑点，$f(L,R,D,U)=f(L,R,0,U)-f(L,R,0,D-1)$；
   - $D<0$：翻转 $[D,-1]$ 区间，$f(L,R,D,U)=f(L,R,0,U)+f(L,R,0,-D)-f(L,R,0,0)$。

3. **将 $x$ 下界平移至 0**
   - $L=0$：无需修改，$f(L,R,0,U)=f(0,R,0,U)$；
   - $L>0$：减去 $[0,L-1]$ 区间的黑点，$f(L,R,0,U)=f(0,R,0,U)-f(0,L-1,0,U)$；
   - $L<0$：翻转 $[L,-1]$ 区间，$f(L,R,0,U)=f(0,R,0,U)+f(0,-L,0,U)-f(0,0,0,U)$。

最终，所有问题都转化为子问题 $f(0,R,0,U)$，代入公式计算即可。