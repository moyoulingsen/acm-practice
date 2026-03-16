#include <bits/stdc++.h>
using namespace std;

typedef long long ll;  

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    

    while(t--){
        int n;cin>>n;
        vector<int> arr(n+1);
        map<int,int> m;
        for(int i =1;i<=n;i++){
            int a;cin>>a;
            arr[i]=a-i;
        }

       

        int ans = 0;
        for(auto pair :m){
            if(pair.second > ans) ans =pair.second;
        }


        

    cout<<ans<<'\n' ;  
    }
    

    return 0;
}