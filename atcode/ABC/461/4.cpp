#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int h,w,k;
    cin>>h>>w>>k;
    

    vector<vector<int>> arr(h,vector<int> (w,0));
    vector<string> brr(h);
    rep(i,0,h)cin>>brr[i];
    arr[0][0]  = brr[0][0] -'0';
    rep(i,1,w){
        arr[0][i] = brr[0][i]-'0'+arr[0][i-1];
    }
    rep(j,1,h){
        arr[j][0] = brr[j][0]-'0'+arr[j-1][0];
    }
    rep(i,1,w)rep(j,1,h){
        int a = arr[j-1][i-1];
        arr[j][i]  =brr[j][i] - '0'+a+arr[j-1][i]-a+arr[j][i-1]-a;
    }
    int ans =0;
    rep(i,0,h)rep(j,0,w){
        int cur =arr[i][j];
        if(cur<k)continue;
        
        else{
            if(cur == k)ans++;
            rep(p,0,i){
                if(cur-arr[p][j]==k)ans++;
            }
            rep(q,0,j){
                if(cur-arr[i][q]==k)ans++;
            }
            rep(p,0,i)rep(q,0,j){
                if(cur - arr[i][q]-arr[p][j]+arr[p][q]==k)ans++;
            }
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


//