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
    int cur = 1;
    int ans = 1;
    rep(i, 0, n)
    {
        cin >> arr[i];
        if (i > 0 && arr[i - 1] == arr[i])
        {
            cur++;
            ans = max(ans, cur);
        }
        else
        {
            cur = 1;
        }
    }

    if (m > ans)
    {
        cout << "yes" << endl;
        return;
    }
    else
    {
        cout << "no" << endl;
        return;
    }
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