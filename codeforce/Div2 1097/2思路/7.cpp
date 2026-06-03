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
    int mmax = 0;
    rep(i,0,n){cin>>arr[i];
    mmax = max(mmax,arr[i]);}

    sort(arr.begin(),arr.end());
    
    

    int ans = 0;
    int mex = 0;

    int pos = -1;
    rep(i,0,n){
        if(arr[i]==mmax){
            pos = i;
            break;
        }
    }

    if(mmax = 0) ans++;
    
    rep(i,0,n){
        if(i==pos) continue;
        if(arr[i]==mex){
            mex++;
            if(mmax==mex){
            mex++;
        }
           
        }
        ans += mex;

        

        

    }

    
    ans += mmax*n;
    cout<<ans<<endl;
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