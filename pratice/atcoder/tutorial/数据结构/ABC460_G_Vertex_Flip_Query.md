# ABC460 G - Vertex Flip Query

## 网址

https://atcoder.jp/contests/abc460/tasks/abc460_g

## 题解

给定一棵树。每个点有权值 `W_i` 和颜色 `C_i`。支持三种操作：

- `1 v`：翻转点 `v` 的颜色；
- `2 v x`：令 `W_v += x`；
- `3 v`：输出点 `v` 所在的同色连通块权值和。

下面给出 HLD + Fenwick 的做法。

以 `1` 为根。定义：

```text
S_c(v) = W_v + sum S_c(u)
```

其中 `u` 枚举 `v` 的儿子，并且要求 `C_u = c`。注意即使 `C_v != c`，`S_c(v)` 也有定义。若 `C_v = c`，那么 `S_c(v)` 就表示从 `v` 往子树方向能连通到的颜色 `c` 连通块权值和。

对查询点 `v`，设 `c=C_v`。从 `v` 往根找最近的一个颜色不是 `c` 的点 `bad`：

- 若不存在，则同色连通块的最高点是根 `1`；
- 否则最高点是 `bad` 到 `v` 路径上的下一个点。

答案就是这个最高点 `t` 的 `S_c(t)`。

需要维护两件事：

1. `S_0, S_1` 的路径加、单点查。用两个 Fenwick 差分树维护重链剖分序上的增量，初始 `S_c(v)` 作为 `base[c][v]`。
2. 路径上最近的颜色不同点。用线段树维护 HLD 序上的颜色，查询区间内最靠右的坏点。

更新规则：

- `2 v x`：`W_v` 增加 `x`。对当前颜色 `c=C_v`，从同色连通块最高点到 `v` 的路径上所有 `S_c` 都增加 `x`；另一个颜色只影响 `S_{1-c}(v)` 本身。
- `1 v`：翻转前，`S_old(v)` 对一段祖先路径有贡献，先减掉；翻转颜色后，`S_new(v)` 对新颜色的一段祖先路径有贡献，再加回。

时间复杂度：`O((N+Q) log^2 N)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<long long> bit;

    Fenwick() : n(0) {}
    Fenwick(int n_) { init(n_); }

    void init(int n_) {
        n = n_;
        bit.assign(n + 2, 0);
    }

    void add(int idx, long long val) {
        for (; idx <= n; idx += idx & -idx) bit[idx] += val;
    }

    void range_add(int l, int r, long long val) {
        if (l > r) return;
        add(l, val);
        if (r + 1 <= n) add(r + 1, -val);
    }

    long long sum(int idx) const {
        long long res = 0;
        for (; idx > 0; idx -= idx & -idx) res += bit[idx];
        return res;
    }
};

struct ColorSegTree {
    int n;
    vector<int> sum1;

    ColorSegTree() : n(0) {}

    void build(const vector<int> &a) {
        n = (int)a.size() - 1;
        sum1.assign(4 * n + 4, 0);
        build_rec(1, 1, n, a);
    }

    void build_rec(int p, int l, int r, const vector<int> &a) {
        if (l == r) {
            sum1[p] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build_rec(p << 1, l, m, a);
        build_rec(p << 1 | 1, m + 1, r, a);
        sum1[p] = sum1[p << 1] + sum1[p << 1 | 1];
    }

    void set_color(int pos, int val) {
        set_rec(1, 1, n, pos, val);
    }

    void set_rec(int p, int l, int r, int pos, int val) {
        if (l == r) {
            sum1[p] = val;
            return;
        }
        int m = (l + r) / 2;
        if (pos <= m) set_rec(p << 1, l, m, pos, val);
        else set_rec(p << 1 | 1, m + 1, r, pos, val);
        sum1[p] = sum1[p << 1] + sum1[p << 1 | 1];
    }

    bool has_bad(int p, int l, int r, int c) const {
        int len = r - l + 1;
        if (c == 0) return sum1[p] > 0;
        return sum1[p] < len;
    }

    int find_last_bad(int ql, int qr, int c) const {
        return find_rec(1, 1, n, ql, qr, c);
    }

    int find_rec(int p, int l, int r, int ql, int qr, int c) const {
        if (qr < l || r < ql) return -1;
        if (ql <= l && r <= qr && !has_bad(p, l, r, c)) return -1;
        if (l == r) return l;

        int m = (l + r) / 2;
        int right = find_rec(p << 1 | 1, m + 1, r, ql, qr, c);
        if (right != -1) return right;
        return find_rec(p << 1, l, m, ql, qr, c);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<long long> W(N + 1);
    for (int i = 1; i <= N; i++) cin >> W[i];

    vector<int> C(N + 1);
    for (int i = 1; i <= N; i++) cin >> C[i];

    vector<vector<int>> g(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> parent(N + 1), depth(N + 1), order;
    order.reserve(N);
    order.push_back(1);

    for (int i = 0; i < (int)order.size(); i++) {
        int v = order[i];
        for (int u : g[v]) {
            if (u == parent[v]) continue;
            parent[u] = v;
            depth[u] = depth[v] + 1;
            order.push_back(u);
        }
    }

    vector<int> sz(N + 1, 1), heavy(N + 1);
    array<vector<long long>, 2> base{vector<long long>(N + 1), vector<long long>(N + 1)};
    for (int c = 0; c < 2; c++) {
        for (int v = 1; v <= N; v++) base[c][v] = W[v];
    }

    for (int i = N - 1; i >= 0; i--) {
        int v = order[i];
        int best = 0;
        for (int u : g[v]) {
            if (parent[u] != v) continue;
            sz[v] += sz[u];
            if (sz[u] > best) {
                best = sz[u];
                heavy[v] = u;
            }
            base[C[u]][v] += base[C[u]][u];
        }
    }

    vector<int> head(N + 1), tin(N + 1), rev(N + 1);
    int timer = 0;
    vector<pair<int, int>> st = {{1, 1}};

    while (!st.empty()) {
        auto [start, h] = st.back();
        st.pop_back();

        for (int v = start; v != 0; v = heavy[v]) {
            head[v] = h;
            tin[v] = ++timer;
            rev[timer] = v;

            for (int u : g[v]) {
                if (u == parent[v] || u == heavy[v]) continue;
                st.push_back({u, u});
            }
        }
    }

    vector<int> colorAt(N + 1);
    for (int v = 1; v <= N; v++) colorAt[tin[v]] = C[v];

    ColorSegTree seg;
    seg.build(colorAt);

    Fenwick fw[2] = {Fenwick(N), Fenwick(N)};

    auto path_add = [&](int a, int b, int c, long long val) {
        while (head[a] != head[b]) {
            fw[c].range_add(tin[head[b]], tin[b], val);
            b = parent[head[b]];
        }
        fw[c].range_add(tin[a], tin[b], val);
    };

    auto current_s = [&](int c, int v) {
        return base[c][v] + fw[c].sum(tin[v]);
    };

    auto nearest_bad = [&](int v, int c) {
        int x = v;
        while (x != 0) {
            int pos = seg.find_last_bad(tin[head[x]], tin[x], c);
            if (pos != -1) return rev[pos];
            x = parent[head[x]];
        }
        return 0;
    };

    auto child_below = [&](int anc, int v) {
        if (anc == 0) return 1;

        int x = v;
        while (head[x] != head[anc]) {
            if (parent[head[x]] == anc) return head[x];
            x = parent[head[x]];
        }
        return rev[tin[anc] + 1];
    };

    while (Q--) {
        int type, v;
        cin >> type >> v;

        if (type == 1) {
            int old = C[v];
            long long val = current_s(old, v);
            int bad = nearest_bad(v, old);

            if (parent[v] != 0) {
                int from = (bad == 0 ? 1 : bad);
                path_add(from, parent[v], old, -val);
            }

            C[v] ^= 1;
            seg.set_color(tin[v], C[v]);

            int now = C[v];
            val = current_s(now, v);
            bad = nearest_bad(v, now);

            if (parent[v] != 0) {
                int from = (bad == 0 ? 1 : bad);
                path_add(from, parent[v], now, val);
            }
        } else if (type == 2) {
            long long x;
            cin >> x;

            W[v] += x;
            int c = C[v];
            int bad = nearest_bad(v, c);
            int from = (bad == 0 ? 1 : bad);

            path_add(from, v, c, x);
            fw[c ^ 1].range_add(tin[v], tin[v], x);
        } else {
            int c = C[v];
            int bad = nearest_bad(v, c);
            int top = child_below(bad, v);
            cout << current_s(c, top) << '\n';
        }
    }

    return 0;
}
```

## 样例验证

代码维护两种颜色的子树方向同色 DP，并通过 HLD 查找连通块最高点。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
