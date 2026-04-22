#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int n,m;
    set<int> s;

    rep(i,0,n){
        int x;cin>>x;
        s.insert(x);
    }

    ((int)s.size() == n)?(cout<<"Yes\n"):(cout<<"No\n");
    ((int)s.size() == m)?(cout<<"Yes\n"):(cout<<"No\n");
    

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