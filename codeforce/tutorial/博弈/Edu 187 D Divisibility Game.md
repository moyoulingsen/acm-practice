# Edu 187 D - Divisibility Game

**题目链接**：<https://codeforces.com/problemset/problem/2203/D>

**题型**：博弈 / 数论 / 约数统计

**难度**：1700

---

## 题意压缩

有两组数 `a` 和 `b`。对每个 `b[j]`，根据有多少个 `a[i]` 能整除它，把它分成不同类型，然后两人最优博弈，判断胜者。

---

## 关键观察

对每个 `b[j]`，设：

\[
cnt = \#\{i \mid a_i \mid b_j\}
\]

它只会有三种类型：

- `cnt = n`：所有 `a` 都能整除它，偏向 Alice；
- `cnt = 0`：没有 `a` 能整除它，偏向 Bob；
- `0 < cnt < n`：双方都可以争。

记三类数量为 `A, B, C`。

中间类相当于双方轮流拿：

- 若 `C` 为偶数，Alice 需要 `A > B`；
- 若 `C` 为奇数，Alice 需要 `A >= B`。

---

## 思路步骤

1. 统计每个值在 `a` 中出现次数。
2. 用类似约数筛的方法，求每个 `x` 被多少个 `a[i]` 整除。
3. 遍历 `b` 的出现次数，分类累加 `A, B, C`。
4. 按 `C` 的奇偶判断胜者。

---

## 复杂度

若值域为 `V`，复杂度为：

\[
O(V \log V)
\]

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
        int n, m;
        cin >> n >> m;

        int lim = n + m;
        vector<int> cntA(lim + 1), cntB(lim + 1), divCnt(lim + 1);

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            ++cntA[x];
        }

        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            ++cntB[x];
        }

        for (int d = 1; d <= lim; ++d) {
            if (!cntA[d]) continue;
            for (int x = d; x <= lim; x += d) {
                divCnt[x] += cntA[d];
            }
        }

        long long aliceOnly = 0, bobOnly = 0, either = 0;

        for (int x = 1; x <= lim; ++x) {
            if (!cntB[x]) continue;

            if (divCnt[x] == n) aliceOnly += cntB[x];
            else if (divCnt[x] == 0) bobOnly += cntB[x];
            else either += cntB[x];
        }

        bool aliceWins;
        if (either % 2 == 0) aliceWins = aliceOnly > bobOnly;
        else aliceWins = aliceOnly >= bobOnly;

        cout << (aliceWins ? "Alice" : "Bob") << '\n';
    }

    return 0;
}
```

---

## 一句话总结

先按“能被多少个 `a` 整除”把每个 `b` 分类，中间类只影响先手多拿一次还是不多拿。
