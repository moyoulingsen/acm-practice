#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
//     int n;cin>>n;
//     vector<int> arr(n+1),brr(n+1);
//     for(int i = 1;i<=n;i++){
//         cin>>arr[i];
//     }
//     for(int i = 1;i<=n;i++){
//         cin>>brr[i];
//     }
//     for(int i = 1;i<=n;i++){
//         if(arr[brr[i]]!=i){
//             cout<<"No";
//             return 0;
//         }
//     }
//     cout<<"Yes";
 }

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    vector<int> arr(n+1),brr(n+1);
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i = 1;i<=n;i++){
        cin>>brr[i];
    }
    for(int i = 1;i<=n;i++){
        if(arr[brr[i]]!=i){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}
//省一点步骤，return



//rep(i,0,n)有一点局限吗
//一点局限都没有，就是想清楚；
// rep(i,0,n)
// rep(i,1,n+1)   的区别

