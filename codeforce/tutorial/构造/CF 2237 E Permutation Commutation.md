# CF 2237 E - Permutation Commutation

**题目链接**：<https://codeforces.com/problemset/problem/2237/E>

**对应题单**：Codeforces Round 1104 E

**题型**：构造 / 置换环 / 贪心

**难度**：2000（紫）

---

## 题意压缩

给定置换 `a` 和一个部分给定的置换 `b`，需要补全 `b`，使得：

\[
a_{b_i} = b_{a_i}
\]

并且要求字典序最小。

这个条件等价于两个置换可交换：`a ∘ b = b ∘ a`。

---

## 关键观察

把 `a` 分解成若干个环。

如果 `b` 把某个点 `u` 映射到 `v`，那么：

- `u` 所在的整个环都会被映射到 `v` 所在的整个环；
- 两个环长度必须相同；
- 映射必须保持环上的相对顺序，只能选择一个偏移量。

因此，一个已知的 `b[u]=v` 会强制填完整个源环。

剩下没有被强制的源环，只能匹配到还没使用过、长度相同的目标环。为了字典序最小，按源环最小下标从小到大处理，每次选择能让这个最小下标映射值最小的目标环。

---

## 思路步骤

1. 分解置换 `a` 的所有环，记录每个点属于哪个环、在环内的位置。
2. 扫描已知 `b[i]`：
   - 若源环还没确定映射，则用 `b[i]` 确定目标环和偏移；
   - 若长度不同、目标环已被使用、或填充时冲突，则无解。
3. 把所有强制环填完。
4. 对剩余源环，按源环最小下标排序：
   - 在同长度未使用目标环中，选最小元素最小的环；
   - 选择偏移，使源环最小下标映射到该最小目标点；
   - 填完整个环。
5. 最后校验 `b` 是置换并满足交换式。

---

## 易错点

- 源环和目标环长度必须相同。
- 一个目标环只能被一个源环使用，否则 `b` 不是置换。
- 字典序最小不是随便选同长度环，而是按当前最小未填下标选择最小可映射值。
- 题面若用 `0` 表示未知，读入后可以统一转成 `-1`。

---

## 复杂度

`O(n log n)`。

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
        vector<int> a(n), input(n), b(n, -1);
        for (int &x : a) {
            cin >> x;
            --x;
        }
        for (int &x : input) {
            cin >> x;
            if (x == 0 || x == -1) x = -1;
            else --x;
        }

        vector<vector<int>> cyc;
        vector<int> cid(n), pos(n), vis(n);
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            int u = i;
            vector<int> cur;
            while (!vis[u]) {
                vis[u] = 1;
                pos[u] = cur.size();
                cid[u] = cyc.size();
                cur.push_back(u);
                u = a[u];
            }
            cyc.push_back(cur);
        }

        int m = cyc.size();
        vector<int> sourceDone(m), targetUsed(m);
        bool ok = true;

        auto assignCycle = [&](int s, int t, int shift) {
            if ((int)cyc[s].size() != (int)cyc[t].size()) return false;
            if (sourceDone[s] || targetUsed[t]) return false;
            int len = cyc[s].size();
            for (int i = 0; i < len; ++i) {
                int u = cyc[s][i];
                int v = cyc[t][(i + shift) % len];
                if (b[u] != -1 && b[u] != v) return false;
                if (input[u] != -1 && input[u] != v) return false;
            }
            for (int i = 0; i < len; ++i) {
                int u = cyc[s][i];
                int v = cyc[t][(i + shift) % len];
                b[u] = v;
            }
            sourceDone[s] = 1;
            targetUsed[t] = 1;
            return true;
        };

        for (int i = 0; i < n && ok; ++i) {
            if (input[i] == -1) continue;
            int s = cid[i], t = cid[input[i]];
            int len = cyc[s].size();
            int shift = (pos[input[i]] - pos[i] + len) % len;
            if (sourceDone[s]) {
                if (b[i] != input[i]) ok = false;
            } else {
                ok = assignCycle(s, t, shift);
            }
        }

        map<int, set<pair<int, int>>> available;
        for (int id = 0; id < m; ++id) {
            if (targetUsed[id]) continue;
            int mn = *min_element(cyc[id].begin(), cyc[id].end());
            available[cyc[id].size()].insert({mn, id});
        }

        vector<pair<int, int>> sources;
        for (int id = 0; id < m; ++id) {
            if (sourceDone[id]) continue;
            int mn = *min_element(cyc[id].begin(), cyc[id].end());
            sources.push_back({mn, id});
        }
        sort(sources.begin(), sources.end());

        for (auto [mnSource, s] : sources) {
            int len = cyc[s].size();
            if (available[len].empty()) {
                ok = false;
                break;
            }
            auto it = available[len].begin();
            int mnTarget = it->first;
            int t = it->second;
            available[len].erase(it);
            int shift = (pos[mnTarget] - pos[mnSource] + len) % len;
            if (!assignCycle(s, t, shift)) {
                ok = false;
                break;
            }
        }

        vector<int> seen(n);
        for (int i = 0; i < n && ok; ++i) {
            if (b[i] < 0 || b[i] >= n || seen[b[i]]) ok = false;
            else seen[b[i]] = 1;
        }
        for (int i = 0; i < n && ok; ++i) {
            if (a[b[i]] != b[a[i]]) ok = false;
        }

        if (!ok) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i = 0; i < n; ++i) {
                cout << b[i] + 1 << " \n"[i + 1 == n];
            }
        }
    }
    return 0;
}
```

---

## 一句话总结

可交换置换必须把 `a` 的每个环映射到同长度环，并保持环内顺序；已知点强制整环，剩余环贪心匹配出字典序最小。
