#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int n;cin>>n;
    vector<int> arr(n);
    rep(i,0,n){
        cin>>arr[i];
    }
    int cnt = 0;
    rep(i,0,n){
        if(i>=1){
             int g =gcd(arr[i-1],arr[i]);
        if(abs(arr[i-1]-arr[i])==g)cnt++;
        }
        
        if(i<n-1){
            int h =gcd(arr[i+1],arr[i]);
            if(abs(arr[i+1]-arr[i])==h)cnt++;
        }
        

    }
    cout<<cnt/2<<endl;
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