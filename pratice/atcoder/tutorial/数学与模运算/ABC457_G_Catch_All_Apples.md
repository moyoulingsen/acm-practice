# ABC457 G - Catch All Apples

## 网址

https://atcoder.jp/contests/abc457/tasks/abc457_g

## 题解

一个机器人能依次接住苹果 `i` 和 `j`（`T_i <= T_j`），当且仅当：

```text
|X_i - X_j| <= T_j - T_i
```

做坐标变换：

```text
u_i = T_i + X_i
v_i = T_i - X_i
```

则可达条件等价于二维偏序：

```text
u_i <= u_j 且 v_i <= v_j
```

问题变成：用最少条链覆盖所有点。根据 Dilworth 定理，最少链覆盖数等于最大反链大小。

将点按 `(u,v)` 排序后，反链对应 `v` 的最长严格下降子序列。实现时对 `-v` 求最长严格上升子序列即可。

时间复杂度：`O(N log N)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> points;
    points.reserve(N);

    for (int i = 0; i < N; i++) {
        int T, X;
        cin >> T >> X;

        int u = T + X;
        int v = T - X;
        points.push_back({u, v});
    }

    sort(points.begin(), points.end());

    vector<int> lis;

    for (auto [u, v] : points) {
        int x = -v;
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if (it == lis.end()) lis.push_back(x);
        else *it = x;
    }

    cout << lis.size() << '\n';
    return 0;
}
```

## 样例验证

```text
输入
4
0 2
1 0
2 1
2 3

输出
2
```

```text
输入
5
0 1
0 2
0 3
0 4
0 5

输出
5
```

```text
输入
8
10 4
4 2
7 10
5 3
1 9
0 6
3 8
0 9

输出
2
```
