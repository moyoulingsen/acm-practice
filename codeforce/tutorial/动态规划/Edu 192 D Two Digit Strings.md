# Edu 192 D - Two Digit Strings

**题目链接**：<https://codeforces.com/problemset/problem/2242/D>

**题型**：字符串 DP / LCS / 前缀和

**难度**：1600

---

## 题意压缩

两个数字串可以不断把相邻两位合并成它们的和模 `10`。问两串最终能变成相同字符串的最大长度。

---

## 关键观察

把一个数字串划分成若干连续段，每段的数字和模 `10` 就是最终字符串中的一位。

也就是说，最终字符串对应的是一组分割边界。若前缀和模 `10` 序列为：

\[
p_0,p_1,\dots,p_n
\]

一段 `[l+1,r]` 的值是：

\[
(p_r-p_l) \bmod 10
\]

两个串想得到相同的分段值序列，本质上是在两个前缀和模 `10` 序列中找尽量长的公共边界序列。

所以答案是两个前缀和模 `10` 序列的 LCS 长度减 `1`。

如果两个串总和模 `10` 不同，则最终不可能相同。

---

## 思路步骤

1. 计算两个串的前缀和模 `10` 数组。
2. 如果最终总和模 `10` 不同，输出 `-1`。
3. 对两个前缀数组求 LCS。
4. 输出 `LCS - 1`。

---

## 复杂度

设两串长度为 `n,m`，复杂度为 `O(nm)`，空间可滚动到 `O(m)`。

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string a, b;
        cin >> a >> b;

        vector<int> pa(a.size() + 1), pb(b.size() + 1);

        for (int i = 0; i < (int)a.size(); ++i) {
            pa[i + 1] = (pa[i] + a[i] - '0') % 10;
        }
        for (int i = 0; i < (int)b.size(); ++i) {
            pb[i + 1] = (pb[i] + b[i] - '0') % 10;
        }

        if (pa.back() != pb.back()) {
            cout << -1 << '\n';
            continue;
        }

        int n = pa.size(), m = pb.size();
        vector<int> dp(m + 1), ndp(m + 1);

        for (int i = 1; i <= n; ++i) {
            ndp[0] = 0;
            for (int j = 1; j <= m; ++j) {
                ndp[j] = max(dp[j], ndp[j - 1]);
                if (pa[i - 1] == pb[j - 1]) {
                    ndp[j] = max(ndp[j], dp[j - 1] + 1);
                }
            }
            swap(dp, ndp);
        }

        cout << dp[m] - 1 << '\n';
    }

    return 0;
}
```

---

## 一句话总结

合并相邻数字等价于按段取和模 `10`，最大公共结果就是前缀模数组的 LCS 减一。
