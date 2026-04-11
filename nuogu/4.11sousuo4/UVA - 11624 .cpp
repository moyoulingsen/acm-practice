#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
vector <int> dx = {0,0,1,-1};
vector<int> dy = {1,-1,0,0};
void solve() {
    int n,m;
    cin>>n>>m;
    

    vector<string> grid(n);
    vector<vector<int>> fire(n,vector<int> (m,-1));
    int c,d;
    vector<pair<int,int>> fired;
    rep(i,0,n){
        cin>>grid[i];
    }
    
    rep(i,0,n)rep(j,0,m){
        if(grid[i][j] == 'F'){
           fired.push_back({i,j});
        }
        if(grid[i][j] == 'J'){
           if(i==0||j==0||i==n-1||j== m-1){
            cout<<1<<endl;
            return;
           }
           c = i;d =j;
        }
}
    queue<pair<int,int>> q;
    for (auto p : fired) {
    int u = p.first;
    int v = p.second;
    q.push({u, v});
    fire[u][v] = 0;
}

    

    while(!q.empty()){
        auto fired = q.front();
        q.pop();

        int x= fired.first;
        int y =fired.second;

       rep(i,0,4){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx<0||ny<0||nx>=n||ny>=m||grid[nx][ny] == '#'||fire[nx][ny] != -1){
            continue;
        }

        q.push({nx,ny});
        fire[nx][ny] = fire[x][y] +1;
       }
    }

    
    vector<vector<int>> dist(n,vector<int> (m,-1));
    q.push({c,d});
    dist[c][d] = 0;
    

    while(!q.empty()){
        auto job = q.front();
        q.pop();
        

        int x= job.first;
        int y =job.second;

       rep(i,0,4){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx<0||ny<0||nx>=n||ny>=m||grid[nx][ny] == '#'||dist[nx][ny] != -1){
            continue;
        }

        if(fire[nx][ny] != -1 &&fire[nx][ny]<= dist[x][y]+1) continue;

        if(nx == 0||ny == 0||nx ==n-1||ny == m-1) {cout<<dist[x][y]+2<<endl;return;}


        q.push({nx,ny});
        dist[nx][ny] = dist[x][y] +1;

       }

    }
    cout<<"IMPOSSIBLE"<<endl;
    
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t ;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}