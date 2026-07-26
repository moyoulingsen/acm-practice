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

    vector<pair<int,int>> arr(m+1);
    rep(i,1,m+1){
        cin>>arr[i].first>>arr[i].second;
    }
    
    vector<int> dp(m+1);
    rep(i,1,m+1){
        for(int j = n;j>arr[i].first;j--){
            dp[j]=max(dp[j],dp[j-arr[i].first]+arr[i].first*arr[i].second);
        }
    }
    cout<<dp[n];
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