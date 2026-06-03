#include <bits/stdc++.h>

#if __has_include("tool/local.hpp")
    #include "tool/local.hpp"
#else
    #define debug(...) 42
#endif

using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using f80 = long double;
using pii = pair<int, int>;
using pll = pair<i64, i64>;

constexpr int INF = 1e9 + 7;
constexpr i64 INF64 = 4e18;

int dx[8]{1,1,1,-1,-1,-1,0,0};
int dy[8]{1,0,-1,1,0,-1,1,-1};

int count(int n,int m, int x,int y,vector<string> &grid){
    int cnt = 0;
    int nx,ny;

    for(int i = 0;i<8;i++){
        nx = x+dx[i];
        ny = y+dy[i];//这周末防？？？
        if (nx>=0&&nx<n&&ny>=0&&ny<m && grid[nx][ny]=='*')cnt++;
    }


    return cnt;
}

void solve() {
    int n,m;
    cin >> n>>m;

    vector<string> grid(n);
    for(int i= 0;i<n;i++){
        cin>>grid[i];
    }
    
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='*') {cout<<'*';continue;}
            cout<< count (n,m,i,j,grid);
        }
        cout<<"\n";
    }
    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        (void)!freopen("data.in", "r", stdin);
        (void)!freopen("data.out", "w", stdout);
    #endif

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}