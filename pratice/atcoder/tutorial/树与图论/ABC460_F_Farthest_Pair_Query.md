# ABC460 F - Farthest Pair Query

## 网址

https://atcoder.jp/contests/abc460/tasks/abc460_f

## 题解

给定一棵树，初始所有点都是黑色。每次翻转一个点的颜色，操作后输出当前黑点集合中两点距离的最大值，也就是黑点集合的直径。

线段树按点编号维护区间内黑点集合的直径信息：

```text
(u, v, d)
```

表示区间内黑点的最远点对是 `(u,v)`，距离为 `d`。若区间内没有黑点，记为 `d=-1`。

合并左右区间时，答案只可能来自：

- 左区间内部直径；
- 右区间内部直径；
- 左右直径端点之间的四种组合。

树上有性质：对任意点 `x`，一个点集里离 `x` 最远的点一定是该点集某条直径的端点之一，所以跨区间只需要枚举四对端点。

树上距离用 LCA 计算：

```text
dist(u,v) = dep[u] + dep[v] - 2*dep[lca(u,v)]
```

每次翻转点颜色就是线段树单点修改，根节点的 `d` 即答案。

时间复杂度：预处理 `O(N log N)`，每次查询 `O(log N)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int N, Q;
vector<vector<int>> g;
vector<int> depth, first, lg;
vector<vector<int>> st;

int better_depth(int a, int b) {
    return depth[a] < depth[b] ? a : b;
}

void build_lca() {
    vector<int> euler;
    first.assign(N + 1, -1);
    depth.assign(N + 1, 0);

    vector<int> parent(N + 1), it(N + 1);
    vector<int> stk = {1};
    parent[1] = 1;
    first[1] = 0;
    euler.push_back(1);

    while (!stk.empty()) {
        int v = stk.back();
        if (it[v] == (int)g[v].size()) {
            stk.pop_back();
            if (!stk.empty()) euler.push_back(stk.back());
            continue;
        }

        int to = g[v][it[v]++];
        if (to == parent[v]) continue;
        parent[to] = v;
        depth[to] = depth[v] + 1;
        first[to] = (int)euler.size();
        euler.push_back(to);
        stk.push_back(to);
    }

    int M = (int)euler.size();
    lg.assign(M + 1, 0);
    for (int i = 2; i <= M; i++) lg[i] = lg[i / 2] + 1;

    int K = lg[M] + 1;
    st.assign(K, vector<int>(M));
    st[0] = euler;
    for (int k = 1; k < K; k++) {
        for (int i = 0; i + (1 << k) <= M; i++) {
            st[k][i] = better_depth(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
        }
    }
}

int lca(int u, int v) {
    int l = first[u], r = first[v];
    if (l > r) swap(l, r);
    int k = lg[r - l + 1];
    return better_depth(st[k][l], st[k][r - (1 << k) + 1]);
}

int dist_tree(int u, int v) {
    int w = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[w];
}

struct Info {
    int u = 0, v = 0, d = -1;
};

Info merge_info(const Info &a, const Info &b) {
    if (a.d == -1) return b;
    if (b.d == -1) return a;

    Info res = a.d >= b.d ? a : b;
    auto relax = [&](int x, int y) {
        int nd = dist_tree(x, y);
        if (nd > res.d) res = {x, y, nd};
    };

    relax(a.u, b.u);
    relax(a.u, b.v);
    relax(a.v, b.u);
    relax(a.v, b.v);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    g.assign(N + 1, {});
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    build_lca();

    int sz = 1;
    while (sz < N) sz <<= 1;

    vector<Info> seg(sz * 2);
    for (int i = 1; i <= N; i++) seg[sz + i - 1] = {i, i, 0};
    for (int i = sz - 1; i >= 1; i--) seg[i] = merge_info(seg[i << 1], seg[i << 1 | 1]);

    vector<char> black(N + 1, true);

    auto update = [&](int pos) {
        int p = sz + pos - 1;
        if (black[pos]) seg[p] = {pos, pos, 0};
        else seg[p] = {0, 0, -1};

        for (p >>= 1; p; p >>= 1) {
            seg[p] = merge_info(seg[p << 1], seg[p << 1 | 1]);
        }
    };

    cin >> Q;
    while (Q--) {
        int x;
        cin >> x;
        black[x] = !black[x];
        update(x);
        cout << seg[1].d << '\n';
    }

    return 0;
}
```

## 样例验证

代码维护黑点集合直径，单点翻转后根节点即全局答案。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
