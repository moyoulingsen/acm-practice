#include <bits/stdc++.h>
using namespace std;

typedef long long ll;  

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t,m;
    cin>>t>>m;

    vector<pair<ll,ll>> arr(m+1);
    for(ll i=1;i<=m;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    
    vector<vector<ll>> dp(m+1,vector<ll> (t+1,0));
    
    for(ll i=1;i<=m;i++){
        for(ll j=0;j<=t;j++){                                     //容量是0-t，但物品是1-m个。
            if(j-arr[i].first>=0)
        dp[i][j] = max(dp[i-1][j],dp[i][j-arr[i].first]+arr[i].second);
        else  dp[i][j] = dp[i-1][j];
        }
        
    }

    cout<< dp[m][t];

    return 0;
}