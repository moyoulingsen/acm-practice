#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int a,b,c,x,y,z;
    cin>>a>>b>>c>>x>>y>>z;

    int d = (a-x)*(a-x)+(b-y)*(b-y);
    int r = (c+z)*(c+z);
    int r2 = (c-z)*(c-z);
    bool ans = d>r||d<r2;
    cout<<(ans?"No\n":"Yes\n");
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