#include <bits/stdc++.h>
using namespace std;

typedef long long ll;  

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;cin>>n;
    vector<pair<ll,ll>> arr;

    for(ll i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        arr.emplace_back(a,b);
    }

    sort(arr.begin(),arr.end(),[](auto a,auto b){
        if(a.second!=b.second)return a.second<b.second;
        return a.first<b.first;
    });

    ll cur=0;
    priority_queue<ll> pq;
    for(auto &[a,b]:arr){
        if(cur+a<b){
            pq.push(a);
            cur += a;
        }
        else if(!pq.empty() && a<pq.top()){
            cur = cur - pq.top() + a;
            pq.pop();
            pq.push(a);
        }
    }

    cout << pq.size();
    return 0;
}