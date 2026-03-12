#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;cin>>n;
    vector<int> a(n+1);
    for (int i =1;i<=n;i++ ){
        cin>>a[i];
    }
    int ans = a[1]; int cur=a[1];
    
    for(int i =2 ;i<=n;i++){
        cur = max(a[i], cur+a[i]);
        ans = max(cur,ans);
    }

    cout << ans;
    

    return 0;
}