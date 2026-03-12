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
    int ans = a[1];
    vector <int> s(n+1); 
    s[1]= a[1];
    for(int i=2;i<=n;i++){
        s[i]= s[i-1]+a[i];
    }

    
    for(int j=1;j<=n;j++){
        for (int i =j;i<=n;i++){
        int num;
        num = s[i]-s[j-1];
        if (num >=ans){
            ans = num;
        }
    }
    }

    cout << ans;
    

    return 0;
}