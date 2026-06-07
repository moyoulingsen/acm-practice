#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int n;cin>>n;
    vector<int> arr(n+1),brr(n+1);
    rep(i,1,n+1)cin>>arr[i];
    rep(i,1,n+1)cin>>brr[i];
    int ans = 1;
    rep(i,1,n+1){
        if(arr[brr[i]]!=i){
            ans = 0;
            break;
        }
    }
    cout<<(ans?"Yes":"No");

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