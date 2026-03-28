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
        cur = max(a[i], cur+a[i]);//以第 i 个位置结尾的连续子数组的最大和
        ////////////////////////////这是一个动态优化的空间优化
        ans = max(cur,ans);
    }

    cout << ans;
    

    return 0;
}