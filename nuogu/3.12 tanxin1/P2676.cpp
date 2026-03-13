#include <bits/stdc++.h>
using namespace std;

typedef long long ll;  

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n,b;
    cin>>n>>b;
    vector<ll> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    sort(arr.begin(),arr.end(),greater<ll>());//reverse才是反转哦
    
    ll ans = 0;
    for(int i =0;i<n;i++){
        if((b-arr[i])>0){
            ans+=1;
            b= b-arr[i];
        }
        else {ans+=1;break;}
    }
    cout << ans;

    return 0;
}