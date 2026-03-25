#include <bits/stdc++.h>
using namespace std;

typedef long long ll;  

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,w;
    cin>>n>>w;

    vector<int> v(n+1);
    vector<int> wr(n+1);
    vector<int> m(n+1);

    for(int i = 1;i<=n;i++){
        cin >> v[i]>>wr[i]>>m[i]; 
    }

    vector<pair<int,int>> arr;

    for(int i= 1 ;i<=n;i++){        //仔细检查循环里面的东西
        int cnt = m[i];
        for(int k =1;k<=cnt;k = k*2){//<<=1
                                    //这里k*2 是没有更新的
            arr.emplace_back(k*v[i],k*wr[i]);
            cnt-=k;
        }
        if(cnt > 0){
            arr.emplace_back(cnt*v[i],cnt *wr[i]);   //////////////////////////非常精妙的使用后面的那一个
        }
    }
    
    vector<int> dp(w+1);
    for (int i = 0;i<arr.size();i++){ //这里直接用以前的n会出问题的
                                       //size这里面是从0开始的哦
                                       //也可以for(auto [w,v]:arr)
        for(int j =w;j>= arr[i].second;j--){
            dp[j]= max(dp[j],dp[j-arr[i].second]+arr[i].first);
        }
    }

    cout << dp[w] ;

    return 0;
}