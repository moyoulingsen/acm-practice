#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
int mmax = 0;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> dx ={ 1 , -1, 0, 0};
    vector<int> dy = {0,0,-1,1};

    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    vector<vector<int>> ans(n,vector<int> (m,-1));
    queue<pair<int,int>> q;

    for(int a = 0;a<n;a++){
        for(int b = 0;b<m;b++){
            for(int c = 0;c<n;c++ ){
                for(int d= 0;d<m;d++){
                    if(grid[a][b] == '#'&& grid[c][d] == '#'){
                        ans[a][b] = 0;
                        ans[c][d] = 0;
                        q.push({a,b});
                        q.push({c,d});

                        while(!q.empty()){
                            auto cur = q.front();
                            q.pop();

                            for(int i = 0;i<4;i++){
                                int nx = cur.first + dx[i];
                                int ny = cur.second+ dy[i];

                                if(nx>=0&&nx<n&&ny>=0&&ny<m&&ans[nx][ny]==-1 && grid[nx][ny]=='#'){//这个顺序一定不能反
                                    q.push({nx,ny});
                                    ans[nx][ny] = min(ans[cur.first][cur.second] +1,ans[nx][ny]);
                                    
                                }
                            }
                        }
                    }

                }
            }
        }
    }
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(ans[i][j] == '.'){
                mmax = -1;
                break;
            }
            mmax = max(mmax,ans[i][j]);
        }
    }


}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
        cout<< "Case "<<i<<": "<<mmax<<endl;
    }
    return 0;
}