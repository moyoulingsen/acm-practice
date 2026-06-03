#include <bits/stdc++.h>
using namespace std;

typedef long long ll;  

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t,m;
    cin>>t>>m;

    vector<pair<int,int>> arr(m+1);
    for(int i=1;i<=m;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    
    vector<int> dp(t+1);

    for(int i = 1;i<=m;i++){
        for(int j = t;j>=arr[i].first;j--){
            dp[j] = max(dp[j],dp[j-arr[i].first]+arr[i].second) ;
        }
    }
    
    
    

    cout<< dp[t];

    return 0;
}