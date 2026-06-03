#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int a,b,c,l,r;
    cin>>a>>b>>c>>l>>r;
    
    set<int> s;
    s.insert(a);
    s.insert(b);
    s.insert(c);
   int cnt =0;
    for(auto x:s){
        if(l<=x||r>=x)cnt++;
    }
    cout<< r-l+1-cnt;
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