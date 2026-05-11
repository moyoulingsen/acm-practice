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
    rep(i,0,n){
        if(arr[i]==mex){
            mex++;
        }
    }

    if(mmax>=mex){
        ans= n*mmax;
        int mmex = 0;
        rep(i,0,n-1){
        if(arr[i]==mmex){
            mex++;
            ans+=mmex;
        }
        else ans+=mmex;
    }

    else{
        ans += (mex+1+1)*(mex+1)/2+(n-mex)*(mex+1);
        ans += (mex+1)*mex/2+(n-mex)*mex;
    }
    }


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