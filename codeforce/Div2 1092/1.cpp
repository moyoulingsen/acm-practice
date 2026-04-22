#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int n,k;
    cin>>n>>k;

    vector<int> arr(k),brr(n);
    vector<int> ans(1000);

    int sum = 0;
    rep(i,0,k){cin>>arr[i];}
    rep(i,0,n){cin>>brr[i];sum+=brr[i];}

    int cnt = (k+1)*n-sum;
    if(cnt >1000){cout << "-1"<<endl;}
    else{cout <<cnt<<endl;
        //这种满足值等于5，输出下标，然后在处理值等于4，输出下标。再处理值等于三。
        rep(i,0,k){
            rep(j,0,n){
                if(brr[j]==k-i){
                    rep(l,0,i+1)
                    cout << j+1 <<" ";
                }
            }
        }
        cout <<endl;
        
    }


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