// 3. 重载是C++面向对象的一大特色，C++可以重载大部分的运算符，使其拥有新的功能。现请你设计程序，定义一个STRING类，拥有一个字符串属性p，并重载“<<”运算符，该函数将字符串p按照如下要求处理：

// 1. 字母区分大小写升序排序，如Type,则处理后为：Tepy；
// 2. 非英文字母则排在其原来位置，如Type：Abc 则处理后：ATbc:epy 处理后，将字符串输出。
// 【考察范围：运算符重载 字符数组 排序】
// 注意：字符串中可能包含多个空格,长度不超过1000。

// 输入
// 多组测试输入
// 每组输入一行字符串，以“Enter”键结束

#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    string s;
    // getline(cin,s);
    while(getline(cin,s)){
         vector<int> arr;

    for(char c:s){
        if(c>='a'&&c<='z'||c>='A'&&c<='Z'){
            arr.push_back(c);
        }
    }
    sort(arr.begin(),arr.end());
    int l= 0;
    rep(i,0,s.size()){
        int c = s[i];
        if(c>='a'&&c<='z'||c>='A'&&c<='Z'){
           s[i] = arr[l];
           l++;
        }
    }
    cout<<s<<endl;
    }
   
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}