#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int n,k;
    cin>>n>>k;
    vector<vector<int>> arr(n);
    vector<int> num(n);
    rep(i,0,n){
        int m;cin>>m;
        num[i] = m; 
        vector<int> brr(m);
        rep(i,0,m){
            cin>>brr[i];
        }
        arr[i] = brr;
    }

    vector<int> c(n);
    rep(i,0,n){
        cin>>c[i];
    }


    int a,b;
    a= 0;b= 0;
    rep(i,0,n){
       k-=c[i]*num[i];
       if(k>0){
           a++;
       }
       else{
           k+=c[i]*num[i];
           b=k%num[i]; 
       }
    }

    if(b==0)cout<<arr[a][arr[a].size()-1];
    else cout<<arr[a][b-1];

    
    
    
   
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