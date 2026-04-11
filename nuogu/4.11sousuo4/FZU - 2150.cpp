#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

vector<int> dx ={0,0,1,-1};
vector<int> dy = {1,-1,0,0};

void solve(int i) {
    int n,m;
    cin>>n>>m;
    
    vector<string> grid(n);
    vector<pair<int,int>> grass;

    rep(i,0,n){
        cin>>grid[i];
    }

    rep(i,0,n)rep(j,0,m){
        if(grid[i][j]=='#')
        grass.push_back({i,j});
    }

    queue<pair<int,int>> q;
    int ans = LLONG_MAX;
    rep(i,0,grass.size())rep(j,i,grass.size()){
        vector<vector<int>> dist(n,vector<int>(m,-1));
        q.push(grass[i]);
           dist[grass[i].first][grass[i].second] = 0; 
        if(j!=i){
            q.push(grass[j]);
            dist[grass[j].first][grass[j].second] = 0;
        }
        

        
        int cur = -1;

        while(!q.empty()){
            auto start = q.front();
            q.pop();

            int x = start.first;
            int y = start.second;

            rep(i,0,4){
                int nx = x+dx[i];
                int ny = y+dy[i];

                if(nx<0||ny<0||nx>=n||ny>=m){//这里不能写错
                    continue;
                }
                if(dist[nx][ny]!=-1||grid[nx][ny]!= '#'){//这里来不能&&
                    continue;
                }

                q.push({nx,ny});
                dist[nx][ny] = dist[x][y]+1;

            }
            
            
            
            }
            for(auto [u,v] : grass){
                if(dist[u][v] == -1)
                {cur = -1;break;}
                cur = max(cur ,dist[u][v]);//局部最优点
                                           //位置应该是while（）全部结束才可以
        }
        if(cur != -1)
        ans = min(cur,ans);
    }
    if(ans == LLONG_MAX){
        ans = -1;
    }
    cout << "case "<<i<<": "<<ans<<endl;
    

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
        
    }
    return 0;
}