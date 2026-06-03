#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <array>

using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

vector<int> dx ={0,0,1,1,1,-1,-1,-1};
vector<int> dy ={1,-1,1,0,-1,1,0,-1};

void solve() {
    int n,m;
    while(cin>>n>>m){
        if(n==0&&m==0)break;

        vector<string> grid(n);
        rep(i,0,n)cin>>grid[i];

        vector<vector<int>> num(n,vector<int> (m,-1));
        int ans = 0;

        rep(i,0,n)rep(j,0,m){
            queue<pair<int,int>> q;

            if(grid[i][j] == '@' && num[i][j]==-1){
                ans++;
                num[i][j] = 0;
                q.push({i,j});

                while(!q.empty()){
                    auto start = q.front();
                    int x = start.first;
                    int y = start.second;
                    q.pop();

                    

                    rep(i,0,8){
                        int nx = x+dx[i];
                        int ny = y+dy[i];

                        if(nx>=n||ny>=m||nx<0||ny<0||grid[nx][ny] == '*'||num[nx][ny]!=-1)continue;

                        q.push({nx,ny});
                        num[nx][ny] = 0;



                    } 
                }

                

            }


        }
        cout<<ans<<endl;

    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}

// The GeoSurvComp geologic survey company is responsible for detecting underground oil deposits. GeoSurvComp works with one large rectangular region of land at a time, and creates a grid that divides the land into numerous square plots. It then analyzes each plot separately, using sensing equipment to determine whether or not the plot contains oil. A plot containing oil is called a pocket. If two pockets are adjacent, then they are part of the same oil deposit. Oil deposits can be quite large and may contain numerous pockets. Your job is to determine how many different oil deposits are contained in a grid.
// Input
// The input file contains one or more grids. Each grid begins with a line containing m and n, the number of rows and columns in the grid, separated by a single space. If m = 0 it signals the end of the input; otherwise 1 <= m <= 100 and 1 <= n <= 100. Following this are m lines of n characters each (not counting the end-of-line characters). Each character corresponds to one plot, and is either `*', representing the absence of oil, or `@', representing an oil pocket.
// Output
// For each grid, output the number of distinct oil deposits. Two different pockets are part of the same oil deposit if they are adjacent horizontally, vertically, or diagonally. An oil deposit will not contain more than 100 pockets.
// 1 1
// *
// 3 5
// *@*@*
// **@**
// *@*@*
// 1 8
// @@****@*
// 5 5 
// ****@
// *@@*@
// *@**@
// @@@*@
// @@**@
// 0 0 
