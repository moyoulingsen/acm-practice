#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define eb emplace_back
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define endl "\n"
using namespace std;

using ll = long long;
using ld = long double;
using ui = unsigned;
using ull = unsigned long long;
using i128 = __int128;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
using TIII = tuple<int, int, int>;
using TLLL = tuple<ll, ll, ll>;

int mod(int a, int b) {
    return ((a % b) + b) % b;
}

void init() {
}

void solve() {
    int n,m;
    cin >>n>>m;
    vector<pair<int,string>> arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    int cur=0;
    int dir,stp;

    for(int i =0;i<m;i++){
        cin>>dir>>stp;
        if(arr[cur].first == 1){
            if(dir == 0){
                cur+=stp;
                cur = mod(cur,n);
            }
            else{cur-=stp;
            cur= mod(cur,n);}
        }
        else{
            if(dir == 0){
                cur-=stp;
                cur = mod(cur,n);
            }
            else{cur+=stp;
            cur= mod(cur,n);}
        }
        }
    cout << arr[cur].second;
    }





        

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    init();

    int t = 1;
    // cin >> t;
    cout << fixed << setprecision(15);
    for (int _ = 1; _ <= t; ++_) {
        solve();
    }

    return 0;
}