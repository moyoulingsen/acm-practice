#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);

    vector<int> ans(m+1, 0);
    rep(i, 0, n)
    {
        cin >> arr[i];
        ans[arr[i]]++;
    }

        int a = 1;
        rep(i, 1, m+1)
        {
            if (ans[i] >= 2)
            {
                a = 0;
                break;
            }
        }
        (a) ? (cout << "Yes\n") : (cout << "No\n");

        int b = 1;
        rep(i, 1, m+1)
        {
            if (ans[i] == 0)
            {
                b = 0;
                break;
            }
        }
        (b) ? (cout << "Yes\n") : (cout << "No\n");
    }
    // 检验有无重复的数字输入


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