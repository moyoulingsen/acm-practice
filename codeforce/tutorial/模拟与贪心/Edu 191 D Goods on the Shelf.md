# Edu 191 D - Goods on the Shelf

**题目链接**：<https://codeforces.com/problemset/problem/2233/D>

**题型**：实现 / 分块 / 局部枚举

**难度**：1900

---

## 题意压缩

给一个数组，问是否能通过至多一次交换，使得每种数的所有出现位置都构成一个连续段。

---

## 关键观察

如果某个值已经被分成太多段，一次交换不可能把它修好。

具体做法是：

1. 把数组按连续相同值分块；
2. 找第一个出现超过一段的值；
3. 只枚举这个坏值各段边界附近的位置进行交换。

为什么只看边界？因为一次交换如果能改变分块结构，关键变化一定发生在块的边界附近；块内部同值位置互换没有意义。

候选位置数量很小，枚举两两交换后全局检查即可。

---

## 思路步骤

1. 离散化数组值。
2. 扫描连续块，统计每个值有多少块，并收集坏值块边界附近位置。
3. 如果所有值都只有一块，输出 `YES`。
4. 如果坏值块数超过 `3`，输出 `NO`。
5. 枚举候选位置两两交换，检查是否所有值都只剩一块。

---

## 复杂度

候选点数是常数级，整体近似 `O(n log n)`。

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

        vector<long long> raw(n);
        for (auto &x : raw) cin >> x;

        vector<long long> vals = raw;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        int m = vals.size();
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = lower_bound(vals.begin(), vals.end(), raw[i]) - vals.begin();
        }

        vector<int> blockCnt(m);
        vector<vector<int>> cand(m);

        for (int l = 0; l < n;) {
            int r = l;
            while (r < n && a[r] == a[l]) ++r;

            int v = a[l];
            ++blockCnt[v];

            for (int p : {l - 1, l, r - 1, r}) {
                if (0 <= p && p < n) cand[v].push_back(p);
            }

            l = r;
        }

        int bad = -1;
        for (int v = 0; v < m; ++v) {
            if (blockCnt[v] > 1) {
                bad = v;
                break;
            }
        }

        if (bad == -1) {
            cout << "YES\n";
            continue;
        }

        if (blockCnt[bad] > 3) {
            cout << "NO\n";
            continue;
        }

        auto goodAfterSwap = [&](int x, int y) {
            swap(a[x], a[y]);

            vector<int> cnt(m);
            for (int l = 0; l < n;) {
                int r = l;
                while (r < n && a[r] == a[l]) ++r;
                ++cnt[a[l]];
                l = r;
            }

            swap(a[x], a[y]);

            for (int v = 0; v < m; ++v) {
                if (cnt[v] > 1) return false;
            }
            return true;
        };

        auto &v = cand[bad];
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        bool ok = false;
        for (int i = 0; i < (int)v.size(); ++i) {
            for (int j = i + 1; j < (int)v.size(); ++j) {
                if (goodAfterSwap(v[i], v[j])) ok = true;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
```

---

## 一句话总结

一次交换只可能修复坏块边界附近的问题，所以枚举第一个坏值的边界位置即可。
