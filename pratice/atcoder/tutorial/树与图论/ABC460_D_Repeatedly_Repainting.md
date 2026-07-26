# ABC460 D - Repeatedly Repainting

## 网址

https://atcoder.jp/contests/abc460/tasks/abc460_d

## 题解

给定黑白网格，反复执行重涂操作很多次。操作基于八邻域，因此可以把重涂后的扩散过程看成从黑格出发的最短距离奇偶。

官方结论：先模拟一次操作，得到网格 `B`。之后以 `B` 中所有黑格为源点做八方向多源 BFS，设每个格子到最近黑格的距离为 `dist`。因为剩余操作次数 `10^100 - 1` 是奇数，最终颜色只由距离奇偶决定：

- `dist` 为偶数：白色 `.`；
- `dist` 为奇数：黑色 `#`。

第一步模拟时，按题意用原网格判断每个格子的八邻域状态，不能原地更新。

时间复杂度：`O(HW)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    cin >> H >> W;

    vector<string> A(H);
    for (auto &s : A) cin >> s;

    const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    vector<string> B = A;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            bool hasBlack = false;
            for (int dir = 0; dir < 8; dir++) {
                int ni = i + dx[dir];
                int nj = j + dy[dir];
                if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
                if (A[ni][nj] == '#') hasBlack = true;
            }
            B[i][j] = hasBlack ? '#' : '.';
        }
    }

    const int INF = 1e9;
    vector<vector<int>> dist(H, vector<int>(W, INF));
    queue<pair<int, int>> q;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (B[i][j] == '#') {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int dir = 0; dir < 8; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (dist[nx][ny] != INF) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << (dist[i][j] % 2 == 0 ? '.' : '#');
        }
        cout << '\n';
    }

    return 0;
}
```

## 样例验证

代码先完成一次同步重涂，再用多源 BFS 的距离奇偶决定最终颜色。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
