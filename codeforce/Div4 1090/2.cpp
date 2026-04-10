#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"

void solve() {
    vector<int> s(7,0),a(7,INT_MIN);

    int ans = 0;
    int mmax = a[1];
    for(int i = 0;i<7;i++){
        
        cin>>a[i];
        mmax = max(a[i],mmax);
        ans += -a[i];
        
    
    }

    
    cout<<ans+2*mmax<<endl;


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