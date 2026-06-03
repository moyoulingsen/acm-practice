#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    string s;cin>>s;
    vector<int> ans;
    rep(i,0,s.size()){
        if(s[i]=='C'){
            ans.push_back(i);
        }
    }

    int cut = 0;
    for(auto v:ans){
        cut += min((long long)(v+1),(long long)(s.size()-v));
    }
    cout<<cut;
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