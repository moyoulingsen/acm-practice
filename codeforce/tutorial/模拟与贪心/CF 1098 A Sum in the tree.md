# CF 1098 A - Sum in the tree

**题目链接**：<https://codeforces.com/problemset/problem/1098/A>

**题型**：树 / 贪心

---

## 题意压缩

给树上根到点的路径和 `s[v]`，部分为 `-1`，要求补全并最小化原点权和。

---

## 关键观察

`a[v]=s[v]-s[parent]` 必须非负。缺失点若有孩子，就把 `s[v]` 设为孩子 `s` 的最小值；叶子设为父亲的 `s`。

---

## 思路步骤

1. 建子节点表。
2. 补所有 `-1`。
3. 检查每条父子边差值非负并累加。

---

## 复杂度

`O(n)`。

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> p(n + 1);
    vector<vector<int>> ch(n + 1);
    for (int v = 2; v <= n; ++v) cin >> p[v], ch[p[v]].push_back(v);

    vector<long long> s(n + 1);
    for (int v = 1; v <= n; ++v) cin >> s[v];

    for (int v = 1; v <= n; ++v) {
        if (s[v] != -1) continue;
        if (ch[v].empty()) s[v] = s[p[v]];
        else {
            s[v] = LLONG_MAX;
            for (int to : ch[v]) s[v] = min(s[v], s[to]);
        }
    }

    long long ans = s[1];
    for (int v = 2; v <= n; ++v) {
        long long add = s[v] - s[p[v]];
        if (add < 0) return cout << -1 << '\n', 0;
        ans += add;
    }
    cout << ans << '\n';
    return 0;
}
```

---

## 一句话总结

缺失路径和补成孩子最小值，保证后续差值最小且非负。
