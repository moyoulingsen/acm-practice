#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int n;
    cin>>n;

    vector<int> arr(n);
    rep(i,0,n)cin>>arr[i];
    int ans = 0;

    if(arr[n-1] == 1){
        ans+=1;
    }

    sort (arr.begin(),arr.end());
    
    rep(i,0,n){

        if(arr[i]!= 1){
        int m = arr[i] % 676767677;
        ans+=m;
        }
    }
    
    cout<<ans<<endl;
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