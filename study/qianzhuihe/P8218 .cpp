// P8218 【深进1.例1】求区间和



//防止炸界，上下界

//养成1的下标了解。
//防止数组炸上下界！！！

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

void solve(int n,int arr[]) {
    //建议下标用1，符合理解，防止炸下标
    
    
    int s[n+1];
    for(int i =1;i<=n;i++){
        s[0] = 0;            //这么防止数组越界，炸下界
        s[1] = arr[1];
        s[i] = arr[i]+s[i-1];
    }

    int l,r;
    
    cin >> l >>r ;
    cout<< s[r]-s[l-1]<<"\n";


    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //#ifndef ONLINE_JUDGE
    //    (void)!freopen("data.in", "r", stdin);
    //    (void)!freopen("data.out", "w", stdout);
    //#endif
    int n;
    cin>>n;
    int arr[n+1];            //防止炸界，炸上届
    for(int i =1;i<=n;i++){
        cin>>arr[i];
    }
    int T;
    cin >> T;
    while (T--) {
        solve(n,arr);
    }

    return 0;
}