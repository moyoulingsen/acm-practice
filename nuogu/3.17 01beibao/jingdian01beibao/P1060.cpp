#include <bits/stdc++.h>
using namespace std;

typedef long long ll;  

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> arr(m+1);
    for(int i=1;i<=m;i++){
        cin>>arr[i].first>>arr[i].second;
    }

    vector<vector<int>>  dp(m+1,vector<int> (n+1,0));
    for (int i=1;i<=m;i++){
        for(int j = 0;j<=n;j++){
            if(j>=arr[i].first){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-arr[i].first]+arr[i].second*arr[i].first);
            }
            else dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[m][n];

    return 0;
}