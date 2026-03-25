#include <bits/stdc++.h>
using namespace std;

typedef long long ll;  

bool dnf( ll n,vector <vector<ll>> &arr){
     for( ll i = 1;i<=n-2;i++){
        for( ll j = i+1;j<=n-1;j++){
            for(ll k = j+1;k<=n;k++)
            if(arr[i][j-i]+arr[j][k-j]<arr[i][k-i]) return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     ll n;cin>>n;
    vector <vector<ll>> arr(n+1,vector<ll> (n+1));
    for( ll i = 1;i<n;i++){
        for( ll j =1;j<=n-i;j++){
            cin>>arr[i][j];
        }
    }
    
   cout<<(dnf(n,arr)?"Yes":"No");

    


    return 0;
}