# CF 1085 C - Connect Three

**题目链接**：<https://codeforces.com/contest/1085/problem/C>

**题型**：构造 / 网格连通

**难度**：1600（蓝）

---

## 题意

给出平面网格上的三个点，要求输出尽量少的格点，使得这三个点在输出的格点集合中两两连通。

连通只能通过上下左右相邻格点。

---

## 关键观察

三个点在曼哈顿网格上连通，最短的形状一定可以做成一棵“T”形树。

做法很简单：

1. 取三个点的 `x` 坐标中位数 `mx`；
2. 在 `x = mx` 这一列上，从最小 `y` 连到最大 `y`；
3. 每个原点再水平连到这一列。

这样不会绕路，并且中位数列保证水平总长度最小。

---

## 思路步骤

1. 读入三个点。
2. 找到三个 `x` 的中位数 `mx`。
3. 把竖线 `(mx, minY) ... (mx, maxY)` 全部加入答案。
4. 对每个点 `(x, y)`，把 `(min(x,mx), y) ... (max(x,mx), y)` 加入答案。
5. 用 `set` 去重后输出。

---

## 易错点

- 输出的是所有格点，不是边数。
- 横线和竖线交点会重复，必须去重。
- 取 `x` 的中位数或 `y` 的中位数都可以，这里固定取 `x` 的中位数。

---

## 复杂度

坐标范围很小，直接枚举路径即可。

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<int, int>> p(3);
    for (auto &[x, y] : p) cin >> x >> y;

    vector<int> xs;
    for (auto [x, y] : p) xs.push_back(x);
    sort(xs.begin(), xs.end());
    int mx = xs[1];

    int mnY = min({p[0].second, p[1].second, p[2].second});
    int mxY = max({p[0].second, p[1].second, p[2].second});

    set<pair<int, int>> ans;
    for (int y = mnY; y <= mxY; ++y) ans.insert({mx, y});

    for (auto [x, y] : p) {
        for (int xx = min(x, mx); xx <= max(x, mx); ++xx) {
            ans.insert({xx, y});
        }
    }

    cout << ans.size() << '\n';
    for (auto [x, y] : ans) cout << x << ' ' << y << '\n';
    return 0;
}
```

---

## 一句话总结

用三个点横向连到 `x` 坐标中位数列，再在这列上竖向连通，就是最短的网格连通树。
