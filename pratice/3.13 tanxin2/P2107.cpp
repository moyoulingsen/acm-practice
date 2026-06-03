#include <bits/stdc++.h>
using namespace std;

typedef long long ll;  

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

    sort(arr.begin(),arr.end(),[](auto a,auto b){
        if(a.first!=b.first)return a.first<b.first;
        return a.second<b.second;
    });
    
    priority_queue<ll> pq;
    int cur=0;
    int pos=0;
    for(ll i =0;i<n;i++){

        if(cur + arr[i].second + arr[i].first - pos <m){
            cur = cur + arr[i].second + arr[i].first - pos ;
            pos = arr[i].first;
            pq.push(arr[i].second);
        }
        else if(!pq.empty() && arr[i].second<pq.top()&&cur -pq.top()+arr[i].second + arr[i].first - pos<m){
            cur = cur -pq.top()+arr[i].second + arr[i].first - pos;
            pq.pop();
            pq.push(arr[i].second);
        }

    }


    cout << pq.size();




    return 0;
}