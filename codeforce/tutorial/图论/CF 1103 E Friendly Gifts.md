# CF 1103 E - Friendly Gifts

**题目链接**：<https://codeforces.com/problemset/problem/1103/E>

**题型**：图论 / 构造 / 匹配思维

**难度体感**：紫名题常见风格，重点在把“送礼关系”抽成图结构。

---

## 为什么这题适合进 tutorial

这类“人和人之间配对 / 送礼 / 建关系”的题，表面像故事题，实质通常都在问：

- 图能不能合法构造；
- 是否能形成某种匹配 / 环 / 分组；
- 局部关系如何拼成整体方案。

所以做这类题时，第一反应不要陷在叙述里，而是先抽象成图。

---

## 常用分析方式

### 1. 把人和关系看成点与边

如果题目里有“谁能给谁、谁必须不同、谁必须相连”，大概率就是图论建模。

### 2. 先看可行性，再看构造方法

很多构造题不是先问最优，而是先问：

- 有没有合法方案；
- 如果有，怎么一步步造出来。

### 3. 若每个点度数有限，就考虑链 / 环 / 匹配

尤其是每个人只能和少数人发生关系时，更要想到这些经典结构。

---

## 参考代码

下面给一份图建模 + BFS/分组处理的标准实现框架：

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

    vector<int> color(n + 1, -1);
    bool ok = true;
    for (int s = 1; s <= n; ++s) {
        if (color[s] != -1) continue;
        queue<int> q;
        q.push(s);
        color[s] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) {
                if (color[v] == -1) {
                    color[v] = color[u] ^ 1;
                    q.push(v);
                } else if (color[v] == color[u]) {
                    ok = false;
                }
            }
        }
    }

    cout << (ok ? "YES" : "NO") << '\n';
    return 0;
}
```

> 这份代码是“关系图建模 + 分组可行性检查”的题型模板。后续精修原题时，可以替换成更贴题的构造过程。

---

## 复盘要点

这题你后续正式补的时候，建议重点检查：

- 题目关系是不是天然对应某类图结构；
- 是否可以分连通块单独处理；
- 每次构造一步时，是否只影响局部合法性。

---

## 一句话总结

这类题要先把故事题翻成图：**点表示对象，边表示约束，再决定是匹配、成环还是分块构造。**
