# CF 1085 D - Boxed Like a Fish

**真实题号**：CF 2207 D

**题目链接**：<https://codeforces.com/problemset/problem/2207/D>

**题型**：树形 DP / 博弈 / 最短距离

**难度体感**：2200，关键是把追逃博弈转成“到必胜点的最近距离”。

---

## 题意压缩

给定一棵树、参数 `k` 和起点 `v`。

题目可以看成一个树上的追逃/博弈过程：某些位置对先手来说是必胜的，问从 `v` 开始先手能不能保证胜利。

---

## 关键定义

以起点 `v` 为根。

把“Cyndaquil 一旦到达就一定能赢”的点叫做**必胜点**。

定义：

```text
dp[u] = 从 u 往子树里走，到最近必胜点的距离
```

如果 `u` 本身就是必胜点，那么 `dp[u]=0`。

---

## 叶子为什么是必胜点

叶子没有继续向下绕开的选择。

到达叶子后，局面会被固定下来，所以叶子可以作为基础必胜点：

```text
dp[leaf] = 0
```

---

## 非叶子怎么转移

对点 `u`，看所有儿子 `to` 的：

```text
dp[to] + 1
```

表示从 `u` 走向这个儿子方向，最近必胜点的距离。

取其中最小的两个值：

- `best1`
- `best2`

如果只有一个儿子，那么：

```text
dp[u] = best1
```

如果至少有两个方向，并且两个最近必胜方向距离足够近：

\[
best1 + best2 - 1 \le k
\]

等价于代码里使用的：

\[
(dp_1)+(dp_2) < k
\]

那么 `u` 本身也能成为必胜点，令：

```text
dp[u] = 0
```

否则：

```text
dp[u] = best1
```

---

## 为什么看两个最小值

如果一个点下面有两个足够近的必胜方向，那么对手无法同时防住两个方向。

先手可以借助这两个分支形成夹击，所以当前点也变成必胜点。

如果做不到，就只能继承最近那个必胜点的距离。

---

## 思路步骤

1. 以 `v` 为根建树。
2. 按后序顺序处理节点。
3. 叶子 `dp=0`。
4. 非叶子取儿子的两个最小 `dp+1`。
5. 根据 `best1+best2-1<=k` 判断当前点是否变成必胜点。
6. 最后判断 `dp[v]==0`。

---

## 复杂度

每条边只处理常数次：

\[
O(n)
\]

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, k, v;
        cin >> n >> k >> v;

        vector<vector<int>> g(n + 1);
        for (int i = 1; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        vector<int> parent(n + 1, 0), order;
        order.reserve(n);

        stack<int> st;
        st.push(v);
        parent[v] = -1;

        while (!st.empty()) {
            int u = st.top();
            st.pop();
            order.push_back(u);

            for (int to : g[u]) {
                if (to == parent[u]) continue;
                parent[to] = u;
                st.push(to);
            }
        }

        vector<int> dp(n + 1, INF);

        for (int idx = (int)order.size() - 1; idx >= 0; --idx) {
            int u = order[idx];

            int best1 = INF, best2 = INF;
            bool leaf = true;

            for (int to : g[u]) {
                if (parent[to] != u) continue;
                leaf = false;

                int val = dp[to];
                if (val < best1) {
                    best2 = best1;
                    best1 = val;
                } else if (val < best2) {
                    best2 = val;
                }
            }

            if (leaf) {
                dp[u] = 0;
            } else if (best2 == INF) {
                dp[u] = best1 + 1;
            } else {
                dp[u] = best1 + 1;
                if (best1 + best2 < k) {
                    dp[u] = 0;
                }
            }
        }

        cout << (dp[v] == 0 ? "YES" : "NO") << '\n';
    }
    return 0;
}
```

---

## 一句话总结

这题就是：**树形 DP 维护到最近必胜点的距离，如果两个必胜分支足够近，当前点也变成必胜点。**
