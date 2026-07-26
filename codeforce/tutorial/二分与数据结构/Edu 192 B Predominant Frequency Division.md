# Edu 192 B - Predominant Frequency Division

**题目链接**：<https://codeforces.com/problemset/problem/2242/B>

**题型**：前缀和 / 贪心

**难度**：1000

---

## 题意压缩

给一个只含 `1,2,3` 的数组，问能否分成三个非空连续段，使前两段满足题目要求的频率条件。

---

## 关键观察

把条件转成前缀差值：

- 左段需要 `1` 的数量不少于非 `1` 的数量，用 `+1/-1` 统计；
- 中段需要 `1/2` 的数量不少于 `3` 的数量，也用 `+1/-1` 统计。

枚举中段右端 `j` 时，需要在它左边找一个合法左段右端 `i`，使中段差值也合法。

维护所有合法 `i` 的最小第二种前缀值即可。

---

## 思路步骤

1. 预处理两个前缀：
   - `prefLeft`：`1` 记 `+1`，其他记 `-1`；
   - `prefMid`：`1/2` 记 `+1`，`3` 记 `-1`。
2. 从左到右枚举中段右端。
3. 维护之前所有满足左段条件的位置中，最小的 `prefMid`。
4. 若 `prefMid[j] - best >= 0`，说明可行。

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

        vector<int> a(n);
        for (int &x : a) cin >> x;

        vector<int> prefLeft(n + 1), prefMid(n + 1);
        for (int i = 0; i < n; ++i) {
            prefLeft[i + 1] = prefLeft[i] + (a[i] == 1 ? 1 : -1);
            prefMid[i + 1] = prefMid[i] + (a[i] == 3 ? -1 : 1);
        }

        const int INF = 1e9;
        int best = INF;
        bool ok = false;

        for (int j = 1; j < n; ++j) {
            if (best != INF && prefMid[j] - best >= 0) {
                ok = true;
                break;
            }

            if (prefLeft[j] >= 0) {
                best = min(best, prefMid[j]);
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}
```

---

## 一句话总结

把两个段条件都写成前缀差值，枚举右端时维护可用左端的最优前缀。
