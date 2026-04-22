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

    vector<vector<int>> arr(n+1);
    vector<int> vis(n+1);
    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        arr[a].push_back(b);
    }

    queue<int> q;
    q.push(1);
    vis[1] = 1;
    int ans = 1;

    while(!q.empty()){
        int start = q.front();
        q.pop();
        
        for(auto x:arr[start]){
            if(!vis[x]){
                ans++;
                q.push(x);
                vis[x] =1;
            }
        }
    }
    cout<<ans;
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