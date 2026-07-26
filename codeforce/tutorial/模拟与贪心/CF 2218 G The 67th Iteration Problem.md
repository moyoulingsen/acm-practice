# CF 2218 G - The 67th Iteration Problem

**题目链接**：<https://codeforces.com/problemset/problem/2218/G>

**对应题单**：CF 1090 Div.4 G

**题型**：计数 / 模拟 / 分类讨论

**难度**：1800

---

## 题意压缩

给定每个人实际坐下的时间 `b_i`，问有多少个初始数组 `a` 能产生这个过程。答案对 `676767677` 取模。

---

## 关键观察

对于某个位置 `i`，设它坐下时间为 `t=b_i`。

如果 `t=0`，那么它的 `a_i` 必须为 `0`，贡献为 `1`。

如果 `t>0`，它要在时间 `t` 坐下，必须至少有一个相邻位置在它之前坐下。令相邻位置中最早坐下时间为 `mn`：

- 如果 `mn >= t`，说明没有邻居提前坐下，无解；
- 如果 `mn = t-1`，它刚好被上一轮激活，`a_i` 可以取 `1..S(t)`，其中 `S(t)` 是时间 `<t` 已坐下人数；
- 如果 `mn <= t-2`，为了不更早坐下，它的阈值必须落在上一轮新增人数对应的区间，贡献是 `cnt[t-1]`。

每个位置的选择相互独立，最后把贡献相乘即可。

---

## 思路步骤

1. 统计每个时间的人数 `cnt[t]`。
2. 计算前缀 `pref[t] = # {i | b_i < t}`。
3. 遍历每个位置：
   - `t=0` 跳过；
   - 取左右邻居中最小的坐下时间 `mn`；
   - 按上述三种情况乘贡献或判无解。
4. 输出答案。

---

## 易错点

- 没有邻居时可以把 `mn` 当成无穷大；
- `mn == t-1` 时贡献是 `pref[t]`；
- `mn <= t-2` 时贡献是 `cnt[t-1]`；
- 模数是 `676767677`。

---

## 复杂度

`O(n+m)`。

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 676767677LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<int> b(n), cnt(m);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            ++cnt[b[i]];
        }

        vector<long long> pref(m + 1);
        for (int t = 0; t < m; ++t) {
            pref[t + 1] = pref[t] + cnt[t];
        }

        long long ans = 1;
        for (int i = 0; i < n; ++i) {
            int t = b[i];
            if (t == 0) continue;

            int mn = INT_MAX;
            if (i > 0) mn = min(mn, b[i - 1]);
            if (i + 1 < n) mn = min(mn, b[i + 1]);

            if (mn >= t) {
                ans = 0;
                break;
            }

            if (mn == t - 1) {
                ans = ans * pref[t] % MOD;
            } else {
                ans = ans * cnt[t - 1] % MOD;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
```

---

## 一句话总结

每个 `b_i=t` 的贡献只由左右邻居最早坐下时间和上一轮新增人数决定。
