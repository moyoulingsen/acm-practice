# CF 1103 D - Brand New Tatar TV Show

**真实题号**：CF 2236 D

**题目链接**：<https://codeforces.com/problemset/problem/2236/D>

**题型**：贪心 / 博弈 / 排序

**难度体感**：1300，关键是从最大值开始分析。

---

## 题意压缩

给定一个 multiset 和参数 `k`。

两个人轮流操作，能从某个数移动到不超过 `k` 距离内的更大数，问先手是否能赢。

---

## 关键观察

把相同值压成 `(value, count)`。

从最大值开始看，因为最大值没有更大的数可以继续跳。

对于当前最大值 `mx`：

### 1. `mx` 出现次数是偶数

先手可以让局面落到对自己有利的配对状态，答案是 `YES`。

### 2. `mx` 是唯一剩下的值，且次数是奇数

没有更小值能跳上来补，答案是 `NO`。

### 3. 次大值和最大值距离不超过 `k`

可以从次大值跳到最大值，答案是 `YES`。

### 4. 否则

最大值这一组和下面断开，且奇数个最大值无法被下面影响。

把这一组删掉，继续分析新的最大值。

---

## 为什么可以从最大值往下剥

最大值没有出边，只能作为终点。

如果下面的值跳不到它，那么它和下面的游戏互不影响。

这时当前最大值组如果无法决定胜负，就可以剥掉，继续看下面的最大组。

---

## 思路步骤

1. 排序数组。
2. 压缩成 `(值, 出现次数)`。
3. 从后往前模拟剥最大值组：
   - 偶数次，`YES`；
   - 没有下一组，`NO`；
   - 与下一组差值 `<=k`，`YES`；
   - 否则丢掉当前组继续。

---

## 复杂度

排序主导：

\[
O(n\log n)
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
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int &x : a) cin >> x;

        sort(a.begin(), a.end());

        vector<pair<int, int>> groups;
        for (int x : a) {
            if (!groups.empty() && groups.back().first == x) {
                groups.back().second++;
            } else {
                groups.push_back({x, 1});
            }
        }

        bool ok = false;
        while (!groups.empty()) {
            int mx = groups.back().first;
            int cnt = groups.back().second;

            if (cnt % 2 == 0) {
                ok = true;
                break;
            }

            groups.pop_back();
            if (groups.empty()) {
                ok = false;
                break;
            }

            if (mx - groups.back().first <= k) {
                ok = true;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}
```

---

## 一句话总结

这题就是：**从最大值组往下剥，偶数个最大值或能从下一组跳上来就赢。**
