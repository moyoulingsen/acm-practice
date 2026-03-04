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

   const int MAXI =405;//注意数组必须是常量作为大小，大写只是默认
   int grid[MAXI][MAXI];//这个就是答案储存了
                      //max 就是函数了，要用大写写常量
   int visited[MAXI][MAXI]={0};
   struct Node {int x,y,step;};
   queue<Node> q;//结构体在这里,不是啥都是int

   int dx[8] ={1,2,1,2,-1,-1,-2,-2};
   int dy[8]={2,1,-2,-1,2,-2,-1,1};

 void bfs (int m,int n,int x,int y){
        int x1,y1;
        q.push({x,y,0});
        visited[x][y] = true;
        grid[x][y]=0;

        
        while(!q.empty()){
            Node cur = q.front();//front是函数
            q.pop();





            for (int i =0;i<8;i++){

            x1 = cur.x + dx[i];
            y1 = cur.y + dy[i];




                if (x1>=0 && y1>=0 && x1<m && y1<n&&!visited[x1][y1])//边界条件永远的坑
                {
                visited[x1][y1] = true;
                grid[x1][y1] = cur.step+1;
                q.push({x1,y1,cur.step+1});
                }
            }
       }
   }

void solve() {

   int m,n,x,y;
   cin>>m>>n>>x>>y;

   memset(grid,-1,sizeof(grid));
   bfs(m,n,x-1,y-1);

   for (int ii = 0;ii <m;ii++){
    for(int iii = 0 ;iii <n;iii++){
        cout << grid[ii][iii] <<  " ";//你写的是什么？
    }
    cout << "\n";//是\n
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