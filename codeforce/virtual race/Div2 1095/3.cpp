#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int n;cin>>n;
    vector<int> arr(n);
    rep(i,0,n){
        cin>>arr[i];
    }
    int l = 0, r = n, mexwf = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        multiset<int> s(arr.begin(), arr.end());
        bool ok = true;

        for(int x = mid - 1; x >= 0; --x){
            auto it = s.find(x);
            if(it != s.end()){
                s.erase(it);
                continue;
            }
            it = s.lower_bound(2 * x + 1);
            if(it == s.end()){
                ok = false;
                break;
            }
            s.erase(it);
        }

        if(ok){
            mexwf = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    cout<<mexwf<<endl;
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
