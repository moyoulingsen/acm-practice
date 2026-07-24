#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int n,x,y,z;
    cin>>n>>x>>y>>z;
    
    int s1 = (n+(x+y)-1)/(x+y);
    if(z>=n/x)cout<<s1<<endl;
    else{
          int s2 = ((n-z*(x))+(10*y+x)-1)/(10*y+x)+z;
          cout<<min(s1,s2)<<endl;
    }
   
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t ;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}