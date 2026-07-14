#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    string filename = R"(C:\Users\ASUS\Desktop\acm-pracice\atcode\a.txt)";
    ifstream inf(filename);

    string s;
    while(getline(inf,s)){
        cout<<s<<endl;
    }

    cout<<"\n";
    

    inf.clear(); //清除 EOF 状态
    inf.seekg(0); //把读指针移回文件开头


    char c[101];
    while(inf.getline(c,100)){
        cout<<c<<endl;
    }

    inf.clear();
    inf.seekg(0);
    string sss;
    while(inf>>sss){
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