#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
vector<int> dx = {0,0,1,-1};
vector<int> dy = {1,-1,0,0};
void solve() {
    int n,m;
    while(cin>>n>>m){
        vector<string> grid(n);
        rep(i,0,n)cin>>grid[i];
        vector<pair<int,int>> kfc;
        int a,b,c,d;

        rep(i,0,n)rep(j,0,m){
            if(grid[i][j]=='@'){
                kfc.push_back({i,j});
            }
            if(grid[i][j] == 'Y'){
                a= i;b =j;
            }
            if(grid[i][j] == 'M'){
                c= i;d=j;
            }

        }

        queue<pair<int,int>> q;
        q.push({a,b});
        vector<vector<int>> arr(n,vector<int> (m,-1));
        vector<vector<int>> brr(n,vector<int> (m,-1));

        arr[a][b] = 0;

        while(!q.empty()){
            auto start = q.front();
            q.pop();

            int x = start.first;
            int y = start.second;

            rep(i,0,4){
                int nx =x+dx[i];
                int ny =y+dy[i];

                if(nx<0||ny<0||nx>=n||ny>=m||grid[nx][ny]=='#'||arr[nx][ny]!=-1)continue;
                q.push({nx,ny});
                arr[nx][ny] = arr[x][y] +1;
            }
        }

        q.push({c,d});
        arr[c][d] = 0;

        while(!q.empty()){
            auto start = q.front();
            q.pop();

            int x = start.first;
            int y = start.second;

            rep(i,0,4){
                int nx =x+dx[i];
                int ny =y+dy[i];

                if(nx<0||ny<0||nx>=n||ny>=m||grid[nx][ny]=='#'||brr[nx][ny]!=-1)continue;
                q.push({nx,ny});
                brr[nx][ny] = brr[x][y] +1;
            }
        }
        int ans = LLONG_MAX;
        for(auto [i,j]:kfc){
           ans = min(ans,arr[i][j]+brr[i][j]);
        }
        cout << (ans+1)*11 <<endl;
        


        


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