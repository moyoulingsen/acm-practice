#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int n,k;cin>>n>>k;
    string s;cin>>s;

stack<int> st;
vector<int> arr(n);
    int pos = 0;
    rep(i,0,n){
        
            if(s[i]=='('){
                st.push(i);
                
            }
           else{
               if(st.empty())continue;
               int j = st.top();
               st.pop();
               arr[i] = arr[j] = ++pos;
               
           }
    }
    int rest  = min(k,pos);
    vector<int> vis(pos+1);
    rep(i,0,n){
        if(rest>0){
            if(arr[i]==0)continue;
            if(!vis[arr[i]]){
            vis[arr[i]]++;
            arr[i] = 1;
            --rest;
           }
           else{
            arr[i] = 0;
           }
        }
        else{
            arr[i]=0;
        }
        
    }
    rep(i,0,n){
        cout<<arr[i];
    }
    cout<<endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t ;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}