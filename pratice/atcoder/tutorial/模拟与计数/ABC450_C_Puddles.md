# ABC450 C - Puddles

## 网址

https://atcoder.jp/contests/abc450/tasks/abc450_c

## 题解

对每个未访问过的白格做 BFS/DFS，遍历整个白色四连通块。遍历时记录这个连通块是否碰到了网格边界。如果没有碰到边界，答案加一。

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

    vector<string> S(H);
    for (auto &row : S) cin >> row;

    vector<vector<int>> vis(H, vector<int>(W));
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    int ans = 0;

    for (int si = 0; si < H; si++) {
        for (int sj = 0; sj < W; sj++) {
            if (S[si][sj] != '.' || vis[si][sj]) continue;

            bool touch = false;
            queue<pair<int, int>> q;
            q.push({si, sj});
            vis[si][sj] = 1;

            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();

                if (r == 0 || r == H - 1 || c == 0 || c == W - 1) touch = true;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if (nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
                    if (S[nr][nc] != '.' || vis[nr][nc]) continue;
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }

            if (!touch) ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}
```

## 样例验证

代码是标准 Flood Fill，会完整访问每个白色连通块并判断是否触边。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
