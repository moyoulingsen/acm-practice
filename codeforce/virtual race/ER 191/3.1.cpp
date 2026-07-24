#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int n,k;string s ;
    cin>>n>>k>>s;
    int x,y;
    x = y= 0;
    int p = 0;
    rep(i,0,n){
        if(s[i]=='('){
            x++;
        }
        else{
            y++;
        }
    }
    int mn = LLONG_MAX;
    int ll = 0;
    int rr = y;
    rep(i,0,n){
        if(ll+rr<mn){
            p =i;
            mn =ll+rr;
        }
        
        if(s[i]=='('){
            ll++;
        }
        else{
            rr--;
        }
    }
    if(ll + rr < mn){
    p = n;
    mn = ll + rr;
}

    
    vector<int> ans(n);
    
    rep(i,0,p){
        if(s[i]=='(')ans[i] = 1;
    }
    rep(i,p,n){
        if(s[i] ==')')ans[i] =1;
    }

    int rest = min(k,mn);
    rep(i,0,n){
        if(rest>0){
            if(ans[i]==0)continue;
            if(ans[i]==1){
                --rest;
            }
        }
        else{
            ans[i] = 0;
        }
    }

    //   int rest = min(k,mn);
    // rep(i, 0, n) {
    //     if (ans[i] == 1) {
    //         if (rest > 0) rest--;
    //         else ans[i] = 0;
    //     }
    // }

    
    rep(i,0,n)cout<<ans[i];
    cout<<endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t ;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}