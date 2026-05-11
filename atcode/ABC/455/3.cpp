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

    vector<int> arr(n);
    set<int> num;
    rep(i,0,n){
        cin>>arr[i];
        num.insert(arr[i]);
    }
    vector<int> sum;
    for(int nu:num){
        int n = count(arr.begin(),arr.end(),nu);
        sum.push_back(nu*n);
    }

    sort(sum.begin(),sum.end());
    int ans = 0;
    if(sum.size()>=m){
        rep(i,0,sum.size()-m){
        ans+=sum[i];
    }    

    cout<<ans;
    }
    else cout<<ans;
    
    
    

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