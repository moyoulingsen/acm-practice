#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int q,w,e,r,t,y,u,i;
    cin>>q>>w>>e>>r>>t>>y>>u>>i;
    // else{
    //     cout<<(((w-r)/!=(y-i)/(t-u))?"Yes":"No")<<endl;
    // }
// # 
// ## 1
// 竞赛里面不要用斜率，你把握不住
// 实际上太多的k= 0还要讨论太复杂了
    



// cout<<(((w-r)*(t-u)!=(y-i)*(q-e))?"Yes":"No")<<endl;
    // ## 2 
    // 向量坐标表示平行和垂直，
    // 记得平行用乘法相加避免除法截断




// ## 3
// 直线要考虑平行和垂直和重合，可能有特解    
    // int d1= q+e;
    // int d2= w+r;
    // int d3= t+u;
    // int d4 = y+i;
    // int cross = ((w-r)*(t-u)!=(y-i)*(q-e));
    // if(cross)cout<<"Yes"<<endl;
    // else{
    //     if(d1==d3&&d2==d4){
    //         cout<<"Yes"<<endl;
    //     }
    //     else{
    //         cout<<"No"<<endl;
    //     }
    // } 
    int d1= q+e;
    int d2= w+r;
    int d3= t+u;
    int d4 = y+i;
    int cross = ((w-r)*(t-u)!=(y-i)*(q-e));
    if(cross)cout<<"Yes"<<endl;
    else{
        int dx = d1-d3;
        int dy = d2-d4;
        int mx = q-e;
        int my = w-r;
        if(dx*mx+dy*my==0){
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;
    }

    
        
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}



