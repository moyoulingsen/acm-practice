#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    vector<int > a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector <long long >s(n+1);
        s[1]=a[1];
        for(int i=1;i<=n;i++){
            s[i]=s[i-1]+a[i];
        }


    int m ;cin>>m;
    while(m--){
        int l,r;cin>>l>>r;
        
        long long ans;
        ans = s[r]-s[l-1]; 
        cout<< ans<<"\n";
    

    }

    return 0;
}