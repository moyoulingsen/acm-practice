# CF 1098 D - Sanae, Cross and Strings

**题目链接**：https://codeforces.com/contest/1098/problem/D

**难度**：1900（紫）

**题型**：数学 / 字符串 / XOR

---

## 题意

给一个长度为 $n$ 的 01 字符串 $s$。定义子串 $[l, r]$ 是"好的"，当且仅当 $s[l] = s[r] = 0$（前后端点都是 0），或 $s[l] = s[r] = 1$。

求"好的"子串个数（$l < r$）。

---

## 关键观察

"好的"条件：$s[l] = s[r]$。

设 $c_0$ 为 0 的个数，$c_1$ 为 1 的个数。

所有满足 $s[l] = s[r]$ 的对数 = $\binom{c_0}{2} + \binom{c_1}{2}$（任意两个相同字符的位置对）。

但是题目要求子串（连续区间），**不是任意两个位置**，且 $l < r$ 要求连续吗？

重新读题：子串 $[l, r]$ 即下标 $l \le r$，$s[l..r]$ 是连续子串。"好的"条件仅关注端点 $s[l]$ 和 $s[r]$。

所以答案 = 满足 $l < r$ 且 $s[l] = s[r]$ 的 $(l, r)$ 对数。

= $\binom{c_0}{2} + \binom{c_1}{2}$

其中 $c_0$ = 字符串中 0 的个数，$c_1$ = 1 的个数（$c_0 + c_1 = n$）。

---

## 思路

1. 统计 $c_0$（0 的数量），$c_1 = n - c_0$。
2. 答案 = $c_0(c_0-1)/2 + c_1(c_1-1)/2$。

---

## 易错点

- 注意 $l < r$（严格小于），所以是组合数 $\binom{c}{2}$ 不包含 $l=r$。
- 数据范围 $n$ 可达 $2 \times 10^5$，答案用 `long long`。

---

## 复杂度

- 时间：$O(n)$

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    string s;
    cin >> n >> s;
    
    long long c0 = count(s.begin(), s.end(), '0');
    long long c1 = n - c0;
    
    cout << c0 * (c0 - 1) / 2 + c1 * (c1 - 1) / 2 << "\n";
    return 0;
}
```

---

**一句话总结**：好子串当且仅当两端字符相同，分别统计 0 和 1 的数量再算组合数即可。
