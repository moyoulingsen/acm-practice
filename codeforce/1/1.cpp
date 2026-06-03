#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int n,a,b;
    cin>>n>>a>>b;

   if(a>=b){
    if(n%3==0)cout<<n/3*b<<endl;
    else cout<<n/3*b +b<<endl;
   }
   else if(a<b&&b<=2*a){
       if(n%3==0)cout<<n/3*b<<endl;
       else if(n%3==1)cout<< n/3*b+a<<endl;
       else cout<<n/3*b+b<<endl;
   }
   else if(2*a<b&&3*a>=b){
       if(n%3==0)cout<<n/3*b<<endl;
       else if(n%3==1)cout<< n/3*b+a<<endl;
       else cout<<n/3*b+2*a<<endl;
   }
   else{
        cout<<n*a<<endl;
   }
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