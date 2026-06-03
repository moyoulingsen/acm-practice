// 链接：https://ac.nowcoder.com/acm/contest/129231/B
// 来源：牛客网

// 小苯在梦里梦到了 ICPC 奖牌是可以合成的。
// 具体来说，合成规则如下：
// ∙
//  
// ∙
// 𝑥
// x 个铜牌可以合成 
// 1
// 1 个银牌；
// ∙
//  
// ∙
// 𝑦
// y 个银牌可以合成 
// 1
// 1 个金牌。

// 特别地，每次合成一个金牌时，会额外掉落 
// 1
// 1 个铜牌作为副产品。
// 现在小苯初始拥有 
// 𝑎
// a 个金牌、
// 𝑏
// b 个银牌、
// 𝑐
// c 个铜牌。
// 他可以通过不断合成，将低级奖牌逐步升级为高级奖牌。银牌可以继续合成金牌，铜牌也可以先合成银牌再合成金牌。每次合成金牌后掉落的铜牌可以继续参与后续的合成。

// 你的任务就是求出最终小苯最多能拥有多少个金牌。


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
    i64 a,b,c,x,y,sum;//只有 s 被初始化为 0。
                      //你不看一下10e9意味着什么。
    cin>>a>>b>>c>>x>>y;

    while (c>=x || b>=y){  //要是一开始银牌就可以合成铜牌了，
                           //这两个有一个满足就可以继续了
       sum = x*b+c;
       a = sum /(x*y)+a;
       b = (sum %(x*y))/x;
       c = sum /(x*y)+(sum %(x*y))%x;
    }
    
    cout << a ;
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