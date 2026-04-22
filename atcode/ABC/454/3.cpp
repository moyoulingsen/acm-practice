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

    vector<pair<int,int>> arr(m);
    vector<int> vis(n+1,0);
    rep(i,0,m){cin>>arr[i].first>>arr[i].second;}

    queue<int> q;
    q.push(1);
    vis[1] = 1;
    int ans = 1;
    while(!q.empty()){
        int start = q.front();
        q.pop();

        rep(i,0,m){
            if(arr[i].first == start &&vis[arr[i].second]==0){
                ans++;
                vis[arr[i].second]=1;
                q.push(arr[i].second);
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