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




vector<int> f (vector<int> &num,int n){
    stack<int> st;
    vector <int> ans(n,0);

    for(int i =0 ;i<n;i++){
        while(!st.empty()&& num[st.top()]<num[i]){
             ans[st.top()]=i+1;
             st.pop();
        }
        st.push(i);
    }
    return ans;//函数有输出就是有返回值的
}

void solve() {
    int n;
    cin >> n;
    vector<int> num,ans;
    
    for (int i = 0;i<n;i++){
        int a;
        cin >> a;
        num.push_back(a);
    }

    ans = f(num,n);
    for (int j = 0;j<n;j++){
        cout << ans[j]<< " ";
    }
    
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