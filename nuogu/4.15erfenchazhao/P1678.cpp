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

    vector<int> arr(n), brr(m);
    rep(i, 0, n) cin >> arr[i];
    rep(i, 0, m) cin >> brr[i];
    int cnt, ans = 0;
    sort(arr.begin(), arr.end()); // 二分之前一定要排序
                                  //     for (int x : brr)
                                  //     {
                                  //         auto l = lower_bound(arr.begin(), arr.end(), x);
                                  //         auto r = upper_bound(arr.begin(), arr.end(), x);
                                  //         cnt = min(*r - x, x - *l)
                                  //         ans += cnt;
                                  //     }
                                  //     cout << ans;
                                  // }
    rep(i, 0, m)
    {
        int l = -1;
        int r = n;
        while (l + 1 < r)
        {
            int mid = (l + r) / 2;
            if (arr[mid] < brr[i])
                l = mid;
            else
                r = mid;
        }
        if (brr[i] <= arr[0])
        {
            cnt = arr[0] - brr[i];
        }
        else if (brr[i] >= arr[n - 1])
        {
            cnt = brr[i] - arr[n - 1];
        }
        else
            cnt = min(arr[r] - brr[i], brr[i] - arr[l]);
        ans += cnt;
    } //////////////////还有边界检查的动脑子
    cout << ans;
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