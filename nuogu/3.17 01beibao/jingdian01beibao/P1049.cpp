#include <bits/stdc++.h>
using namespace std;

typedef long long ll;  

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m,n;
    cin>>m>>n;

    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
        cin>> arr[i];
    }

    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    for(int i=1;i<=n;i++){
        for(int j = 0;j<=m;j++){
            if(j>=arr[i]){
                dp[i][j] =max(dp[i-1][j],dp[i-1][j-arr[i]]+arr[i]);
                
            }
            else dp[i][j] =dp[i-1][j];
        }
    }
    cout<<  m - dp[n][m];
    return 0;
}
//反正最后你会发现i-1，你就不得不开到n+1.
//背包反正是从0到满