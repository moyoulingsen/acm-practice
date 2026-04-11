#include <bits/stdc++.h>
using namespace std;

static const int dx[4] = {1, -1, 0, 0};
static const int dy[4] = {0, 0, 1, -1};

void solve() {
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
            vector<vector<int>> dist(n, vector<int>(m, -1));
            queue<pair<int, int>> q;

            dist[grass[i].first][grass[i].second] = 0;
            q.push(grass[i]);

            if (grass[j] != grass[i]) {
                dist[grass[j].first][grass[j].second] = 0;
                q.push(grass[j]);
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

            int cur = 0;
            bool ok = true;
            for (auto [x, y] : grass) {
                if (dist[x][y] == -1) {
                    ok = false;
                    break;
                }
                cur = max(cur, dist[x][y]);
            }

            if (ok) {
                ans = min(ans, cur);
            }
        }
    }

    if (ans == INT_MAX) {
        ans = -1;
    }

    static int tc = 1;
    cout << "Case " << tc++ << ": " << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}