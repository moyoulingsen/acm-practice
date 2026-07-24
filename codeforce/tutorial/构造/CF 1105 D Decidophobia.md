# CF 1105 D - Kilani and the Game

**题目链接**：<https://codeforces.com/problemset/problem/1105/D>

**题型**：BFS / 多源扩展 / 模拟

**难度体感**：1500 左右典型网格扩张题。

---

## 题意压缩

多名玩家在网格上扩张领地，每个人每轮最多扩张固定步数。要求最后统计每个人占了多少格。

---

## 关键观察

这题不是普通 BFS，而是：

- 每个玩家都有自己的扩张队列；
- 每轮只能走最多 `s[i]` 层；
- 所以更像“分玩家的分层 BFS”。

最自然的做法就是：

- 为每个玩家维护一个队列；
- 每轮对每个玩家做有限层数的 BFS 扩张。

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, p;
    cin >> n >> m >> p;
    vector<int> s(p + 1);
    for (int i = 1; i <= p; ++i) cin >> s[i];

    vector<string> g(n);
    for (int i = 0; i < n; ++i) cin >> g[i];

    vector<queue<pair<int,int>>> q(p + 1);
    vector<int> ans(p + 1, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (isdigit(g[i][j])) {
                int id = g[i][j] - '0';
                q[id].push({i, j});
                ans[id]++;
            }
        }
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    bool moved = true;
    while (moved) {
        moved = false;
        for (int id = 1; id <= p; ++id) {
            int steps = s[id];
            queue<pair<int,int>> nq;
            while (!q[id].empty()) {
                auto cur = q[id].front(); q[id].pop();
                nq.push(cur);
            }
            while (steps--) {
                int sz = (int)nq.size();
                if (sz == 0) break;
                moved = true;
                while (sz--) {
                    auto [x, y] = nq.front(); nq.pop();
                    for (int d = 0; d < 4; ++d) {
                        int nx = x + dx[d], ny = y + dy[d];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m || g[nx][ny] != '.') continue;
                        g[nx][ny] = char('0' + id);
                        ans[id]++;
                        nq.push({nx, ny});
                    }
                }
            }
            q[id] = nq;
        }
    }

    for (int i = 1; i <= p; ++i) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}
```

---

## 一句话总结

这题本质是：**每个玩家各自做“每轮最多扩张 s[i] 层”的 BFS。**
