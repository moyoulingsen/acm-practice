# ABC461 E - E-liter

## 网址

https://atcoder.jp/contests/abc461/tasks/abc461_e

## 题解

有一个 `N x N` 网格，初始全白。两种操作：

- `1 R`：把第 `R` 行涂黑；
- `2 C`：把第 `C` 列涂白。

每次操作后输出黑色格子数量。

不能直接维护整个网格。对一个格子 `(r,c)` 来说，它最终颜色只取决于“第 `r` 行最后一次涂黑”和“第 `c` 列最后一次涂白”哪个更晚。

维护：

- `lastRow[r]`：第 `r` 行上次涂黑的时间；
- `lastCol[c]`：第 `c` 列上次涂白的时间；
- Fenwick 树 `rows`：当前每一行最后涂黑时间出现了多少行；
- Fenwick 树 `cols`：当前每一列最后涂白时间出现了多少列；
- `ans`：当前黑格数量。

处理行涂黑 `1 R`：

- 如果这一行之前没涂黑过，先增加 `N` 个黑格；
- 如果之前在时间 `pre` 涂黑过，那么这次只会把那些在 `(pre, now)` 之间被列涂白的格子重新变黑，增加量就是这段时间内作为“最后涂白时间”的列数；
- 更新这行的最后涂黑时间。

处理列涂白 `2 C`：

- 设这列之前最后涂白时间为 `pre`，这次会把所有最后涂黑时间在 `(pre, now)` 之间的行对应格子变白；
- 减去这部分行数；
- 更新这列的最后涂白时间。

时间复杂度：`O(Q log Q)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<int> bit;

    Fenwick(int n = 0) : n(n), bit(n + 1, 0) {}

    void add(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) bit[idx] += val;
    }

    int sum(int idx) const {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx) res += bit[idx];
        return res;
    }

    int range_sum(int l, int r) const {
        if (l > r) return 0;
        return sum(r) - sum(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    Fenwick rows(Q + 2), cols(Q + 2);
    vector<int> lastRow(N + 1, 0), lastCol(N + 1, 0);
    long long ans = 0;

    for (int t = 1; t <= Q; t++) {
        int op, x;
        cin >> op >> x;

        if (op == 1) {
            int pre = lastRow[x];
            if (pre == 0) {
                ans += N;
            } else {
                rows.add(pre, -1);
                ans += cols.range_sum(pre + 1, t - 1);
            }

            rows.add(t, 1);
            lastRow[x] = t;
        } else {
            int pre = lastCol[x];
            ans -= rows.range_sum(pre + 1, t - 1);

            if (pre != 0) cols.add(pre, -1);
            cols.add(t, 1);
            lastCol[x] = t;
        }

        cout << ans << '\n';
    }

    return 0;
}
```

## 样例验证

代码只维护每行/列最后一次操作时间，并用 Fenwick 树统计时间区间内的行列数。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
