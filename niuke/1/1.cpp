#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int a,b,c,l,r;
    cin>>a>>b>>c>>l>>r;
    int sum = a+b+c;
    int mmin = min(a,min(b,c));
    int mmax = max(a,max(b,c));
    int other = sum -mmin-mmax;

    if(l>mmax||r<mmin)cout<<r-l+1;
    else{if(r>=mmax&&l<=mmin){
         cout <<r-l-2;
    }
    else{
        if(l<=mmin&&r>=other&&r<mmax||r>=mmax&&l>mmin&&l<=other){
            cout <<r-l-1;
        }
        else cout<<r-l;
    }
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