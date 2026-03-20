//01背包变体，精确背包
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;  

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n>>m;
    vector<int> arr(n+1);
    for(int i =1;i<=n;i++){
        cin>>arr[i];
    }

    vector<vector<int>> dp(n+1,vector<int> (m+1,0));

    dp[0][0]=1;//启动项，为什么

    for(int i=1;i<=n;i++){
        for(int j= 0;j<=m;j++){
                dp[i][j] += dp[i-1][j];
                if(j>=arr[i]){
                    dp[i][j]+=dp[i-1][j-arr[i]];
                }
            
        }
    }
    cout<<dp[n][m];

    return 0;
}