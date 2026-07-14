#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int n,d;
    cin>>n>>d;
    vector<pair<int,int>> arr(n);
    rep(i,0,n){
        cin>>arr[i].first>>arr[i].second;
    }
    sort (arr.begin(),arr.end());

    int l = 0;
    int r;
    int ans =0;
    while (l<n){
        r=l+1;
        int x = arr[l].second;
        while(r<n&&arr[r].first<x){
            int sum =  min(x,arr[r].second)-arr[r].first;
            if(sum>=d){
                ans+=sum-d+1;
            }
            r++;
        } 
        ++l;
        
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