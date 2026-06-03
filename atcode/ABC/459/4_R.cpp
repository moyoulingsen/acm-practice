#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    string s; cin>>s;
    int l = s.size();
    vector<int> arr(26);
    int mmax =LLONG_MIN;
    string ans ="";
    rep(i,0,l){
        arr[s[i]-'a']++;
        mmax= max(arr[s[i]-'a'],mmax);
    }

    if(mmax>(l+1)/2){
        cout<<"No"<<endl;
    }
    else{
        cout<<"Yes"<<endl;
        rep(i,0,l){
            int nm = -1;
            rep(j,0,26){
                if(arr[j]==0)continue;
                if(!ans.empty()&&ans.back()==char(j+'a'))continue;//char不必要，但是更加安全
                if(nm==-1||arr[j]>arr[nm]){
                    nm = j;
                }
            }
            
            ans+=char(nm+'a');
            arr[nm]--;
            //寻找最大值标准写法
        }
        cout<<ans<<endl;
    }
    ///////////要非常小心arr[i]和i的区别,还有nm的区别
    
    
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