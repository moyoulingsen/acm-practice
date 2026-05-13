# C - Comfortable Distance 题解（官方英文翻译版）
---

## 英文原文
Consider computing the count for each fixed $j$. It suffices to count the number of $i$ with $j−R≤i≤j−L$ and $S_i = S_j$ . This can be computed by precalculating the cumulative sums of the frequencies of each English letter. Specifically, let $A_{c,k}$ be the number of occurrences of the English character $c$ among the $1,2,…,k$-th characters, then the answer for each $j$ is $A_{S_j,\max(j−L,0)} − A_{S_j,\max(j−R−1,0)}$.

The solution above runs in $O(σN)$, where $σ$ denotes the distinct number of letters. However, this can be solved in $O(σ+N)$ time as well. Maintain the frequency array of $S_i$ within $j−R≤i≤j−L$, and perform a differential update for $j=1,2,...,N$ incrementally. When $j$ increases by $1$, there are $O(1)$ elements that need to be updated. Therefore, the computation can be done by maintaining and updating the entire frequency array. See also the sample code below.

### Sample code (differential updates)
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	int n, l, r;
	cin >> n >> l >> r;
	r++;
	string s;
	cin >> s;
	ll ans = 0;
	vector<int> cnt(26);
	for (int i = 0; i < n; i++) {
		if (i >= l) cnt[s[i - l] - 'a']++;
		if (i >= r) cnt[s[i - r] - 'a']--;
		ans += cnt[s[i] - 'a'];
	}
	cout << ans << '\n';
}
```

---

## 中文翻译
我们可以**固定右端点 $j$** 来计算合法数对的数量：只需要统计满足 $j-R \le i \le j-L$ 且 $S_i = S_j$ 的下标 $i$ 的个数即可。

### 方法一：前缀和法
我们可以预处理每个英文字母的**出现次数前缀和数组**来计算。
具体来说，定义 $A_{c,k}$ 表示字符串前 $k$ 个字符中，字符 $c$ 出现的总次数。
那么对于每个 $j$，合法的 $i$ 的数量为：
$$A_{S_j,\ \max(j-L,\ 0)} - A_{S_j,\ \max(j-R-1,\ 0)}$$

这个解法的时间复杂度为 $O(σN)$，其中 $σ$ 表示不同字符的种类数（本题中 $σ=26$）。

### 方法二：滑动窗口/差分更新法（最优解）
我们可以将复杂度优化到 **$O(σ+N)$**：
维护一个频率数组，实时记录区间 $[j-R,\ j-L]$ 内所有字符的出现次数；然后从左到右遍历每个 $j$，对频率数组进行**增量式差分更新**。
当 $j$ 增加 $1$ 时，仅需修改 $O(1)$ 个元素即可更新频率数组，最终累加答案。

### 示例代码说明
代码采用了**滑动窗口差分更新**的最优思路：
1. 将 $R$ 自增 $1$，简化区间边界的判断；
2. 用长度为 $26$ 的数组 `cnt` 维护窗口内字符的频率；
3. 遍历每个位置 $i$（对应原题的 $j$），动态维护窗口的左右边界，累加合法字符的数量。