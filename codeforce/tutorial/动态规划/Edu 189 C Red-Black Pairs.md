# Edu 189 C - Red-Black Pairs

**题目链接**：<https://codeforces.com/problemset/problem/2225/C>

**题型**：动态规划 / 网格配对

**难度**：1100

---

## 题意压缩

给一个 `2 × n` 的红黑网格，需要把所有格子划分成相邻的二格对，并最小化需要重涂的格子数，使每一对同色。

---

## 关键观察

合法划分只有两种局部形态：

1. 某一列上下两个格子竖着配；
2. 相邻两列中，上面两个横着配，下面两个横着配。

因此可以做一维 DP。

设 `dp[i]` 表示处理完前 `i` 列的最小代价：

- 竖着配第 `i` 列，代价是上下颜色是否不同；
- 横着配第 `i,i+1` 两列，代价是两行各自相邻颜色是否不同。

---

## 思路步骤

1. 初始化 `dp[0]=0`。
2. 从左到右转移：
   - `dp[i+1]` 用竖配更新；
   - `dp[i+2]` 用两列横配更新。
3. 输出 `dp[n]`。

---

## 复杂度

`O(n)`。

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
        int n;
        cin >> n;

        string top, bottom;
        cin >> top >> bottom;

        const int INF = 1e9;
        vector<int> dp(n + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < n; ++i) {
            dp[i + 1] = min(dp[i + 1], dp[i] + (top[i] != bottom[i]));

            if (i + 1 < n) {
                int cost = (top[i] != top[i + 1]) + (bottom[i] != bottom[i + 1]);
                dp[i + 2] = min(dp[i + 2], dp[i] + cost);
            }
        }

        cout << dp[n] << '\n';
    }

    return 0;
}
```

---

## 一句话总结

`2 × n` 铺二格对，只需要在“竖一列”和“横两列”之间做线性 DP。
