#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int n,m;
    cin>>n>>m;

    vector<vector<int>> arr(n,vector<int> (m));
    rep(i,0,n)rep(j,0,m){
        rep(k,0,4){
             int x =  i+dx[k];
        int y = j+dy[k];
        if(x>=0&&x<n&&y>=0&&y<m)arr[i][j]++;
        }
        

    }



    rep(i,0,n){
        rep(j,0,m){
           cout<<arr[i][j]<<" ";
        }
        cout<<endl;
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