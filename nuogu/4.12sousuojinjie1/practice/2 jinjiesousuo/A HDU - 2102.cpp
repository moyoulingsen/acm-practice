// 可怜的公主在一次次被魔王掳走一次次被骑士们救回来之后，而今，不幸的她再一次面临生命的考验。魔王已经发出消息说将在T时刻吃掉公主，因为他听信谣言说吃公主的肉也能长生不老。年迈的国王正是心急如焚，告招天下勇士来拯救公主。不过公主早已习以为常，她深信智勇的骑士LJ肯定能将她救出。
// 现据密探所报，公主被关在一个两层的迷宫里，迷宫的入口是S（0，0，0），公主的位置用P表示，时空传输机用#表示，墙用*表示，平地用.表示。骑士们一进入时空传输机就会被转到另一层的相对位置，但如果被转到的位置是墙的话，那骑士们就会被撞死。骑士们在一层中只能前后左右移动，每移动一格花1时刻。层间的移动只能通过时空传输机，且不需要任何时间。
// Input
// 输入的第一行C表示共有C个测试数据，每个测试数据的前一行有三个整数N，M，T。 N，M迷宫的大小N*M（1 <= N,M <=10)。T如上所意。接下去的前N*M表示迷宫的第一层的布置情况，后N*M表示迷宫第二层的布置情况。
// Output
// 如果骑士们能够在T时刻能找到公主就输出“YES”，否则输出“NO”。
// Sample
// Input复制	Output复制
// 1
// 5 5 14
// S*#*.
// .#...
// .....
// ****.
// ...#.

// ..*.P
// #.*..
// ***..
// ...*.
// *.#..

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