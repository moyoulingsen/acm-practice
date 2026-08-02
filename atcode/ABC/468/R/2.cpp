#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve()
{
    int m, d;
    cin >> m >> d;
    string s;
    cin >> s;
    int ans = 0;
    int n = s.size();
    rep(i, 0, s.size())
    {
        int left = max((int)0, i - d);
        int right = min(n-1, i + d);
        if (s[i] == '.')
        {   int cur = 1;
            rep(j, left, right+1)
            {
                if(s[j]=='G'){
                    cur = 0;
                }
            }
            ans+=cur;
        }
    }
    cout<<ans;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}