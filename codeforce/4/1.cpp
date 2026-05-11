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
    rep(i,0,n)cin>>arr[i];
    int cnt = 0;

    for(int i = n-2;i>=0;i--){
    
            if(arr[i+1]>0){
                arr[i] = arr[i+1]+arr[i];
            }
        
    }
    for(auto c:arr){
        if(c>0)cnt++;
    }
    cout<<cnt<<endl;
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