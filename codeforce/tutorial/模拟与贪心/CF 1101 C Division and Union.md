# CF 1101 C - Division and Union

**题目链接**：<https://codeforces.com/problemset/problem/1101/C>

**题型**：区间 / 排序 / 贪心分组

**难度体感**：C 题，核心是把区间按左端点排序后找一个“断点”。

---

## 题意压缩

给 `n` 个区间 `[l_i,r_i]`，要把它们分成两组：

- 每个区间必须属于一组；
- 两组都不能为空；
- 任意来自不同组的两个区间不能相交。

如果可以，输出每个原区间属于第几组；否则输出 `-1`。

---

## 关键观察

如果把所有区间按左端点排序，那么想让两组完全不相交，只需要找到一个位置 `i`，使得：

\[
\max(r_1, r_2, \dots, r_i) < l_{i+1}
\]

这样前 `i` 个区间放一组，后面的区间放另一组，两个集合之间就没有交集。

---

## 思路步骤

1. 保存每个区间的原始编号。
2. 按左端点从小到大排序。
3. 扫描排序后的区间，维护前缀最大右端点 `mx`。
4. 如果某个位置满足 `mx < next_l`，就找到断点。
5. 断点左边赋值为 `1`，右边赋值为 `2`。
6. 如果没有断点，输出 `-1`。

---

## 易错点

- 输出顺序必须按原始输入顺序；
- 条件是严格 `mx < next_l`，端点相等说明两个闭区间相交；
- 两组都不能为空，所以断点不能在最后。

---

## 复杂度

\[
O(n \log n)
\]

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Seg {
    int l, r, id;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<Seg> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].l >> a[i].r;
            a[i].id = i;
        }

        sort(a.begin(), a.end(), [](const Seg &x, const Seg &y) {
            if (x.l != y.l) return x.l < y.l;
            return x.r < y.r;
        });

        int split = -1;
        int mx = a[0].r;
        for (int i = 0; i + 1 < n; ++i) {
            mx = max(mx, a[i].r);
            if (mx < a[i + 1].l) {
                split = i;
                break;
            }
        }

        if (split == -1) {
            cout << -1 << '\n';
            continue;
        }

        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[a[i].id] = (i <= split ? 1 : 2);
        }

        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " \n"[i + 1 == n];
        }
    }

    return 0;
}
```

---

## 一句话总结

排序后找第一个“前缀右端点完全小于下一个左端点”的断点即可。
