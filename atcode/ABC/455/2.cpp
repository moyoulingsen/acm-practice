#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int n,m;
    cin>>n>>m;
    vector<string> map(n);
    rep(i,0,n){
        cin>>map[i];
    }
    int cnt = 0;
    rep(i,1,n+1)rep(j,1,m+1){
        rep(k,0,n-i+1)rep(l,0,m-j+1){
            int right= 1;
            rep(q,0,i)rep(p,0,j){
                if(map[k+q][l+p]!=map[k+i-q-1][l+j-p-1]){
                    right = 0;
                }
            }
            if(right == 1){
                cnt++;
            }
        }
    }
    cout<<cnt;
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