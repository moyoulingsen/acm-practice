#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve()
{
    int n;
    cin >> n;

    set<int> arr;

    rep(i, 0, n)
    {
        int x;
        cin >> x;
        arr.insert(x);
    }
    vector<int> ans;

    for (int a : arr)
    {
        ans.push_back(a);
    }

    if (ans.size() != n)
    {
        cout << -1 << endl;
        return;
    }

    reverse(ans.begin(), ans.end());

    rep(i, 0, n) cout << ans[i] << " ";
    cout << endl;
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