#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

class Father{
    private:int a;
    
    public:Father(int a):a(a){}
    void geta(){
        cout<<a<<endl;
    }
};

class Son:public Father{
    public:
    Son(int a):Father(a){}
    void kuayueshi(){
        geta();
    }
};


void solve() {
   Son a(1);
   a.kuayueshi(); 
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