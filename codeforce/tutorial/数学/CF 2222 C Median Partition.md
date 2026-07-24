# CF 2222 C - Median Partition

**题目链接**：<https://codeforces.com/problemset/problem/2222/C>

**对应题单**：Codeforces Round 1094 C

**题型**：数学 / DP / 中位数

**难度**：1500（青）

---

## 题意压缩

把数组划分成若干段，要求每段长度为奇数，并且每段的中位数都等于原数组的中位数。求最多能划分成多少段。

---

## 关键观察

设全数组中位数为 `mid`。

对某一段：

- 小于 `mid` 的数记为 `-1`；
- 大于 `mid` 的数记为 `+1`；
- 等于 `mid` 的数记为 `0`。

设这一段里：

- `eq` = 等于 `mid` 的个数；
- `sum` = `+1/-1` 的和。

这段的中位数等于 `mid`，当且仅当：

\[
eq > 0 \quad \text{且} \quad |sum| < eq
\]

因为等于 `mid` 的数必须能够压住两边数量差。

---

## 思路步骤

1. 排序求出全数组中位数 `mid`。
2. 做前缀：
   - `prefSum[i]`：前 `i` 个元素的 `+1/-1` 和；
   - `prefEq[i]`：前 `i` 个元素中等于 `mid` 的个数。
3. DP：`dp[i]` 表示前 `i` 个数最多能分成多少合法段。
4. 枚举上一段起点 `j`，若 `[j,i)` 长度为奇数且合法，则更新 `dp[i]`。

---

## 易错点

- 每段长度必须是奇数。
- 段内必须至少有一个 `mid`。
- 判定条件是 `abs(sum) < eq`，不是 `<=`。

---

## 复杂度

`O(n^2)`。

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
        vector<int> a(n), srt;
        for (int &x : a) cin >> x;
        srt = a;
        sort(srt.begin(), srt.end());
        int mid = srt[n / 2];

        vector<int> prefSum(n + 1), prefEq(n + 1);
        for (int i = 0; i < n; ++i) {
            prefSum[i + 1] = prefSum[i] + (a[i] > mid) - (a[i] < mid);
            prefEq[i + 1] = prefEq[i] + (a[i] == mid);
        }

        const int NEG = -1e9;
        vector<int> dp(n + 1, NEG);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if ((i - j) % 2 == 0 || dp[j] < 0) continue;
                int sum = prefSum[i] - prefSum[j];
                int eq = prefEq[i] - prefEq[j];
                if (eq > 0 && abs(sum) < eq) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        cout << dp[n] << '\n';
    }
    return 0;
}
```

---

## 一句话总结

把元素按和全局中位数的关系压成 `-1/0/+1`，合法段就是 `0` 的数量严格压过两边差值。
