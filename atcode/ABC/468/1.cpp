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
    rep(i,0,n){
        cin>>arr[i];
    }
    int ans =0;

    for(int i = 1;i<n-1;i++){
        if(arr[i-1]<arr[i]&&arr[i]>arr[i+1]){
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