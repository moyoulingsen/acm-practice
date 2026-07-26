# ABC451 E - Tree Distance

## 网址

https://atcoder.jp/contests/abc451/tasks/abc451_e

## 题解

如果给定距离矩阵来自一棵带正权树，那么以点 `1` 为根时，每个点的父亲可以由距离关系确定。

对于点 `i != 1`，点 `j` 在根到 `i` 的路径上当且仅当：

```text
A[1][j] + A[j][i] = A[1][i]
```

在所有满足条件的 `j` 中，距离 `i` 最近的那个点就是 `i` 的父亲。构造出候选树后，再从每个点 DFS 一遍，验证树上距离是否与输入矩阵完全一致。

时间复杂度：`O(N^2)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> A(N, vector<int>(N));

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            cin >> A[i][j];
            A[j][i] = A[i][j];
        }
    }

    vector<vector<pair<int, int>>> g(N);

    for (int i = 1; i < N; i++) {
        int parent = -1;
        int bestDist = INT_MAX;

        for (int j = 0; j < N; j++) {
            if (j == i) continue;

            if ((long long)A[0][j] + A[j][i] == A[0][i]) {
                if (A[j][i] < bestDist) {
                    bestDist = A[j][i];
                    parent = j;
                }
            }
        }

        if (parent == -1) {
            cout << "No\n";
            return 0;
        }

        g[i].push_back({parent, bestDist});
        g[parent].push_back({i, bestDist});
    }

    for (int s = 0; s < N; s++) {
        vector<long long> dist(N, -1);
        stack<int> st;
        dist[s] = 0;
        st.push(s);

        while (!st.empty()) {
            int v = st.top();
            st.pop();

            for (auto [to, w] : g[v]) {
                if (dist[to] == -1) {
                    dist[to] = dist[v] + w;
                    st.push(to);
                }
            }
        }

        for (int t = 0; t < N; t++) {
            if (dist[t] != A[s][t]) {
                cout << "No\n";
                return 0;
            }
        }
    }

    cout << "Yes\n";
    return 0;
}
```

## 样例验证

```text
输入
4
2 5 4
3 2
5

输出
Yes
```

```text
输入
4
2 5 4
3 2
6

输出
No
```
