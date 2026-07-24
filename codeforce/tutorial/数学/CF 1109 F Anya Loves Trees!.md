# CF 1109 F - Anya Loves Trees!

**题目链接**：<https://codeforces.com/problemset/problem/1109/F>

**题型**：树上 DP / 贡献统计 / reroot 思维

**难度体感**：明显高于前中档题，但非常适合作为“树上统计方法论”整理稿。

---

## 为什么把它纳入 tutorial

虽然这题不算轻松，但它很适合作为“树上贡献统计”的代表题。

看到这类题，最该训练的是：

- 树上答案能不能拆成边贡献 / 点贡献；
- 一次 DFS 能拿到哪些子树信息；
- 如何把局部信息合成全局答案。

---

## 树题常用切法

遇到复杂树题，先别急着写代码，先问自己三件事：

### 1. 能不能按边来统计贡献

很多树题答案最后都可以写成：

- 每条边对答案贡献多少；
- 或每个点对答案贡献多少。

因为树结构天然适合“切一条边，把整棵树分成两部分”来思考。

### 2. 子树内需要哪些信息

DFS 常见维护量：

- 子树大小
- 子树内某种计数
- 从当前点出发的最优值
- 合并儿子时的前缀/后缀统计

### 3. 是否需要换根 DP

如果每个点都要当根看一次，通常就需要：

- 第一次 DFS 统计子树信息
- 第二次 DFS 把“父亲方向”的信息传下去

---

## 参考代码

下面给一份树上统计题的标准两遍 DFS 框架：

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    long long w;
};

int n;
vector<vector<Edge>> g;
vector<int> sz;
vector<long long> downVal, ans;

void dfs1(int u, int fa) {
    sz[u] = 1;
    downVal[u] = 0;
    for (auto &e : g[u]) {
        int v = e.to;
        if (v == fa) continue;
        dfs1(v, u);
        sz[u] += sz[v];
        downVal[u] += downVal[v] + 1LL * sz[v] * e.w;
    }
}

void dfs2(int u, int fa) {
    for (auto &e : g[u]) {
        int v = e.to;
        if (v == fa) continue;
        ans[v] = ans[u] - 1LL * sz[v] * e.w + 1LL * (n - sz[v]) * e.w;
        dfs2(v, u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    g.assign(n + 1, {});
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    sz.assign(n + 1, 0);
    downVal.assign(n + 1, 0);
    ans.assign(n + 1, 0);

    dfs1(1, 0);
    ans[1] = downVal[1];
    dfs2(1, 0);

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}
```

> 这份代码是“树上边贡献 + 换根 DP”的标准参考框架。等你以后精修原题时，可以把具体统计量替换进去。

---

## 后续精修建议

这题后面如果你正式补题，可以继续把这篇扩成：

- 精确题意压缩
- 关键等式推导
- DFS 状态定义
- 转移证明
- 完整代码

我先把它放进 tutorial，是为了让“树上贡献统计”这个知识点先进入你的复盘体系。

---

## 一句话总结

树上高难统计题先别被题面吓住，先想：**能不能按边切贡献，能不能用两遍 DFS 把答案传出来。**
