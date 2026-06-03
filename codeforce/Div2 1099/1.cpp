#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int n;cin>>n;
    set<int> s;
    int num = 0;
    int pre = 0;
    vector<int> ans(n);
        rep(i,1,2*n+1){
            if(num==n)break;
            if(s.find(i)!=s.end()){
                continue;
            }
            else{
                cout<< i <<" ";
                num++;
                s.insert(i);
                if(i>1)s.insert(i+pre);
                pre = i;
            }
        }
    cout<<endl;
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