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

    vector<int> arr(n), tar(n);
    rep(i, 0, n)
    {
        cin >> arr[i];
        tar[i] = arr[i] - m;
    }
    sort(arr.begin(), arr.end());
    int cnt = 0;
    rep(i, 0, n)
    {
        int target = tar[i];
        auto l = lower_bound(arr.begin(), arr.end(), target);
        auto r = upper_bound(arr.begin(), arr.end(), target);

        cnt += (r - l);
    }
    cout << cnt;
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


////////////////这道题目还有o（n)的写法