#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int n;cin>>n;
     
    vector<vector<int>> arr(n);
    rep(i,0,n){
        int m;cin>>m;
        vector<int> brr(m);
        rep(j,0,m){
            cin>>brr[j];
        }
        arr[i] = brr;
    }

    int a,b;
    cin>>a>>b;
    cout<<arr[a-1][b-1];

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