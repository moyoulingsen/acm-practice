# Edu 188 D - Alternating Path

**题目链接**：<https://codeforces.com/problemset/problem/2204/D>

**题型**：图论 / 二分图染色

**难度**：1400

---

## 题意压缩

给一张无向图，需要按题目要求给边定向，使尽量多的点满足条件。

---

## 关键观察

一个连通分量如果不是二分图，就不能整体按交替方式定向，贡献为 `0`。

如果一个连通分量是二分图，设两侧点数为 `cnt0, cnt1`。把所有边统一从一侧指向另一侧，就可以让其中一侧的点满足条件。

为了最大化答案，每个连通分量选择较大的颜色类贡献：

\[
\max(cnt0,cnt1)
\]

---

## 思路步骤

1. 对每个未访问点做 BFS/DFS 染色。
2. 如果发现同色相邻，当前连通分量不是二分图，贡献 `0`。
3. 否则统计两种颜色数量，累加较大值。

---

## 复杂度

`O(n+m)`。

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

        vector<vector<int>> g(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> color(n, -1);
        int ans = 0;

        for (int st = 0; st < n; ++st) {
            if (color[st] != -1) continue;

            queue<int> q;
            q.push(st);
            color[st] = 0;

            int cnt[2] = {0, 0};
            bool ok = true;

            while (!q.empty()) {
                int v = q.front();
                q.pop();

                ++cnt[color[v]];

                for (int to : g[v]) {
                    if (color[to] == -1) {
                        color[to] = color[v] ^ 1;
                        q.push(to);
                    } else if (color[to] == color[v]) {
                        ok = false;
                    }
                }
            }

            if (ok) ans += max(cnt[0], cnt[1]);
        }

        cout << ans << '\n';
    }

    return 0;
}
```

---

## 一句话总结

每个二分图连通块能贡献较大的一边，非二分图连通块贡献为 `0`。
