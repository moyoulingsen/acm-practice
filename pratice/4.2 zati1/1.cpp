#include <bits/stdc++.h>
using namespace std;

int M, N;
vector<vector<int>> grid, bestFlip;
int minSteps = INT_MAX;

void applyFlip(vector<vector<int>>& g, int x, int y) {
    // 翻转 (x,y) 及其上下左右
    g[x][y] ^= 1;
    if (x > 0) g[x-1][y] ^= 1;
    if (x < M-1) g[x+1][y] ^= 1;
    if (y > 0) g[x][y-1] ^= 1;
    if (y < N-1) g[x][y+1] ^= 1;
}

void solve() {
    cin >> M >> N;
    grid.assign(M, vector<int>(N));
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> grid[i][j];

    // 枚举第一行的翻转状态（二进制）
    for (int mask = 0; mask < (1 << N); mask++) {
        vector<vector<int>> cur = grid;
        vector<vector<int>> flip(M, vector<int>(N, 0));
        int steps = 0;

        // 按 mask 翻转第一行
        for (int j = 0; j < N; j++) {
            if (mask >> j & 1) {
                applyFlip(cur, 0, j);
                flip[0][j] = 1;
                steps++;
            }
        }

        // 递推下面各行
        for (int i = 1; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (cur[i-1][j] == 1) { // 上一行还有 1，必须由当前行翻转
                    applyFlip(cur, i, j);
                    flip[i][j] = 1;
                    steps++;
                }
            }
        }

        // 检查最后一行是否全 0
        bool ok = true;
        for (int j = 0; j < N; j++)
            if (cur[M-1][j] == 1) { ok = false; break; }

        if (ok && steps < minSteps) {
            minSteps = steps;
            bestFlip = flip;
        }
    }

    if (minSteps == INT_MAX) cout << "IMPOSSIBLE\n";
    else {
        for (auto& row : bestFlip) {
            for (int v : row) cout << v << ' ';
            cout << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
