#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int k,n;cin>>k>>n;
    vector<int> c(n);
    rep(i,0,n){
        cin>> c[i]; 
    }
    unordered_map<int,int> m;//很有<int,int> 的用vector足以
    
    rep(i,0,k){
        int a,b;
        cin>>a>>b;
        m[a] += b;
    }

    int sum = 0;
    rep(i,0,n){
        sum+=min(c[i],m[i+1]);//下标偏移
    }
    cout<<sum;
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