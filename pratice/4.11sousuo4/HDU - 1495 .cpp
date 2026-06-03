#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int a,n,m;
    while(cin>>a>>n>>m){
        if(a==0&&n==0&&m==0)break;

        if (a % 2) {
    cout << "NO\n";
    continue;
}//////////////剪枝必须

        vector<vector<int>> grid(n+1,vector<int> (m+1,-1));
        grid[0][0]= 0;

        queue<pair<int,int>> q;
        q.push({0,0});
        int ans = 0;
        while(!q.empty()){
            auto start = q.front();
            int x = start.first;
            int y = start.second;
            int z = a-x-y;
            q.pop();


            

            

           if ((x == a/2 && y == a/2) ||
    (x == a/2 && z == a/2) ||
    (y == a/2 && z == a/2)) {ans = grid[x][y];break;}//精髓所在
            
            
            
            if(grid[min(n,x+z)][y]==-1){
                q.push({min(n,x+z),y});
                grid[min(n,x+z)][y] = grid[x][y] +1;
            }

            if(grid[x][min(m,y+z)]==-1){
                q.push({x,min(m,y+z)});
                grid[x][min(m,y+z)] = grid[x][y] +1;
            }

            if(grid[max(0LL,x-(m-y))][min(m,x+y)]==-1){
                q.push({max(0LL,x-(m-y)),min(m,x+y)});
                grid[max(0LL,x-(m-y))][min(m,x+y)] = grid[x][y] +1;
            }
            if(grid[min(n,x+y)][max(0LL,y-(n-x))]==-1){
                q.push({min(n,x+y),max(0LL,y-(n-x))});
                grid[min(n,x+y)][max(0LL,y-(n-x))] = grid[x][y] +1;
            }

            if(grid[0][y]==-1){
                q.push({0,y});
                grid[0][y] = grid[x][y] +1;
            }

            if(grid[x][0]==-1){
                q.push({x,0});
                grid[x][0] = grid[x][y] +1;
            }

        }
        if(ans !=0)cout<<ans<<endl;
         else cout<<"NO"<<endl;
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