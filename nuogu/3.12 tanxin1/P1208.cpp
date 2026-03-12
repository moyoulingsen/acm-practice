#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    vector<pair<int,int>> arr;

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;

        arr.emplace_back(a,b);
    }
    
    sort(arr.begin(),arr.end(),[](auto a,auto b){if(a.first!=b.first)return a.first<b.first;return a.second<b.second;});
    int ans =0;
    for(int i=0;i<m;i++){
        
        if(n - arr[i].second >= 0) {n = n - arr[i].second;
                    ans += arr[i].second*arr[i].first;}
           
        else {ans += n*arr[i].first;break;}
    }

    cout<<ans;

    return 0;
}