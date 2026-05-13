# D - Make Target 2 题解（官方英文翻译版）
---

## 英文原文
To conveniently handle the expression $\max(|x|,|y|)$, we count those with $|x|>|y|$ and $|x|≤|y|$, and finally sum them up to find the answer.

Here, we will describe how to count those with $|x|>|y|$. Those with $|x|≤|y|$ can be counted likewise.

When $|x|>|y|$, $\max(|x|,|y|)=|x|$. Thus, we may iterate all even numbers $x$ within $L≤x≤R$, and for each $x$ find the number of $y$ with $|x|>|y|$ and $D≤y≤U$. Since $|x|>|y|$ is equivalent to $-|x|<y<|x|$, for a fixed $x$ the integers $y$ to be counted are within $\max(-|x|+1,D)≤y≤\min(|x|−1,U)$. The number of such $y$ can be represented as $\max(0,\min(|x|−1,U)−\max(-|x|+1,D)+1)$, which can be computed in $O(1)$ time for each $x$. Hence, those with $|x|>|y|$ can be counted in $O(X)$ time, where $X=R−L$.

### Sample code
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	int l, r, d, u;
	cin >> l >> r >> d >> u;
	ll ans = 0;
	// |x| > |y|
	for (int x = l; x <= r; x++) {
		if (x % 2 == 0) {
			int D = max(d, -abs(x) + 1);
			int U = min(u, abs(x) - 1);
			int C = U - D + 1;
			ans += max(C, 0);
		}
	}
	// |x| <= |y|
	for (int y = d; y <= u; y++) {
		if (y % 2 == 0) {
			int L = max(l, -abs(y));
			int R = min(r, abs(y));
			int C = R - L + 1;
			ans += max(C, 0);
		}
	}
	cout << ans << '\n';
}
```

---

## 中文翻译
为了方便处理 $\max(|x|,|y|)$ 这个表达式，我们将问题拆分为**$|x|>|y|$** 和 **$|x|≤|y|$** 两种情况分别统计，最后将两种情况的结果相加，即为最终答案。

下面详细说明 $|x|>|y|$ 的统计方法，$|x|≤|y|$ 的情况可以用完全相同的逻辑计算。

---
### 情况1：$|x|>|y|$
当 $|x|>|y|$ 时，$\max(|x|,|y|) = |x|$。
因此我们只需要遍历区间 $[L, R]$ 内**所有偶数 $x$**（黑色点要求 $\max$ 值为偶数），对每个 $x$ 统计满足以下条件的 $y$ 的数量：
1. $D ≤ y ≤ U$
2. $|x| > |y|$（等价于 $-|x| < y < |x|$）

对于固定的 $x$，合法的 $y$ 的取值区间为：
$$\max(-|x|+1,\ D) \le y \le \min(|x|-1,\ U)$$
该区间内的整数个数为：
$$\max\left(0,\ \min(|x|-1,U) - \max(-|x|+1,D) + 1\right)$$
每个 $x$ 都可以在 $O(1)$ 时间内计算出结果，因此统计 $|x|>|y|$ 的总时间复杂度为 $O(R-L)$。

---
### 情况2：$|x|≤|y|$
当 $|x|≤|y|$ 时，$\max(|x|,|y|) = |y|$。
遍历区间 $[D, U]$ 内**所有偶数 $y$**，统计满足 $D ≤ y ≤ U$ 且 $|x|≤|y|$ 的 $x$ 的数量即可，逻辑与情况1完全一致。

---
### 代码说明
1. 拆分统计：分别循环计算 $|x|>|y|$ 和 $|x|≤|y|$ 的黑色点数量；
2. 边界判断：对每个符合条件的偶数，计算坐标的合法区间，无效区间（长度为负）记为0；
3. 数据类型：使用 `long long` 避免数值溢出。