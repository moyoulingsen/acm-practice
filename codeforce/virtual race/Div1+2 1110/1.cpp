// #include <bits/stdc++.h>
// using namespace std;

// #define ull unsigned long long
// #define int long long
// #define pii array<int, 2>
// #define endl "\n"
// #define rep(i, a, b) for (int i = (a); i < (b); ++i)


// void changer(string& s,int a){
//     while(a>0){
//         for(int i= s.size()-1;i>0;i--){
//             if(s[i]=='L')continue;
//             else{
//                 s[i] = 'L';
//                 a--;
//             }
//         }
//     }
// }

// void solve() {
//     int n,m;cin>>n>>m;
//     string s;cin>>s;
//     int ans = 0;
//     int maxx = (n+1)/2;
//     if(m>maxx){
//         cout<<-1<<endl;
//     }
//     else{
//         int totalr=0;
//     for(auto c:s){
//         if(c=='R')totalr++;
//     }
//     int l=n-totalr,r=0;
//     rep(i,0,n){
//         if(s[i]=='R'){
//             r++;
//             if(l<m){
//                 l+=m-l;
//                 changer(s,m-l);
//                 ans+=m-l;
//             }
//         }
//         else{
//             l--;
//             if(r<m){
//                 s[i] = 'R';
//                 r++;
//                 ans++;
//             }
//         }
//         cout<<totalr<<" " <<r<< " "<<l<< " "<<ans<<endl;
//     }
//     cout<<ans<<endl;
//     }

    
       
// }

// signed main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int t;
//     cin >> t;
//     for (int i = 0; i < t; i++) {
//         solve();
//     }
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    if (2 * m > n) {
        cout << -1 << endl;
        return;
    }

    vector<int> preL(n + 1, 0), preR(n + 1, 0);
    rep(i, 0, n) {
        preL[i + 1] = preL[i] + (s[i] == 'L');
        preR[i + 1] = preR[i] + (s[i] == 'R');
    }

    int ans = 1e18;
    rep(a, m, n + 1) {
        rep(b, a, n - m + 1) {
            int cost1 = preL[a];
            int cost2 = preR[n] - preR[b];
            ans = min(ans, cost1 + cost2);
        }
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
