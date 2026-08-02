#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    string s;cin>>s;
    int n = s.size();
    int ans =0;
    rep(i,0,n){
        int center = i;
        int diff =0;
        for(int r = center,l =center;r<=n-1&&l>=0;r++,l--){
            // if(s[r]==s[l]){
            //     ans++;
            // }
            // else{
            //     ++diff;
            //     if(diff<2)++ans;
            //     else break;
            // }
            if(s[l]!=s[r])++diff;
            if(diff>1)break;//只要没有退出循环就是加加
            ans++;
        }
        center = i;
        diff = 0;//同样的操作重置a
        for(int l =center,r = center+1;r<n&&l>=0;r++,l--){
            // if(s[r]==s[l]){
            //     ans++;
            // }
            // else{
            //     ++diff;
            //     if(diff<2)++ans;
            //     else break;
            // }
            if(s[l]!=s[r])++diff;
            if(diff>1)break;//只要没有退出循环就是加加
            ans++;
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