#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int a;cin>>a;
    string s;cin>>s;
    int mmax = 0;
    vector<int> arr(a);
    if(s[0]=='#'){arr[0]=1;mmax=1;}
    rep(i,1,a){
       if(s[i]=='#')arr[i]=arr[i-1]+1;
       mmax = max(mmax,arr[i]);
    }
    
    if(mmax%2==0){
        cout <<mmax/2<<endl;
    }
    else cout<<mmax/2+1<<endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}