#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int n,m;
    cin>>n>>m;
    vector<string> grid(n);
    rep(i,0,n)cin>>grid[i];

    int cnt =0;
    rep(i,0,n-1)rep(j,0,m-1){
        set<int> s{grid[i][j],grid[i][j+1],grid[i+1][j],grid[i+1][j+1]};
        if((int)s.size()==3)cnt++;
    }
    cout<<cnt*2;
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