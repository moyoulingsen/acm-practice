#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int n;cin>>n;
    vector<int>arr(4*n+5);
    rep(i,0,n){
        arr[4*i] = i+1;
        arr[4*i+1] = i+1;
        arr[4*i+2] = i+1;
        arr[4*i+3] = i+1;
    }
    rep(i,0,n-1){
        arr[4*i+1] = i+2;
    }
    arr[4*n-2] = 1;

    rep(i,0,4*n){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t ;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}