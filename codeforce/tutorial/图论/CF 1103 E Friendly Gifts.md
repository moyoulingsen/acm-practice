# CF 1103 E - Friendly Gifts

**真实题号**：CF 2236 E

**题目链接**：<https://codeforces.com/problemset/problem/2236/E>

**题型**：区间 / 排列 / 枚举

**难度体感**：1700，关键是把“好数组”转成连续值域。

---

## 题意压缩

给定一个排列。

一个子数组如果满足某种“好”的条件，就可以作为一份礼物。

要求找到最大的 `k`，使得存在两段长度为 `k` 的好子数组，并且它们合起来也对应一段连续的值域。

---

## 关键观察

一个长度为 `len` 的子数组是好数组，等价于：

- 所有元素互不相同；
- 最大值和最小值满足：

\[
max-min=len-1
\]

也就是说，这个子数组的值集合刚好是某个连续整数区间。

因此可以预处理：

```text
able[l][r] = 是否存在某个子数组，它的值集合正好是 [l,r]
```

---

## 如何预处理 able

枚举子数组左端点 `L`，向右扩展 `R`。

维护当前子数组的：

- 最小值 `mn`；
- 最大值 `mx`；
- 是否出现重复值。

如果没有重复，并且：

\[
mx-mn=R-L
\]

说明当前子数组的值集合正好是 `[mn,mx]`，令 `able[mn][mx]=true`。

---

## 如何检查答案 k

如果两份长度为 `k` 的礼物合起来也是连续值域，那么它们的值域应该是相邻的：

```text
[x, x+k-1]
[x+k, x+2k-1]
```

所以只需要检查是否存在 `x` 满足：

```text
able[x][x+k-1] && able[x+k][x+2k-1]
```

从大到小枚举 `k`，第一个可行的就是答案。

---

## 为什么不用额外检查两个子数组是否重叠

如果两个子数组的值域不相交，而原数组是排列，那么它们不可能共享同一个位置。

因为同一个位置只有一个值，不可能同时属于两个不相交值域。

---

## 复杂度

预处理所有子数组：

\[
O(n^2)
\]

检查答案也是：

\[
O(n^2)
\]

总复杂度：

\[
O(n^2)
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
        int n;
        cin >> n;

        vector<int> a(n);
        for (int &x : a) {
            cin >> x;
            --x;
        }

        vector<vector<unsigned char>> able(n, vector<unsigned char>(n, 0));
        vector<int> seen(n, -1);

        for (int l = 0; l < n; ++l) {
            int mn = n, mx = -1;
            for (int r = l; r < n; ++r) {
                int x = a[r];
                if (seen[x] == l) break;
                seen[x] = l;

                mn = min(mn, x);
                mx = max(mx, x);

                if (mx - mn == r - l) {
                    able[mn][mx] = 1;
                }
            }
        }

        for (int len = n / 2; len >= 1; --len) {
            for (int x = 0; x + 2 * len <= n; ++x) {
                if (able[x][x + len - 1] && able[x + len][x + 2 * len - 1]) {
                    cout << len << '\n';
                    goto solved;
                }
            }
        }

        cout << 0 << '\n';

    solved:;
    }
    return 0;
}
```

---

## 一句话总结

这题就是：**把每个好子数组映射成一个连续值域，再找两段相邻且长度相同的值域。**
