#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int n,q;cin>>n>>q;
    vector<int> arr(n+1),brr(q+1);
    int k=0;
    while(q--){
        int x,y;
        cin>>x>>y;
        if(x==1){
            arr[y]++;
            brr[arr[y]]++;
            if(brr[arr[y]]==n)k++;
        }
        else{if(y+k<=q)
             cout <<brr[y+k]<<endl;
    
            else cout << 0 << endl;
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