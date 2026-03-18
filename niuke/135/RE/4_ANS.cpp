#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        ll sum = 0;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i], sum += a[i];
        ll p = sum > 0 ? (sum + n - 1) / n : sum / n, chg = 0;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] < p)
                chg += p - a[i];
        }
        cout << chg << endl;
    }

    return 0;
}