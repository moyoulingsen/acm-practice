#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"

void solve() {
    int n,m,target;
    cin>>n>>m>>target;

    struct Node{
        int prex,prey,cha,step = -1;
    };

    vector<vector<Node>> grid(n+1,vector<Node> (m+1));
    
    queue<pair<int,int>> q;

    grid[0][0] = {-1,-1,-1,0};
    q.push({0,0});

    while(!q.empty()){
        

        int nx = (q.front()).first;
        int ny = (q.front()).second;
        q.pop();

        if(nx == target || ny == target){
           int steps = grid[nx][ny].step;
           vector<string> ans;
           while(grid[nx][ny].prex != -1 ){
              int num = grid[nx][ny].cha;
              if(num == 1){
                ans.push_back("FILL(1)");
              }
              if(num == 2){
                ans.push_back("FILL(2)");
              }
              if(num == 3){
                ans.push_back("DROP(2)");
              }
              if(num == 4){
                ans.push_back("DROP(1)");
              }
              if(num == 5){
                ans.push_back("POUR(2,1)");
              }
              if(num == 6){
                ans.push_back("POUR(1,2)");
              }
              int px = grid[nx][ny].prex;
              int py = grid[nx][ny].prey;
              nx = px;
              ny = py;
           }
           reverse(ans.begin(),ans.end());
           
           cout << steps << endl;
           for(const string& op : ans){
                cout << op << endl;
           }
           return;
        }

        if(grid[n][ny].step == -1 ){
           q.push({n,ny});
           grid[n][ny] = {nx,ny,1,grid[nx][ny].step + 1};
        }

        if(grid[nx][m].step == -1 ){
           q.push({nx,m});
           grid[nx][m] = {nx,ny,2,grid[nx][ny].step + 1};
        }

        if(grid[nx][0].step == -1 ){
           q.push({nx,0});
           grid[nx][0] = {nx,ny,3,grid[nx][ny].step + 1};
        }
        
        if(grid[0][ny].step == -1 ){
           q.push({0,ny});
           grid[0][ny] = {nx,ny,4,grid[nx][ny].step + 1};
        }
        
        if(grid[min(n,nx+ny)][max(0LL,ny - (n-nx))].step == -1 ){
           q.push({min(n,nx+ny),max(0LL,ny - (n-nx))});
           grid[min(n,nx+ny)][max(0LL,ny - (n-nx))] = {nx,ny,5,grid[nx][ny].step + 1};
        }

        if(grid[max(0LL,nx-(m-ny))][min(m,nx+ny)].step == -1 ){
           q.push({max(0LL,nx-(m-ny)),min(m,nx+ny)});
           grid[max(0LL,nx-(m-ny))][min(m,nx+ny)] = {nx,ny,6,grid[nx][ny].step + 1};
        }




    }ss
    cout << "impossible" << endl;

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
