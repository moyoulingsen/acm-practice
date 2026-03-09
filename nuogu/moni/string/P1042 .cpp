#include <bits/stdc++.h>

#if __has_include("tool/local.hpp")
    #include "tool/local.hpp"
#else
    #define debug(...) 42
#endif

using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using f80 = long double;
using pii = pair<int, int>;
using pll = pair<i64, i64>;

constexpr int INF = 1e9 + 7;
constexpr i64 INF64 = 4e18;

void solve() {
    string s ="";
    char a;
    while(cin>>a){
        s+=a;
    }
    int n,m;
    n=m=0;
    for(char l:s){
        if(l == 'E'){
            cout <<n <<":"<<m<<"\n";
            break;
        }
        if(l =='W'){
            n++;
            if(n>=11&&(n-m)>=2){
                cout <<n <<":"<<m<<"\n";
                n = m = 0;
            }
        }
        if(l =='L'){
            m++;
            if(m>=11&&(m-n)>=2){
                cout <<n <<":"<<m<<"\n";
                n = m = 0;
            }
        }
    }
    cout <<'\n';
    n= m =0;



      //状态情况切换的时候,比分没有清零!!!
    for(char l:s){
        if(l == 'E'){                     ///精彩!!!!!
            cout <<n <<":"<<m<<"\n";
            break;
        }
        if(l =='W'){
            n++;
            if(n>=21&&(n-m)>=2){
                cout <<n <<":"<<m<<"\n";
                n = m = 0;
            }
        }
        if(l =='L'){
            m++;
            if(m>=21&&(m-n)>=2){
                cout <<n <<":"<<m<<"\n";
                n = m = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#include <bits/stdc++.h>

#if __has_include("tool/local.hpp")
    #include "tool/local.hpp"
#else
    #define debug(...) 42
#endif

using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using f80 = long double;
using pii = pair<int, int>;
using pll = pair<i64, i64>;

constexpr int INF = 1e9 + 7;
constexpr i64 INF64 = 4e18;

void solve() {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        (void)!freopen("data.in", "r", stdin);
        (void)!freopen("data.out", "w", stdout);
    #endif

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
    #ifndef ONLINE_JUDGE
        (void)!freopen("data.in", "r", stdin);
        (void)!freopen("data.out", "w", stdout);
    #endif

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}