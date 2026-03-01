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
    int a;
    cin >>a;

    if(a<=18){cout << a+5;}
    else {cout << a-24+5;}
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