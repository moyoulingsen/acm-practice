//https://vjudge.net/contest/65959#problem/B

#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"


int ans ;


void bfs (vector<vector<string>> &grid,vector<vector<vector<int>>> &vis,int a,int b,int c,int sx,int sy,int sz){
    queue <array<int,3>> q;
    q.push({sx,sy,sz});
    vis[sx][sy][sz] = 0; 

    int dx[6] = {1,-1, 0,0,0,0};
    int dy[6] = { 0 ,0 ,1, -1,0 ,0};
    int dz[6] = { 0 , 0, 0, 0, 1, -1 };

    
    

    while (!q.empty()){
        auto cur = q.front();
        q.pop();

        int x = cur[0];
        int y = cur[1];
        int z = cur[2];
        if(grid[x][y][z]=='E'){
       ans = vis[x][y][z];
       return;
    }

        for(int i= 0;i<6;i++){
            sx = x + dx[i];
            sy = y + dy[i];
            sz = z + dz[i];
            
            if(sx == a|| sx==-1||sy ==b||sy == -1|| sz == c ||sz == -1 ){
                continue;
            }

            if (grid [sx][sy][sz] == '#'|| vis[sx][sy][sz] != -1){
                continue;
            }

            vis[sx][sy][sz] = vis [x][y][z]+1;
            q.push({sx,sy,sz});


        }
        ans = -1;
        
    }
    
}



void solve() {
    int a,b,c;

    int x,y,z;
    while(cin >>a>>b>>c){
        
        if(a==0&&b==0&&c==0)return;

        vector<vector<string>> grid(a,vector<string>(b));
        vector<vector<vector<int>>> vis(a,vector<vector<int>>(b,vector<int>(c,-1)));

        for(int i = 0;i<a;i++){
            for(int j =0;j<b;j++){
                cin >>  grid[i][j];
                for(int k = 0;k<c;k++){
                    if (grid[i][j][k] == 'S'){
                        x = i;
                        y = j;
                        z = k;
                        break;
                    } 
                }
            }

        }
    bfs (grid,vis,a,b,c,x,y,z);

    if(ans == -1){cout << "Trapped!"<<endl;}                  //if 里面的==
    else cout << "Escaped in "<<ans<<" minute(s)."<<endl;
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