#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

int c (int a){
    return a*(a-1)/2;
    
}

void solve() {
    int n,d;
    cin>>n>>d;
    vector<pair<int,int>> arr(n);
    vector<int> diff(10e6+5);
    rep(i,0,n){
        cin>>arr[i].first>>arr[i].second;
    }
    
    vector<int> time(10e6+5);
    rep(i,0,n){
        auto[u,v] =arr[i];
        if(v-d>=u){
            // rep(j,u,v-d+1){
            //     time[j]++;
            // }
            diff[u] += 1;
            diff[v - d + 1] -= 1;
        }
    }
    int ans = 0;
    rep(i,1,diff.size()){
        // time[i] = diff[i]+diff[i-1];
        time[i] = time[i-1]+diff[i];
    }
    rep(i,1,time.size()){
        if(time[i]>=2){
             ans += c(time[i]);
        }
    }
    cout<<ans;

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