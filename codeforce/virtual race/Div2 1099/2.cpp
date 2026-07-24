#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int n;cin>>n;
    vector<int> arr(n);
    rep(i,0,n)cin>>arr[i];
    int ans = 1;

    int lmmax =arr[0];

    rep(i,1,n){
       int k = arr[i]-arr[i-1];
       if(k<0){
          rmmax = arr[i];
       }
       
    }
cout<<((ans==1)?"Yes\n":"No\n");
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