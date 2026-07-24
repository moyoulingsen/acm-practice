#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int ans=1;
    int n;cin>>n;
    vector<int> arr(n),cur(n),sum(n);
    // sum[0]=1;
    // cur[0]=1;
    
    rep(i,0,n){
        cin>>arr[i];
        if(i==0){
           cur[i] = arr[i];
           sum[i] = 1;
        }
        // if(i>1)sum[i] = sum[i-1]+i+1;
        if(i>=1)sum[i] = sum[i-1]+i+1;
        // cin>>arr[i];
        // cur[i]+=arr[i];
        if(i>=1)cur[i] = cur[i-1]+arr[i];
        if(cur[i]<sum[i]){
            ans = 0;
            // break;
        }
    }
    
     cout<<((!ans)?"No":"Yes")<<endl;
    
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}