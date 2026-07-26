#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int m,n;
    cin>>m>>n;
    string s;
    cin>>s;
    int cnt = 0;
    rep(i,n,m-n){
        if(s[i]=='.'){
            int ans =1;
            // rep(j,i-n,i+n){真正的是左开右闭了
            rep(j,i-n,i+n+1){
                if(s[j]=='G'){
                    ans = 0;
                }
            }
            cnt +=ans;
        }
    }
    rep(i,0,n){
        if(s[i]=='.'){
            int ans =1;
            rep(j,0,i+n+1){
                if(s[j]=='G'){
                    ans = 0;
                }
            }
            cnt +=ans;
        }
    }
    rep(i,m-n,m){
        if(s[i]=='.'){
            int ans =1;
            rep(j,i-n,m){
                if(s[j]=='G'){
                    ans = 0;
                }
            }
            cnt +=ans;
        }
    }
    cout<<cnt;
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