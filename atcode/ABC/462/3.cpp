#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int n;cin>>n;
    vector<int> arr(n+1,LLONG_MAX);
    rep(i,0,n){
        int x,y;
        cin>>x>>y;
        if(y<=arr[x]){
            arr[x] =y;
        }
    }
    int ans = 0;
    int cur = LLONG_MAX;
    rep(i,1,n+1){
        if(arr[i]<=cur){
            cur = arr[i];
            ans++;
        }
    }
    cout<<ans;
       
}



signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}