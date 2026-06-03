#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};

void solve()
{
    vector<vector<int>> map(5, vector<int>(5));
    rep(i, 0, 5) rep(j, 0, 5)
    {
        cin >> map[i][j];
    }

    queue<pair<int, int>> q;
    q.push({0, 0});

    struct Node
    {
        int an, bn, step;
    };

    vector<vector<Node>> vis(5, vector<Node>(5, {0, 0, -1}));
    vis[0][0] = {-1, -1, 0};

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        int x = cur.first;
        int y = cur.second;

        if (x == 4 && y == 4)
        {
            break;
        }

        rep(i, 0, 4)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5 || vis[nx][ny].step != -1 || map[nx][ny] == 1)
                continue;
            q.push({nx, ny});
            vis[nx][ny] = {x, y, vis[x][y].step + 1};
        }
    }

    vector<pair<int, int>> ans;
    int a = 4;
    int b = 4;
    while (vis[a][b].an != -1 && vis[a][b].bn != -1)
    {
        ans.push_back({a, b});
        int c = a;
        int d = b;
        a = vis[c][d].an;
        b = vis[c][d].bn;
    }
    ans.push_back({0, 0});

    reverse(ans.begin(), ans.end());
    rep(i, 0, ans.size()) cout << "(" << ans[i].first << ", " << ans[i].second << ")\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}