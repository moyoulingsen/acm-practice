# ABC456 E - Endless Holidays

## 网址

https://atcoder.jp/contests/abc456/tasks/abc456_e

## 题解

建立状态图，状态为 `(city, day)`。如果第 `day` 天在城市 `u` 是休息日，下一天在城市 `v` 也是休息日，并且 `v==u` 或 `u,v` 有边相连，则连边：

```text
(u, day) -> (v, next_day)
```

因为一周是周期性的，能永远每天在休息日城市，当且仅当这个有限有向图中存在环。

用拓扑排序判环：如果删不完所有活跃状态，就存在环。

时间复杂度：`O((N+M)W)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<vector<int>> city_adj(N);
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            city_adj[u].push_back(v);
            city_adj[v].push_back(u);
        }

        int W;
        cin >> W;

        vector<string> S(N);
        for (int i = 0; i < N; i++) cin >> S[i];

        int V = N * W;
        vector<vector<int>> g(V);
        vector<int> indeg(V);
        vector<char> active(V);

        auto id = [&](int city, int day) {
            return day * N + city;
        };

        int active_count = 0;
        for (int d = 0; d < W; d++) {
            for (int v = 0; v < N; v++) {
                if (S[v][d] == 'o') {
                    active[id(v, d)] = 1;
                    active_count++;
                }
            }
        }

        auto add_edge = [&](int from, int to) {
            g[from].push_back(to);
            indeg[to]++;
        };

        for (int d = 0; d < W; d++) {
            int nd = (d + 1) % W;
            for (int v = 0; v < N; v++) {
                if (S[v][d] != 'o') continue;

                int from = id(v, d);

                if (S[v][nd] == 'o') add_edge(from, id(v, nd));

                for (int to_city : city_adj[v]) {
                    if (S[to_city][nd] == 'o') add_edge(from, id(to_city, nd));
                }
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (active[i] && indeg[i] == 0) q.push(i);
        }

        int removed = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            removed++;

            for (int to : g[v]) {
                indeg[to]--;
                if (indeg[to] == 0) q.push(to);
            }
        }

        cout << (removed < active_count ? "Yes" : "No") << '\n';
    }

    return 0;
}
```

## 样例验证

```text
输入
3
4 4
1 2
1 4
2 4
2 3
3
xxo
xox
oxo
oxx
1 0
4
oooo
5 5
1 4
2 3
4 5
3 4
2 5
7
oxxxxxx
xxoxxxo
xxxoxox
xoxxoxx
oxxxoxx

输出
Yes
Yes
No
```
