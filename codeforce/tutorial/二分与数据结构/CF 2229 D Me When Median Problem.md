# CF 2229 D - Me When Median Problem

**题目链接**：<https://codeforces.com/problemset/problem/2229/D>

**对应题单**：Codeforces Round 1100 D

**题型**：二分答案 / 贪心

**难度**：1700（蓝）

---

## 题意压缩

给定两行数组，需要通过题目允许的操作最大化最终中位数或最小值形式的答案。

这类题最自然的做法是二分答案 `x`，判断能否让最终结果至少为 `x`。

---

## 关键观察

固定一个候选答案 `x`，把每一列按是否 `>= x` 分类：

- `0`：这一列两个数都 `< x`；
- `1`：这一列恰好一个数 `>= x`；
- `2`：这一列两个数都 `>= x`。

`1` 类型列可以被当作分隔，不会形成必须额外处理的坏块。

剩下真正重要的是：

- `2` 类型列提供一个“好资源”；
- 连续的 `0` 类型列形成一个“坏块”。

可行条件是：

\[
\#type2 > \#zeroBlocks
\]

也就是好资源数量严格多于坏块数量。

---

## 思路步骤

1. 二分答案 `x`。
2. 对每列统计有几个数 `>= x`。
3. 扫描列：
   - `cnt == 2`：好资源 `good++`；
   - `cnt == 1`：打断连续坏块；
   - `cnt == 0`：若刚进入一个新的连续坏块，则 `bad++`。
4. 若 `good > bad`，说明 `x` 可行。

---

## 易错点

- `cnt == 1` 的列会打断 `0` 块。
- 条件是严格大于：`good > bad`。
- 二分上界可以取所有数最大值。

---

## 复杂度

`O(n log V)`。

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
        vector<vector<int>> a(2, vector<int>(n));
        int hi = 0;
        for (int r = 0; r < 2; ++r) {
            for (int c = 0; c < n; ++c) {
                cin >> a[r][c];
                hi = max(hi, a[r][c]);
            }
        }

        auto ok = [&](int x) {
            int good = 0, bad = 0;
            bool inBad = false;
            for (int c = 0; c < n; ++c) {
                int cnt = (a[0][c] >= x) + (a[1][c] >= x);
                if (cnt == 2) {
                    good++;
                    inBad = false;
                } else if (cnt == 1) {
                    inBad = false;
                } else {
                    if (!inBad) bad++;
                    inBad = true;
                }
            }
            return good > bad;
        };

        int lo = 1, ans = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (ok(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
```

---

## 一句话总结

二分答案后，每列只需要看有几个数达标：双达标列数量必须严格压过连续双不达标块数量。
