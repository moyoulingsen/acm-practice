#include <string>
#include <iostream>
using namespace std;

#define ull unsigned long long
#define int long long

#define endl "\n"

int ans = 0;

void solve() {
    int n;cin>>n;
    // vector<char> r1(n),r2(n);//这样没有语法错误
    // vector<char> target(2*n);//对于vector完全没有问题，array就不行
    
    string s1,s2,target;
    cin>>s1>>s2>>target;
    string start1 = s1;string start2 = s2; 
    string cur ="";
    ans = 0;
    

    while(cur!=target){
         cur = "";
         for(int i = 0;i<n;i++){
         cur += s2[i];
         cur += s1[i];
    }
    s1 = "";s2 = "";
        for(int i = 0;i<n;i++){
         s1+= cur[i];
         s2+= cur[i+n];
    }
    ans++;
    if(s1 == start1 && s2 == start2 ){ans = -1;break;}
    }

    

    

    
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
        cout << i+1 <<" "<<ans<<endl; 
    }
    return 0;
}