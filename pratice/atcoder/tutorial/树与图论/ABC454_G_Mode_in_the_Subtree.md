# ABC454 G - Mode in the Subtree

## 网址

https://atcoder.jp/contests/abc454/tasks/abc454_g

## 题解

对每个点 `v`，需要知道其子树内：

- 最大颜色出现次数 `m_v`；
- 达到该最大次数的颜色数量 `k_v`。

最后求：

```text
sum (m_i xor i) * (k_i xor i) mod 998244353
```

`N` 很大，不能每个子树单独统计。使用 DSU on Tree：

1. 对每个点找子树最大的儿子作为重儿子；
2. 处理轻儿子后清空统计；
3. 处理重儿子后保留统计；
4. 把轻儿子的点重新加入统计表，再加入当前点。

维护数组：

- `cnt[color]`：当前统计表中某颜色出现次数；
- `freq[t]`：出现次数恰为 `t` 的颜色数量；
- `mx`：当前最大出现次数。

为避免递归爆栈，代码用显式栈实现。

时间复杂度：`O(N log N)` 级别，实际每个点被加入常数/轻重相关次数。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 998244353;
static const long long MASK = (1LL << 31) - 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, F;
    long long state;
    cin >> N >> state >> M >> F;

    vector<int> parent(N + 1), head(N + 1, -1), to(N), nxt(N);
    int ec = 0;

    auto add_edge = [&](int p, int v) {
        parent[v] = p;
        to[ec] = v;
        nxt[ec] = head[p];
        head[p] = ec++;
    };

    for (int i = 2; i <= M; i++) {
        int q;
        cin >> q;
        add_edge(q, i);
    }

    for (int i = M + 1; i <= N; i++) {
        int p = (int)(state % (i - 1)) + 1;
        add_edge(p, i);
        state = (state * 1103515245LL + 12345) & MASK;
    }

    vector<int> color(N + 1);
    for (int i = 1; i <= M; i++) cin >> color[i];

    for (int i = M + 1; i <= N; i++) {
        color[i] = (int)(state % F) + 1;
        state = (state * 1103515245LL + 12345) & MASK;
    }

    vector<int> sz(N + 1, 1), heavy(N + 1);

    for (int v = N; v >= 2; v--) {
        int p = parent[v];
        sz[p] += sz[v];
        if (heavy[p] == 0 || sz[v] > sz[heavy[p]]) heavy[p] = v;
    }

    vector<int> tin(N + 1), tout(N + 1), euler(N);
    vector<int> st;
    st.push_back(1);
    int timer = 0;

    while (!st.empty()) {
        int x = st.back();
        st.pop_back();

        if (x > 0) {
            int v = x;
            tin[v] = timer;
            euler[timer++] = v;

            st.push_back(-v);

            for (int e = head[v]; e != -1; e = nxt[e]) {
                int u = to[e];
                if (u != heavy[v]) st.push_back(u);
            }

            if (heavy[v]) st.push_back(heavy[v]);
        } else {
            tout[-x] = timer;
        }
    }

    vector<int> cnt(N + 1), freq(N + 1);
    int mx = 0;
    long long ans = 0;

    auto add_vertex = [&](int v) {
        int col = color[v];
        int old = cnt[col];
        if (old > 0) freq[old]--;
        cnt[col]++;
        freq[old + 1]++;
        mx = max(mx, old + 1);
    };

    auto reset_subtree = [&](int v) {
        for (int i = tin[v]; i < tout[v]; i++) cnt[color[euler[i]]] = 0;
        for (int f = 1; f <= mx; f++) freq[f] = 0;
        mx = 0;
    };

    struct Task {
        int v;
        unsigned char post;
        unsigned char keep;
    };

    vector<Task> tasks;
    tasks.push_back({1, 0, 1});

    while (!tasks.empty()) {
        Task cur = tasks.back();
        tasks.pop_back();

        int v = cur.v;

        if (!cur.post) {
            tasks.push_back({v, 1, cur.keep});

            if (heavy[v]) tasks.push_back({heavy[v], 0, 1});

            for (int e = head[v]; e != -1; e = nxt[e]) {
                int u = to[e];
                if (u != heavy[v]) tasks.push_back({u, 0, 0});
            }
        } else {
            int h = heavy[v];

            if (h) {
                for (int i = tout[h]; i < tout[v]; i++) add_vertex(euler[i]);
            }

            add_vertex(v);

            long long term = 1LL * ((mx ^ v) % MOD) * ((freq[mx] ^ v) % MOD) % MOD;
            ans += term;
            if (ans >= MOD) ans -= MOD;

            if (!cur.keep) reset_subtree(v);
        }
    }

    cout << ans % MOD << '\n';
    return 0;
}
```

## 样例验证

```text
输入
4 454 4 2
1 2 2
1 2 2 3

输出
29
```

```text
输入
6 123 2 2
1
1 2

输出
101
```

```text
输入
15 1 4 5
1 2 3
5 3 1 3

输出
1199
```
