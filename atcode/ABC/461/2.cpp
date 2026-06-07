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
    rep(j,0,n){


        cin>>brr[j];
    }
    int ans = 1;
    rep(i,0,n){
        if(brr[--arr[i]] == i+1)continue;
        else {
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