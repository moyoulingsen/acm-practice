#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)


void solve() {
    int n,k,m;
    cin>>n>>k>>m;
    vector<pair<int,int>> arr(n);
    rep(i,0,n){
        cin>>arr[i].second>>arr[i].first;
    }    

    sort(arr.begin(),arr.end());
    reverse(arr.begin(),arr.end());
    
    vector<int> num(n+1); 
    
    // int cnt,ans = 0;
    int cnt = 0;
    int ans = 0;
    rep(i,0,k){
        num[arr[i].second]++;
        if(num[arr[i].second]==1)cnt++;
        ans+=arr[i].first;
    }

    int r,l;
    r=k;l=k-1;

    while(cnt<m){
        // if(!num[arr[r].second])r++;
        if(num[arr[r].second])r++;
        else {
            // r++;
            num[arr[r].second]++;
            while(num[arr[l].second]==1){
                l--;
            }
            ans -=arr[l].first;
            num[arr[l].second]--;
            ans+=arr[r].first;
            r++;
            l--;
            cnt++;

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