#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;  

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n,m;cin>>n>>m;
    vector<pair<ll,ll>> arr;

    for(ll i=0;i<n;i++){
        ll x,t;
        cin>>x>>t;
        arr.emplace_back(x,t);
    }

    sort(arr.begin(),arr.end());
    
    priority_queue<ll> pq;
    ll cur=0;
    for(auto &[x,t]:arr){
        if(cur+x+t<=m){
            cur += t;
            pq.push(t); 
        }
        else if (!pq.empty() && t<pq.top()&& cur - pq.top()+t+x<=m){
            cur =cur - pq.top()+t;
            pq.pop();
            pq.push(t);
        } 
    }
    
    


    cout << pq.size();




    return 0;
}