<<<<<<< HEAD
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

bool valid(string a){
    stack<char> st; //单一作用于里面初始化容器
    for (char c:a){
        if (c == '('||c =='['||c =='{') st.push(c);//验证后才是入栈
        else{if (st.empty()) return false;

             if (c==')'&&st.top()=='('||c==']'&&st.top()=='['||c=='}'&&st.top()=='{'){//小心char是有''单引号
                st.pop();
                
             }
             else return false;
        }
    }
    //如何处理循环后的输入输出
    //状态函数！！！
    return st.empty();
}

void solve() {
    string a;
    cin >> a;

    
    cout << (valid(a)?"YES\n":"NO\n");//<<优先级高于？

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        (void)!freopen("data.in", "r", stdin);
        (void)!freopen("data.out", "w", stdout);
    #endif

    int T ;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
=======
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

bool valid(string a){
    stack<char> st; //单一作用于里面初始化容器
    for (char c:a){
        if (c == '('||c =='['||c =='{') st.push(c);//验证后才是入栈
        else{if (st.empty()) return false;

             if (c==')'&&st.top()=='('||c==']'&&st.top()=='['||c=='}'&&st.top()=='{'){//小心char是有''单引号
                st.pop();
                
             }
             else return false;
        }
    }
    //如何处理循环后的输入输出
    //状态函数！！！
    return st.empty();
}

void solve() {
    string a;
    cin >> a;

    
    cout << (valid(a)?"YES\n":"NO\n");//<<优先级高于？

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        (void)!freopen("data.in", "r", stdin);
        (void)!freopen("data.out", "w", stdout);
    #endif

    int T ;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
>>>>>>> f3d8f9d220f226ccb00ba468b120269c5642f3ba
}