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
    vector<int> dis(n);
    rep(i, 0, n)
    {
        cin >> dis[i];
        arr[i] = dis[i] - m; // tar = arr[i]
    }
    sort(dis.begin(), dis.end());
    int cnt = 0;
    rep(i, 0, n)
    {
        int ansr;
        int ansl;

        int l = -1;
        int r = n;
        while (l + 1 < r)
        {
            int mid = (r + l) / 2;
            if (dis[mid] < arr[i])
                l = mid;
            else
                r = mid;
        }
        if (arr[i] == dis[r])
        {
            ansl = r;
        }
        else
        {
            continue;
        }

        l = -1;
        r = n;
        while (l + 1 < r)
        {
            int mid = (r + l) / 2;
            if (dis[mid] <= arr[i])
                l = mid;
            else
                r = mid;
        }
        if (arr[i] == dis[l])
        {
            ansr = l;
        }
        cnt += (ansr - ansl + 1);
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