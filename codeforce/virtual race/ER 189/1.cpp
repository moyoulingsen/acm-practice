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

    int x = m/n;
    int ans = 0;
    if(x==2)cout<<"NO\n";
    else {rep(i,1,x+1){
        if(m%(n*i)!=0){
            ans = 1;
            break;
        }

    }
     cout<< ((ans)?"YES\n":"NO\n");
}
   
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