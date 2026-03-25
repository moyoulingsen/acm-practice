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
    
    vector<ll> dp(t+1);

    for(ll i=1;i<=m;i++ ){
        for(ll j = arr[i].first;j<=t;j++){
            dp[j] = max(dp[j],dp[j-arr[i].first]+arr[i].second);
        }
    }
    
    

    cout<< dp[t];

    return 0;
}