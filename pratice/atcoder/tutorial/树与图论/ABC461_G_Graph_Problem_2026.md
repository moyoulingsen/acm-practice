# ABC461 G - Graph Problem 2026

## 网址

https://atcoder.jp/contests/abc461/tasks/abc461_g

## 题解

给定无向图，要给每个点赋权 `W_i`，满足：

```text
0 <= W_i <= 2026
W_u + W_v <= 2026   对每条边 (u,v)
```

要求最大化所有点权之和。

关键结论：最优解可以只考虑 `0, 1013, 2026` 三种权值。把每个原点 `i` 拆成二分图中的两个点 `A_i` 和 `B_i`。对原图每条边 `(u,v)`，加入二分图边：

```text
A_u - B_v
A_v - B_u
```

在这个二分图中选择一个独立集，每选中一个拆点贡献 `1013`。若 `A_i` 和 `B_i` 都被选中，对应原点权值为 `2026`；只选一个则为 `1013`；都不选则为 `0`。

原图边 `(u,v)` 对应的约束，会禁止同时选择 `A_u` 和 `B_v`、以及 `A_v` 和 `B_u`，正好由二分图边表达。因此最大权值和为：

```text
1013 * 最大独立集大小
```

二分图中：

```text
最大独立集大小 = 点数 - 最大匹配大小
```

点数为 `2N`，所以答案是：

```text
1013 * (2N - max_matching)
```

用 Hopcroft-Karp 求二分图最大匹配。

时间复杂度：`O(M sqrt N)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

struct HopcroftKarp {
    int n, m;
    vector<vector<int>> g;
    vector<int> dist, ml, mr;

    HopcroftKarp(int n, int m) : n(n), m(m), g(n), dist(n), ml(n, -1), mr(m, -1) {}

    void add_edge(int u, int v) {
        g[u].push_back(v);
    }

    bool bfs() {
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (ml[i] == -1) {
                dist[i] = 0;
                q.push(i);
            } else {
                dist[i] = -1;
            }
        }

        bool found = false;
        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int to : g[v]) {
                int nxt = mr[to];
                if (nxt == -1) {
                    found = true;
                } else if (dist[nxt] == -1) {
                    dist[nxt] = dist[v] + 1;
                    q.push(nxt);
                }
            }
        }
        return found;
    }

    bool dfs(int v) {
        for (int to : g[v]) {
            int nxt = mr[to];
            if (nxt == -1 || (dist[nxt] == dist[v] + 1 && dfs(nxt))) {
                ml[v] = to;
                mr[to] = v;
                return true;
            }
        }
        dist[v] = -1;
        return false;
    }

    int max_matching() {
        int res = 0;
        while (bfs()) {
            for (int i = 0; i < n; i++) {
                if (ml[i] == -1 && dfs(i)) res++;
            }
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    HopcroftKarp hk(N, N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        hk.add_edge(u, v);
        hk.add_edge(v, u);
    }

    int matching = hk.max_matching();
    cout << 1013LL * (2LL * N - matching) << '\n';
    return 0;
}
```

## 样例验证

代码把原图约束转成二分图最大独立集问题，再用最大匹配求解。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
