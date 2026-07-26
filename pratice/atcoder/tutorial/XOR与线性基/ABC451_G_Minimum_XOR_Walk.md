# ABC451 G - Minimum XOR Walk

## 网址

https://atcoder.jp/contests/abc451/tasks/abc451_g

## 题解

任取一棵生成树，以 `1` 为根，令 `A_v` 表示生成树上从 `1` 到 `v` 的路径 XOR。

对于任意边 `(u, v, w)`，定义：

```text
cycle = A_u xor A_v xor w
```

这些 `cycle` 张成的 XOR 线性空间表示 walk 中可以额外加入的环 XOR。

于是 `x` 到 `y` 的 walk 最小 XOR 值为：

```text
min over s in span(cycle) of (A_x xor A_y xor s)
```

建立 XOR 线性基后，可以把任意数化成其所在陪集中的最小代表 `f(z)`。官方结论是：

```text
f(x xor y) = f(x) xor f(y)
```

令 `B_i = f(A_i)`，问题转化为统计有多少对 `i < j` 满足：

```text
B_i xor B_j <= K
```

这个用二进制 Trie 在线统计即可。

时间复杂度：`O((N+M) * 30)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

struct XorBasis {
    static constexpr int LOG = 30;
    int basis[LOG];

    XorBasis() {
        memset(basis, 0, sizeof(basis));
    }

    void insert(int x) {
        for (int b = LOG - 1; b >= 0; b--) {
            if (((x >> b) & 1) == 0) continue;

            if (!basis[b]) {
                basis[b] = x;
                return;
            }

            x ^= basis[b];
        }
    }

    int minimize(int x) const {
        for (int b = LOG - 1; b >= 0; b--) {
            if (basis[b] && (x ^ basis[b]) < x) x ^= basis[b];
        }
        return x;
    }
};

struct BinaryTrie {
    static constexpr int LOG = 30;

    struct Node {
        int child[2];
        int cnt;

        Node() {
            child[0] = child[1] = -1;
            cnt = 0;
        }
    };

    vector<Node> tr;

    BinaryTrie() {
        tr.emplace_back();
    }

    void insert(int x) {
        int v = 0;
        tr[v].cnt++;

        for (int b = LOG - 1; b >= 0; b--) {
            int bit = (x >> b) & 1;

            if (tr[v].child[bit] == -1) {
                tr[v].child[bit] = (int)tr.size();
                tr.emplace_back();
            }

            v = tr[v].child[bit];
            tr[v].cnt++;
        }
    }

    long long count_leq(int x, int k) const {
        int v = 0;
        long long res = 0;

        for (int b = LOG - 1; b >= 0; b--) {
            if (v == -1) break;

            int xb = (x >> b) & 1;
            int kb = (k >> b) & 1;

            if (kb == 1) {
                int same = tr[v].child[xb];
                if (same != -1) res += tr[same].cnt;
                v = tr[v].child[xb ^ 1];
            } else {
                v = tr[v].child[xb];
            }
        }

        if (v != -1) res += tr[v].cnt;
        return res;
    }
};

struct Edge {
    int u, v, w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;

        vector<Edge> edges(M);
        vector<vector<pair<int, int>>> g(N);

        for (int i = 0; i < M; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            --u;
            --v;

            edges[i] = {u, v, w};
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }

        vector<int> A(N);
        vector<int> visited(N);
        queue<int> q;
        visited[0] = 1;
        q.push(0);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (auto [to, w] : g[v]) {
                if (!visited[to]) {
                    visited[to] = 1;
                    A[to] = A[v] ^ w;
                    q.push(to);
                }
            }
        }

        XorBasis basis;
        for (auto e : edges) {
            basis.insert(A[e.u] ^ A[e.v] ^ e.w);
        }

        vector<int> B(N);
        for (int i = 0; i < N; i++) B[i] = basis.minimize(A[i]);

        BinaryTrie trie;
        long long ans = 0;

        for (int i = 0; i < N; i++) {
            ans += trie.count_leq(B[i], K);
            trie.insert(B[i]);
        }

        cout << ans << '\n';
    }

    return 0;
}
```

## 样例验证

```text
输入
3
4 4 2
3 4 3
1 3 4
1 2 3
2 3 2
5 7 14032
1 2 24681
3 5 25665
1 5 14154
2 3 23215
1 3 21259
4 5 24874
3 4 26495
8 10 109312507
6 8 793188457
7 8 501937135
1 2 954888411
2 7 109497327
1 6 791995625
2 6 665857693
1 3 101233808
1 7 114788578
4 6 953503358
5 8 624700613

输出
4
9
22
```
