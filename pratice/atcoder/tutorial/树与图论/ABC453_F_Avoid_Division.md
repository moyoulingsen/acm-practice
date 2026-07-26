# ABC453 F - Avoid Division

## 网址

https://atcoder.jp/contests/abc453/tasks/abc453_f

## 题解

关键看叶子。若某个叶子颜色只出现一次，切掉它相邻的边时，叶子单独成块，另一块没有同色点，必然不合法。所以每个叶子必须染一种最终至少出现两次的颜色。

判无解：

- `N=2`：两个点必须同色，需要存在某个 `C_i >= 2`；
- `N>=3`：设叶子数为 `L`，若所有容量 `C_i >= 2` 的颜色容量总和小于 `L`，无解。

构造时找一个非叶点 `X`，使删掉 `X` 后每个连通块中的原树叶子数都不超过 `L/2`。然后按这些连通块给叶子分组，用容量至少 2 的颜色给不同组的叶子配对染色，保证同色点分布在切边两侧。剩余非叶点用剩余容量随便填。

时间复杂度：`O(N log N + K)` 每组测试。

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
        int N, K;
        cin >> N >> K;

        vector<vector<int>> g(N);
        for (int i = 0; i < N - 1; i++) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> C(K);
        for (int &x : C) cin >> x;

        if (N == 2) {
            int color = -1;
            for (int i = 0; i < K; i++) {
                if (C[i] >= 2) color = i;
            }

            if (color == -1) cout << -1 << '\n';
            else cout << color + 1 << ' ' << color + 1 << '\n';
            continue;
        }

        int leaf_count = 0;
        for (int i = 0; i < N; i++) {
            if ((int)g[i].size() == 1) leaf_count++;
        }

        long long usable = 0;
        for (int x : C) {
            if (x >= 2) usable += x;
        }

        if (usable < leaf_count) {
            cout << -1 << '\n';
            continue;
        }

        vector<int> parent(N, -2), order;
        parent[0] = -1;
        order.push_back(0);

        for (int qi = 0; qi < (int)order.size(); qi++) {
            int v = order[qi];
            for (int to : g[v]) {
                if (to == parent[v]) continue;
                parent[to] = v;
                order.push_back(to);
            }
        }

        vector<int> sub_leaf(N);
        for (int v = 0; v < N; v++) sub_leaf[v] = ((int)g[v].size() == 1);

        for (int i = N - 1; i >= 0; i--) {
            int v = order[i];
            for (int to : g[v]) {
                if (parent[to] == v) sub_leaf[v] += sub_leaf[to];
            }
        }

        int X = -1;
        for (int v = 0; v < N; v++) {
            if ((int)g[v].size() == 1) continue;

            int mx = 0;
            for (int to : g[v]) {
                int part;
                if (parent[to] == v) part = sub_leaf[to];
                else part = leaf_count - sub_leaf[v];
                mx = max(mx, part);
            }

            if (mx * 2 <= leaf_count) {
                X = v;
                break;
            }
        }

        vector<vector<int>> groups;
        for (int nb : g[X]) {
            vector<int> leaves;
            vector<pair<int, int>> st;
            st.push_back({nb, X});

            while (!st.empty()) {
                auto [v, p] = st.back();
                st.pop_back();

                if ((int)g[v].size() == 1) leaves.push_back(v);

                for (int to : g[v]) {
                    if (to != p) st.push_back({to, v});
                }
            }

            groups.push_back(leaves);
        }

        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < (int)groups.size(); i++) {
            if (!groups[i].empty()) pq.push({(int)groups[i].size(), i});
        }

        vector<int> ans(N, -1);
        int rem = leaf_count;

        auto take_leaf = [&](int color) {
            auto [cnt, gid] = pq.top();
            pq.pop();

            int v = groups[gid][cnt - 1];
            ans[v] = color;
            cnt--;
            rem--;

            if (cnt > 0) pq.push({cnt, gid});
        };

        for (int color = 0; color < K && rem > 0; color++) {
            if (C[color] <= 1) continue;

            if (rem == 1) {
                take_leaf(color);
                C[color]--;
                ans[X] = color;
                C[color]--;
                break;
            }

            if (rem <= C[color]) {
                while (rem > 0) {
                    take_leaf(color);
                    C[color]--;
                }
                break;
            }

            auto [cnt1, gid1] = pq.top();
            pq.pop();
            auto [cnt2, gid2] = pq.top();
            pq.pop();

            ans[groups[gid1][cnt1 - 1]] = color;
            cnt1--;
            rem--;

            ans[groups[gid2][cnt2 - 1]] = color;
            cnt2--;
            rem--;

            if (cnt1 > 0) pq.push({cnt1, gid1});
            if (cnt2 > 0) pq.push({cnt2, gid2});

            C[color] -= 2;

            while (C[color] > 0) {
                take_leaf(color);
                C[color]--;
            }
        }

        if (rem > 0) {
            cout << -1 << '\n';
            continue;
        }

        int cur = 0;
        for (int v = 0; v < N; v++) {
            if (ans[v] == -1) {
                while (cur < K && C[cur] == 0) cur++;
                ans[v] = cur;
                C[cur]--;
            }
        }

        for (int i = 0; i < N; i++) {
            if (i) cout << ' ';
            cout << ans[i] + 1;
        }
        cout << '\n';
    }

    return 0;
}
```

## 样例验证

```text
输入
2
5 3
1 2
1 3
2 4
2 5
2 2 2
3 3
1 2
2 3
1 1 1

输出例
3 2 2 1 1
-1
```

说明：本题合法染色不唯一，代码输出可能与样例不同，只需满足条件。
