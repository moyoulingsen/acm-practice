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
    char a ;
    int n1,n2,m1,m2;n1=n2=m1=m2=0;
    while(cin >> a){
        if(a=='E') {
            cout << n1<<':'<<m1<<'\n';
            cout << n2<<':'<<m2<<'\n';
            break;
        };
        if(a=='W') {
            n1++;n2++;
            if(n1>=11&&(n1-m1)>=2){
                cout << n1<<':'<<m1<<'\n';
                n1=m1=0;
            }
            if(n2>=21&&(n2-m2)>=2){
                cout << n2<<':'<<m2<<'\n';
                n2=m2=0;
            }
        }
        if(a== 'L'){
            m1++;m2++;
            if(m1>=11&&(m1-n1)>=2){
                cout << n1<<':'<<m1<<'\n';
                n1=m1=0;
            }
            if(n2>=21&&(n2-m2)>=2){
                cout << n2<<':'<<m2<<'\n';//还是有错误逻辑
                n2=m2=0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // #ifndef ONLINE_JUDGE
    //     (void)!freopen("data.in", "r", stdin);
    //     (void)!freopen("data.out", "w", stdout);
    // #endif

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

//既然工作流有问题,就要学会更改变通