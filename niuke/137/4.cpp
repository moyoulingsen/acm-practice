#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"

void solve() {
    int n;cin>>n ;
    vector<int> arr(n+1);
    vector<int> s(n+1);
    for (int i = 1;i<=n;i++){
        cin>>arr[i];
        s[i]= s[i-1]^arr[i];
    }

    vector<int> dp(n+1,0);
    for(int i =1 ;i<=n;i++){
        dp[i] = dp[i-1]+arr[i];
        for(int j =1;j<i;j++){
            dp[i]= min(dp[i],dp[j-1]+(s[i]^s[j-1]));//
                                                     //异或前缀和唯一需要记住的地方
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