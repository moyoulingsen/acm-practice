#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

struct Node{
    int a;
    char s[10];
// } node1(1,"aaaaa");
} node1{1,"aaaaa"};


void solve() {
    string filename = "data.dat";
    ofstream of(filename,ios::app|ios::binary);
    if(!of){cout<<"创建失败"<<endl;}
    else{
        of.write((char*)&node1,sizeof(node1));
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