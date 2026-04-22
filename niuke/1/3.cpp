#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int a,b;
    cin>>a>>b;
    vector<string> grid(a);
    vector<pair<int,int>> q;

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    rep(i,0,a){
        cin>>grid[i];
        rep(j,0,b){
        if(grid[i][j]=='0'){
            q.push_back({i,j});
        }
        }
        
    }

    int cnt=0;
    for(auto [x,y]:q){
        rep(i,0,4){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx<a&&ny<b&&nx>=0&&ny>=0&&grid[nx][ny]=='1'){
                rep(j,0,4){
                    int nnx = nx+dx[j];
                int nny = ny+dy[j];
                if(nnx<a&&nny<b&&nnx>=0&&nny>=0&&grid[nnx][nny]=='2'&&j!=i)cnt++;
                }
                
            }
        }
        rep(i,0,4){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx<a&&ny<b&&nx>=0&&ny>=0&&grid[nx][ny]=='2'){
                rep(j,0,4){
                    int nnx = nx+dx[j];
                int nny = ny+dy[j];
                if(nnx<a&&nny<b&&nnx>=0&&nny>=0&&grid[nnx][nny]=='1'&&j!=i)cnt++;
                }
                
            }
        }
    }
    cout<<cnt;

    
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