#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int n,m;
    cin>>n>>m;

    vector<int> arr(n),brr(m);
    rep(i,0,n){int x;cin>>x;
    arr[i] = x*2;}
    rep(i,0,m){
        cin>>brr[i];
    }

    sort(arr.begin(),arr.end());
    sort(brr.begin(),brr.end());
    int ans = 0;
    int r = 0;

    rep(i,0,n){
            if(arr[i]>=brr[r]&&r<m){
                ans++;r++;
            }
        }
    
    cout<<ans<<endl;
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