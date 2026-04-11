#include <bits/stdc++.h>
using namespace std;

static const int dx[4] = {1, -1, 0, 0};
static const int dy[4] = {0, 0, 1, -1};

int bfs_time(const vector<string>& grid, const vector<pair<int, int>>& grass,
             pair<int, int> s1, pair<int, int> s2) {
    int n = (int)grid.size();
    int m = (int)grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;

    dist[s1.first][s1.second] = 0;
    q.push(s1);
    if (s2 != s1) {
        dist[s2.first][s2.second] = 0;
        q.push(s2);
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if (grid[nx][ny] != '#' || dist[nx][ny] != -1) {
                continue;
            }
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    int mx = 0;
    for (auto [x, y] : grass) {
        if (dist[x][y] == -1) {
            return -1;
        }
        mx = max(mx, dist[x][y]);
    }
    return mx;
}

void solve(int tc) {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<pair<int, int>> grass;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#') {
                grass.push_back({i, j});
            }
        }
    }

    int ans = INT_MAX;
    int k = (int)grass.size();
    for (int i = 0; i < k; i++) {
        for (int j = i; j < k; j++) {
            int cur = bfs_time(grid, grass, grass[i], grass[j]);
            if (cur != -1) {
                ans = min(ans, cur);
            }
        }
    }

    if (ans == INT_MAX) {
        ans = -1;
    }
    cout << "Case " << tc << ": " << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }
    return 0;
}
