#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int n,a,b;
    cin>>n>>a>>b;
    int snap = gcd(a,b);
    vector<int> arr(n);
    rep(i,0,n)cin>>arr[i];

    int ans = 1;

    rep(i,0,n){
        if((i+1)%snap != arr[i]%snap) ans = 0;
    }
    cout<<((ans)?"Yes\n":"No\n");


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