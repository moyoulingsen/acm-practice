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
    int sum = 0;
    int mmin = INT_MAX;
    int mmax = INT_MIN;
    rep(i, 0, n)
    {
        int x;
        cin >> x;
        sum += x;
        mmin = min(mmin, x);
        mmax = max(mmax, x);
    }

    int mx = mmax * (n - 1) - sum + mmin;
    if (m <= mx)
    {
        cout << sum - mmin - mmax + m;
    }
    else
    {
        int rest = (m - mx + n - 2) / (n - 1);
        cout << sum - mmin - (mmax + rest) + m;
    }
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