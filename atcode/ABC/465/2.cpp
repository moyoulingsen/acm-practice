#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int w,h;
    cin>>h>>w;
    vector<string> arr(h+1);
    int a=0,b=0,c=0,d=0;

    rep(i,0,h){
        cin>>arr[i];
    }

    rep(i,0,h){
        int shan = 1;
        rep(j,0,w){
        if(arr[i][j]=='#'){
            shan = 0;
            break;
        }
        if(shan){
            a++;
        }
    }
}
    for(int i = h-1;i>=0;i--){
        int shan = 1;
        rep(j,0,w){
        if(arr[i][j]=='#'){
            shan = 0;
            break;
        }
        if(shan){
            b++;
        }
    }
}

    for(int i = 0;i<=w;i++){
        int shan = 1;
        rep(j,0,h){
        if(arr[i][j]=='#'){
            shan = 0;
            break;
        }
        if(shan){
            c++;
        }
    }
}

    for(int i = w-1;i>=0;i--){
        int shan = 1;
        rep(j,0,h){
        if(arr[i][j]=='#'){
            shan = 0;
            break;
        }
        if(shan){
            d++;
        }
    }
}

rep(i,a,h-b){
    rep(j,c,w-d){
        cout<<arr[i][j];
    }
    cout<<endl;
}


}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}