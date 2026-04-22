#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int n;cin>>n;
    string s;
    cin>>s;

    stack<int> st;
    for(char a:s){
        if(!st.empty()&&a == 'u'&&st.top()=='i'){
            st.pop();
            if(!st.empty()&&st.top()=='n'){
                st.pop();
            }
            
        }
        else{
            if(!st.empty()&&a == 'o'&&st.top()=='m'){
            st.pop();
        }
        else{st.push(a);}
    }
    
   
}
 cout<<(((int)st.size()==0)?"Yes":"No");
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