# ABC451 F - Make Bipartite 3

## 网址

https://atcoder.jp/contests/abc451/tasks/abc451_f

## 题解

二分图的每个连通分量有两种染色方式，互为黑白翻转。因此该连通分量对答案的贡献是：

```text
min(color0 的点数, color1 的点数)
```

总答案是所有连通分量贡献之和。

动态加边时，用带异或权的并查集维护：

- 每个点到所在连通分量根的颜色奇偶；
- 每个根下两种颜色的点数；
- 当前答案 `ans = sum min(cnt0, cnt1)`。

加入边 `(u, v)` 要求 `u` 和 `v` 颜色不同，即 `color(u) xor color(v) = 1`。

如果 `u, v` 已在同一连通分量内，检查奇偶是否满足；如果不满足，出现奇环，之后答案永久为 `-1`。否则合并两个连通分量并更新答案。

时间复杂度：`O((N+Q) α(N))`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, sz, xr;
    vector<array<int, 2>> cnt;
    long long ans = 0;

    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        xr.assign(n, 0);
        cnt.assign(n, {0, 0});

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            cnt[i][0] = 1;
        }
    }

    pair<int, int> find(int x) {
        if (parent[x] == x) return {x, 0};

        auto [r, val] = find(parent[x]);
        int nxr = xr[x] ^ val;
        parent[x] = r;
        xr[x] = nxr;
        return {parent[x], xr[x]};
    }

    bool add_edge(int u, int v) {
        auto [ru, xu] = find(u);
        auto [rv, xv] = find(v);

        if (ru == rv) return (xu ^ xv) == 1;

        ans -= min(cnt[ru][0], cnt[ru][1]);
        ans -= min(cnt[rv][0], cnt[rv][1]);

        if (sz[ru] < sz[rv]) {
            swap(ru, rv);
            swap(xu, xv);
        }

        int t = xu ^ xv ^ 1;
        parent[rv] = ru;
        xr[rv] = t;
        sz[ru] += sz[rv];

        array<int, 2> merged = cnt[ru];
        merged[0 ^ t] += cnt[rv][0];
        merged[1 ^ t] += cnt[rv][1];
        cnt[ru] = merged;

        ans += min(cnt[ru][0], cnt[ru][1]);
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    DSU dsu(N);
    bool ok = true;

    while (Q--) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;

        if (ok && !dsu.add_edge(u, v)) ok = false;

        if (!ok) cout << -1 << '\n';
        else cout << dsu.ans << '\n';
    }

    return 0;
}
```

## 样例验证

```text
输入
4 4
1 2
2 3
3 4
1 3

输出
1
1
2
-1
```

```text
输入
10 10
1 10
6 7
2 7
4 9
5 9
6 10
7 8
2 5
3 4
8 10

输出
1
2
2
3
3
3
3
4
4
4
```
