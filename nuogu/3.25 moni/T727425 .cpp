#include <bits/stdc++.h>
using namespace std;

typedef long long ll;  

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    map<int ,int> m;
    
    for(int i = 0;i<4;i++){
        for(int j=0;j<4;j++){
            int a;cin>>a;
            m[a]++;
        }
    }

    for(auto [u,v]:m){
        if(v==3){
            cout<<u;
        }
    }

    
    return 0;
}