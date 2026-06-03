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
    int n,m;
    cin>>n>>m;

    vector<vector<int>> matrix(n,vector(m,0));//第二个怎么写啊
                                              //第二个就是c17里面   
                                              // vector(大小, 初始值) → 推导为vector<初始值类型>
                                              // vector(迭代器, 迭代器) → 推导为vector<迭代器指向的类型>
    for (int i=0;i<n;i++ ){
        for(int j=0;j<m;j++){                 //遍历有初始化你怎么忘了？？？
            cout << matrix[i][j]<<" ";
        }
        cout<<"\n";
    }

//一种c17后的遍历
    cout << "\n";
    for(auto arr:matrix){//这里vector，有auto快速表示
        for(int value:arr){
            cout << value <<" ";
        }
        cout <<"\n"; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // #ifndef ONLINE_JUDGE
    //     (void)!freopen("data.in", "r", stdin);
    //     (void)!freopen("data.out", "w", stdout);
    // #endif

    int T ;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

