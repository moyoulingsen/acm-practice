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

using vi = vector<int>;
using vii = vector<vi>;

int dx[4] {0,1,0,-1};
int dy[4] {1,0,-1,0};

bool isvalid(int x,int y,int n,vii &visited ){ //漏写了vii
    if (x>=0&&y>=0&&x<n&&y<n&& !visited[x][y]) return true;
    else return false;
}


void solve() {
    int n,x1,y1 ;
    cin>> n >> x1 >> y1;

    

    int x= 0,y=0,dir=0;
    int nx,ny;

    for(int i = 0;i<n*n;i++){
        if (x==x1-1 && y==y1-1) cout<<i+1;//赋值漏写了==
                                          //数组坐标和索引是有区别的！！！

        visited[x][y]=1;
        nx =x+dx[dir];
        ny =y+dy[dir];

        if(!isvalid(nx,ny,n,visited)){//检验的是状态转移
            dir =(dir+1)%4;
            nx =x+dx[dir];
            ny =y+dy[dir];
        }

        x =nx;
        y =ny;
        
        
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