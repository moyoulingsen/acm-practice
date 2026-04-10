#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"

void solve() {
    int n;cin>>n;
    for(int i = 1;i<=n;i++){
        cout<< i <<" "<< n*3-2*(i-1) << " "<< n*3-1-2*(i-1)<<" ";
    }
    cout << endl;
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