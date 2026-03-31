#include <bits/stdc++.h>
using namespace std;

typedef long long ll;  

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;
        cin>>s;
        string ans = ""; 
        for(auto v:s){
            if(v!='!'&&v!='-'){
                ans+=v;
            }
        }
    }

    return 0;
}