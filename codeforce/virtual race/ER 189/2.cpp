#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    string s;cin>>s;
    int cnt = 2;
    rep(i,1,s.size()){
        if(s[i-1]==s[i]){
            cnt--;
        }
    }
    cout<<((cnt>=0)?"YES\n":"NO\n");
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