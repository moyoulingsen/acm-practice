#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int n;
    cin>>n;

    vector<int> arr(n);
    vector<int> tar(n);
    rep(i,0,n)cin>>tar[i];
    rep(i,0,n){
        arr[i] = i+1;
    }

    int l,r;
    l=0;
    r=n-1;
    int ans=1;

    
        rep(i,0,n){
            if(arr[l]==tar[i]){
                l++;
            }
            else if(arr[r]==tar[i]){
                r--;
            }
            else {
                ans = 0;
                break;
            }
            
        }
        
    
    cout<<((ans==1)?"YES\n":"NO\n");
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