# CF 2229 C2 - We Be Flipping (Hard Version)

**题目链接**：<https://codeforces.com/problemset/problem/2229/C2>

**对应题单**：Codeforces Round 1100 C2

**题型**：贪心 / 前缀翻转 / 枚举

**难度**：1400（青）

---

## 题意压缩

Hard 版本要求让数组和尽量大，并输出一种操作方案。

---

## 关键观察

如果至少做了一次操作，设最后一次操作的最大下标为 `idx`。

最终效果可以理解为：

- `idx` 左边的数尽量变成正的；
- `idx` 自己会从正数变成负数，所以 `a[idx]` 必须原本为正才值得作为最后操作点；
- `idx` 右边不会受到影响，保持原样。

因此可以枚举最后的最大操作点 `idx`，计算最终和：

\[
\sum_{i<idx} |a_i| - a_{idx} + \sum_{i>idx} a_i
\]

再选择最优的 `idx`。

构造时：

1. 先用 Easy 版方法，把 `idx` 左边前缀全变成负数；
2. 最后操作 `idx`，把左边全部翻成正数，同时把 `idx` 翻成负数。

---

## 思路步骤

1. 计算原数组和，作为不操作的候选。
2. 枚举每个 `a[idx] > 0` 的位置，计算以它为最后操作点的最终和。
3. 如果最优值不超过原数组和，输出 `0` 次操作。
4. 否则对 `idx` 左边跑 Easy 版贪心，再追加一次 `idx` 操作。

---

## 易错点

- 最后操作点必须满足 `a[idx] > 0` 才可能变优。
- 构造时先只处理 `idx` 左边，最后再操作 `idx`。
- 如果不操作已经最优，不要强行输出操作。

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
        vector<long long> a(n), suf(n + 1), prefAbs(n + 1);
        for (auto &x : a) cin >> x;

        long long original = 0;
        for (long long x : a) original += x;

        for (int i = 0; i < n; ++i) prefAbs[i + 1] = prefAbs[i] + llabs(a[i]);
        for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] + a[i];

        long long best = original;
        int idx = -1;
        for (int i = 0; i < n; ++i) {
            if (a[i] <= 0) continue;
            long long cur = prefAbs[i] - a[i] + suf[i + 1];
            if (cur > best) {
                best = cur;
                idx = i;
            }
        }

        if (idx == -1) {
            cout << 0 << "\n\n";
            continue;
        }

        vector<int> ops;
        bool flip = false;
        for (int i = idx - 1; i >= 0; --i) {
            bool positive = a[i] > 0;
            if (flip) positive = !positive;
            if (positive) {
                ops.push_back(i + 1);
                flip = !flip;
            }
        }
        ops.push_back(idx + 1);

        cout << ops.size() << '\n';
        for (int x : ops) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
```

---

## 一句话总结

枚举最后一次翻转的位置：它左边最终取绝对值，它自己变负，右边保持原样。
