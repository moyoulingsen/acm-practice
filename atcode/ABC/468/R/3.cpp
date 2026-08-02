#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int n;cin>>n;
    vector<int> arr(n),brr(n);
    rep(i,0,n){
        cin>>arr[i];
    }
    rep(i,0,n){
        cin>>brr[i];
    }

    vector<int> c(n);
    iota(c.begin(),c.end(),1);

    int ans =0;

    while(c<=arr){
        // next_permutation(c.begin(),c.end());
        //判断同时下一个了

        //  if (!next_permutation(c.begin(), c.end())) {
        // cout << 0 << '\n';
        // return;
         if (!next_permutation(c.begin(), c.end())) {
        cout << 0 << '\n';
        return;
    
    }
    }
    
    while(c<brr&&c>arr){
        ans++;
        next_permutation(c.begin(),c.end());
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