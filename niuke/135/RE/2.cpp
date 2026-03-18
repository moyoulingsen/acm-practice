#include <bits/stdc++.h>
using namespace std;

typedef long long ll;  

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--){
        int n;cin>>n;
        map<int ,int> m;
        for(int i=0;i<n;i++){
            int a;cin>>a;
            m[a-i]++;
        }

        int ans=0;
        for (auto &pair: m ){
            ans = max(ans,pair.second);
        }
        cout << ans<<"\n";
    } 

    return 0;
}