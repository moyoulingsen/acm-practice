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

string add(string &a,string &b){
     int i = a.size()-1;
     int j = b.size()-1;
     int add = 0;

     int num,num1,num2;
     string ans = "";/////初始化字符串方便添加

     while(i >= 0||j>=0||add !=0){   /////错误的越界条件。如果i小于0怎么办
        num1 = (i>=0)?a[i]-'0':0;////char转int。最快的是ASAII码里面减去‘’
        num2 = (j>=0)?b[j]-'0':0;////典型的经典 Copy-Paste 错误

        num = (num1 + num2 + add)%10;
        add = (num1 + num2 + add)/10;

        ans += to_string(num)  ;     

        i--;//最后怎么能忘了指针前移
        j--;
     }
    reverse(ans.begin(),ans.end());//reverse才是反转
                                  //reverse返回void只是修改了anas而已
    return ans;
}

void solve() {
    string a,b;
    getline(cin,a);
    getline(cin,b);

    cout <<add(a,b);
    
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