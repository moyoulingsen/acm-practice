#include <bits/stdc++.h>
using namespace std;

typedef long long ll;  

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    vector<int> arr;
    while(t--){
        int n;cin>>n;
        arr.resize(n+1);
        for(int i = 1;i<=n;i++){
            cin>>arr[i];
            
        }
        sort(arr.begin()+1,arr.end());
        int ans=1;
        int last=1;
        int noo=1;
        for(int i = 2;i<=n;i++){
            if(arr[i]-arr[last] >= noo){
                ans++;
                last = i;
                noo++;
            }
            
        }
        cout<<ans<<"\n";
    }

    return 0;
}