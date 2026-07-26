# ABC463 E - Roads and Gates

## 网址

https://atcoder.jp/contests/abc463/tasks/abc463_e

## 题解

普通道路直接建双向边。难点是任意两个城市 `i, j` 都有传送，代价为：

```text
X_i + Y + X_j
```

不能显式建出 `O(N^2)` 条传送边。新增两个虚拟点 `S` 和 `T`：

- 对每个城市 `i`，连边 `i -> S`，权值 `X_i`；
- 连边 `S -> T`，权值 `Y`；
- 对每个城市 `i`，连边 `T -> i`，权值 `X_i`。

于是从 `i` 传送到 `j` 等价于路径：

```text
i -> S -> T -> j
```

总代价正好是 `X_i + Y + X_j`。

所有边权非负，所以在包含 `N+2` 个点的新图上从城市 `1` 跑 Dijkstra，输出到 `2..N` 的距离。

时间复杂度：`O((N+M) log N)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = (1LL << 62);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll Y;
    cin >> N >> M >> Y;

    int S = N;
    int T = N + 1;
    vector<vector<pair<int, ll>>> g(N + 2);

    for (int i = 0; i < M; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u;
        --v;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    vector<ll> X(N);
    for (int i = 0; i < N; i++) cin >> X[i];

    for (int i = 0; i < N; i++) {
        g[i].push_back({S, X[i]});
        g[T].push_back({i, X[i]});
    }
    g[S].push_back({T, Y});

    vector<ll> dist(N + 2, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        if (d != dist[v]) continue;

        for (auto [to, cost] : g[v]) {
            if (dist[to] > d + cost) {
                dist[to] = d + cost;
                pq.push({dist[to], to});
            }
        }
    }

    for (int i = 1; i < N; i++) {
        if (i > 1) cout << ' ';
        cout << dist[i];
    }
    cout << '\n';
    return 0;
}
```

## 样例验证

代码把任意传送边压缩为两个虚拟点上的三段路径，之后直接运行最短路。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
