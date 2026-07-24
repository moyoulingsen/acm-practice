# CF 1106 D Lunar New Year and a Wander

**题目链接**：<https://codeforces.com/problemset/problem/1106/D>

**题型**：图论 / 贪心 / 优先队列

**难度体感**：1500 左右的好题，关键是“每一步选当前能到的最小编号点”。

---

## 题意压缩

给一张无向图，从点 `1` 出发遍历。要求输出一种遍历顺序，使得：

- 每次只能去当前已访问点连出去的新点；
- 在所有可选点里，总是尽量选编号最小的那个。

---

## 关键观察

这其实就是：

- 图上的“最小字典序扩展”；
- 每次把当前能访问到的新点放进一个最小堆；
- 然后弹出最小编号继续扩展。

所以和 BFS/Prim 的写法很像。

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> vis(n + 1, 0);
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1);

    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        cout << u << ' ';
        for (int v : g[u]) if (!vis[v]) pq.push(v);
    }
    cout << '\n';
    return 0;
}
```

---

## 一句话总结

这题本质是：**每一步都从当前可达点中取编号最小的那个。**
