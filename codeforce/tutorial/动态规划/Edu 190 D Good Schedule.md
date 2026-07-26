# Edu 190 D - Good Schedule

**题目链接**：<https://codeforces.com/problemset/problem/2230/D>

**题型**：动态规划 / 贪心 / 后缀维护

**难度**：1700

---

## 题意压缩

给定两个人的节目观看顺序，统计满足题目条件的区间数量。

---

## 关键观察

从某个左端点 `i` 出发，只需要知道最早在哪个右端点开始不合法。设这个位置为 `bad`，那么以 `i` 为左端点的合法区间数就是：

\[
bad-i
\]

从右往左扫描，可以维护：

- `pa[x]`：当前位置右侧，Alice 中节目 `x` 的下一次出现；
- `pb[x]`：当前位置右侧，Bob 中节目 `x` 的下一次出现；
- `dp[pos]`：如果某个节目在两人同一天匹配，继续往后匹配时最早失败的位置。

若节目 `1` 在两边下一次出现位置不同，失败点就是较早的那个；若相同，就沿着 `dp` 继续判断节目 `2,3,...`。

---

## 思路步骤

1. 把节目编号转成 `0` 开始。
2. 从右往左维护 `pa,pb`。
3. 如果当前位置两个人节目相同，更新对应 `dp`。
4. 对每个左端点 `i`，根据节目 `0` 的下一次出现情况累加合法区间数量。

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

        vector<int> a(n), b(n);
        for (int &x : a) {
            cin >> x;
            --x;
        }
        for (int &x : b) {
            cin >> x;
            --x;
        }

        vector<int> pa(n + 1, n), pb(n + 1, n), dp(n + 1, n);
        long long ans = 0;

        for (int i = n - 1; i >= 0; --i) {
            pa[a[i]] = i;
            pb[b[i]] = i;

            if (a[i] == b[i]) {
                int nextEpisode = a[i] + 1;
                if (pa[nextEpisode] == pb[nextEpisode]) {
                    dp[i] = dp[pa[nextEpisode]];
                } else {
                    dp[i] = min(pa[nextEpisode], pb[nextEpisode]);
                }
            }

            if (pa[0] != pb[0]) {
                ans += min(pa[0], pb[0]) - i;
            } else {
                ans += dp[pa[0]] - i;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
```

---

## 一句话总结

从右往左维护每个节目下一次出现，用最早失败右端点一次性贡献所有合法区间。
