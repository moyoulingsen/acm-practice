#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int n;cin>>n;
    string a,b;
    cin>>a>>b;

    vector<int> dp(n+1);
    dp[0] = 0;

    rep(i,1,n+1){
        dp[i] = dp[i-1]+(a[i-1]!=b[i-1]);
        if(i>=2){
            dp[i] = min(dp[i],dp[i-2] + (a[i-2]!=a[i-1])+(b[i-2]!=b[i-1]));
        }
    }
    cout<<dp[n]<<endl;

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