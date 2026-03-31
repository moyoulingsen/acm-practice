#include <bits/stdc++.h>
using namespace std;

typedef long long ll;  

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    priority_queue<ll,vector<ll>,greater<ll>> arr;
    ll cnt = 0;
    ll t;cin>>t ;
    while(t--){
        ll n,m;
        cin>>n>>m;

        if(n==1){
            cnt++;
            arr.push(m);
            
        }
        else {
              
                while(!arr.empty()&&arr.top()<=m){
                    arr.pop();
                    cnt--;
                }
                                
        }
        cout<<cnt<<"\n";

    }

    return 0;
}