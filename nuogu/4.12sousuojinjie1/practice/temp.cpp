#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve()
{
    int n, m, t;
    cin >> n >> m >> t;

    vector<string> up(n);
    rep(i, 0, n) cin >> up[i];

    vector<string> down(n);
    rep(i, 0, n) cin >> down[i];

    vector<vector<int>> vis(n, vector<int>(m, -1));
    vector<vector<int>> viss(n, vector<int>(m, -1));
    struct Node
    {
        int x, y, z;
    };
    queue<Node> q;
    q.push({0, 0, 0});
    vis[0][0] = 0;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int cnt = 0;

    while (!q.empty())
    {
        auto start = q.front();
        q.pop();
        int x = start.x;
        int y = start.y;
        int z = start.z;

        if (z == 0)
        {
            if (up[x][y] == 'P'){
                cnt  = vis[x][y]; 
            }
                
            if (up[x][y] == '.' || up[x][y] == 'S')
            {
                rep(i, 0, 4)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx < 0 || ny < 0 || nx >= n || ny >= m || up[nx][ny] == '*' || vis[nx][ny] != -1)
                        continue;
                    q.push({nx, ny, 0});
                    vis[nx][ny] = vis[x][y] + 1;
                }
            }
            else
            {
                rep(i, 0, 4)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx < 0 || ny < 0 || nx >= n || ny >= m || up[nx][ny] == '*' || vis[nx][ny] != -1)
                        continue;
                    q.push({nx, ny, 0});
                    vis[nx][ny] = vis[x][y] + 1;
                }
                if (down[x][y] != '*')
                {
                    q.push({x, y, 1});
                    viss[x][y] = vis[x][y];
                }
            }
        }
        else
        {
            if (down[x][y] == 'P'){
                cnt = viss[x][y];
            }
                

            if (down[x][y] == '.' || down[x][y] == 'S')
            {
                rep(i, 0, 4)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx < 0 || ny < 0 || nx >= n || ny >= m || down[nx][ny] == '*' || viss[nx][ny] != -1)
                        continue;
                    q.push({nx, ny, 1});
                    viss[nx][ny] = viss[x][y] + 1;
                }
            }
            else
            {
                rep(i, 0, 4)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx < 0 || ny < 0 || nx >= n || ny >= m || down[nx][ny] == '*' || viss[nx][ny] != -1)
                        continue;
                    q.push({nx, ny, 1});
                    viss[nx][ny] = viss[x][y] + 1;
                }
                if (up[x][y] != '*')
                {
                    q.push({x, y, 0});
                    vis[x][y] = viss[x][y];
                }
            }
        }
    }
    cout<<(cnt<=t?"YES\n":"NO\n");
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}
