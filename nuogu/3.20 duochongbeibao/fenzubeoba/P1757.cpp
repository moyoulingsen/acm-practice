#include <bits/stdc++.h>
using namespace std;

typedef long long ll;  

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m,n;
    cin>>m>>n;
    
    vector<vector<pair<int,int>>> group(n+1);
    for(int i = 1;i<=n;i++){
        int a,b,c;
        cin>>a>>b>>c;

        group[c].push_back({a,b});//有问题vector里面的还是vector
    }

    vector<int> dp(m+1);
    for(int i = 1;i<=n;i++){
        for(auto [w,v]:group[i]){
            for(int j = m;j>=v;j--){
                dp[j]= max(dp[j],dp[j-w]+v);
            }
        }
    }
    
    cout<<dp[m];
    


    return 0;
}