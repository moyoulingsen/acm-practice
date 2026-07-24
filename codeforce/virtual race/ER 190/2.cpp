#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve()
{
    string s;
    cin >> s;
    
    int total13 = 0;
    for(auto c:s){
        if(c=='1'||c=='3'){
            total13++;
        }
    }

    int pre2 = 0;
    int pre13 = 0;
    int ans = total13;//qiangqiang
    for(auto c:s){
        if(c=='1'||c=='3')pre13++;
        if(c=='2')pre2++;

        ans = max(ans,total13-pre13+pre2);
    }    

    cout<<s.size()-ans<<endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}