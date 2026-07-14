#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int n;cin>>n;
    vector<int> arr(n+1);
    vector<vector<int>> ans(n+1);
    rep(i,1,n+1){
        int num;cin>>num;
        rep(j,0,num){
            int x;cin>>x;
            arr[x]++;
            ans[x].push_back(i);
        }
    }
    rep(i,1,n+1){
        cout<<arr[i]<<" ";
        rep(j,0,arr[i]){
            // cout<<ans[j]<<" ";
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

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