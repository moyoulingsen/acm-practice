# ABC453 D - Go Straight

## 网址

https://atcoder.jp/contests/abc453/tasks/abc453_d

## 题解

当前位置本身不够描述状态，还需要知道上一手移动方向。定义状态 `(r, c, d)`：当前在 `(r,c)`，上一手方向为 `d`。

根据当前格子字符决定下一步方向：

- `.` / `S` / `G`：四个方向都可以；
- `o`：只能继续沿上一手方向；
- `x`：不能沿上一手方向。

从 `S` 的四种虚拟上一方向状态入队 BFS。首次到达 `G` 后用前驱数组恢复路径。

时间复杂度：`O(HW)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Prev {
    int v = -1;
    char move = 0;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    cin >> H >> W;

    vector<string> S(H);
    int sr = -1, sc = -1, gr = -1, gc = -1;

    for (int i = 0; i < H; i++) {
        cin >> S[i];
        for (int j = 0; j < W; j++) {
            if (S[i][j] == 'S') sr = i, sc = j;
            if (S[i][j] == 'G') gr = i, gc = j;
        }
    }

    const int dr[4] = {-1, 1, 0, 0};
    const int dc[4] = {0, 0, -1, 1};
    const char mv[4] = {'U', 'D', 'L', 'R'};

    auto id = [&](int r, int c, int d) {
        return ((r * W + c) * 4 + d);
    };

    int V = H * W * 4;
    vector<Prev> pre(V);
    queue<int> q;

    for (int d = 0; d < 4; d++) {
        int s = id(sr, sc, d);
        pre[s].v = -2;
        q.push(s);
    }

    int goal = -1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        int cell = cur / 4;
        int dprev = cur % 4;
        int r = cell / W;
        int c = cell % W;

        if (r == gr && c == gc) {
            goal = cur;
            break;
        }

        vector<int> dirs;
        char ch = S[r][c];
        if (ch == 'o') {
            dirs.push_back(dprev);
        } else if (ch == 'x') {
            for (int d = 0; d < 4; d++) {
                if (d != dprev) dirs.push_back(d);
            }
        } else {
            for (int d = 0; d < 4; d++) dirs.push_back(d);
        }

        for (int d : dirs) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
            if (S[nr][nc] == '#') continue;

            int nxt = id(nr, nc, d);
            if (pre[nxt].v != -1) continue;
            pre[nxt].v = cur;
            pre[nxt].move = mv[d];
            q.push(nxt);
        }
    }

    if (goal == -1) {
        cout << "No\n";
        return 0;
    }

    string ans;
    for (int v = goal; pre[v].v != -2; v = pre[v].v) ans.push_back(pre[v].move);
    reverse(ans.begin(), ans.end());

    cout << "Yes\n";
    cout << ans << '\n';
    return 0;
}
```

## 样例验证

```text
输入
3 5
.#...
.Sooo
..x.G

输出例
Yes
DRUUDDRR
```

说明：本题输出路径不唯一，只要输出合法路径即可。
