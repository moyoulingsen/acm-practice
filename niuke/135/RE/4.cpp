#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        ll sum = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        ll m = sum > 0 ? (sum + n - 1) / n : sum / n;
        // ll ans =m*n-sum;
        ll ans =0;
            for (ll i = 0; i < n; i++)
        {
            if (arr[i] < m)
                ans += m - arr[i];
        }
        cout << ans << "\n";
    }

    return 0;
}