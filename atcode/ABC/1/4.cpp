#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int n;cin>>n;
    int m;cin>>m;
    priority_queue<int> arr;
    priority_queue<int,vector<int>,greater<int>> brr;
    
    arr.push(n);
     int ans = n;
     rep(i,0,m){
        int x,y;
     cin>>x>>y;
     if(x<=ans){
        arr.push(x);
     }
     else{
        brr.push(x);
     }
     if(y<=ans){
        arr.push(y);
     }
     else{
        brr.push(y);
     }

     if(arr.size()-brr.size()==3){
        brr.push(arr.top());
        arr.pop();
        ans = arr.top(); 
     }
     else if (arr.size() - brr.size() == -3){
        arr.push(brr.top());
        brr.pop();
        ans = brr.top(); 
     }
     
     cout<<ans<<endl;
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