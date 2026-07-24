#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int f(int n, int k, int p, int m, vector<ll> &arr)
{
    int ans = 0;
    int mmin = arr[n - 1];
    int pos;
    for (ll ii = n - 1; ii >= n - k; ii--)
    {
        if (arr[ii] < pow(2, (n - ii - 1)) * arr[n - 1])
        {
            mmin = arr[ii];
            pos = ii;
        }
    }

    int cur = p;
    while (m >= 0)
    {
        if (n - cur > pos)
        {
            int mmmin = arr[n - 1];
            int ppos;
            for (ll i = n - 1; i >= n - cur; i--)
            {
                if (arr[i] < pow(2, (n - i - 1)) * arr[n - 1])
                {
                    mmmin = arr[i];
                    ppos = i;
                }
            }
            int need = ppos - (n - cur);
            if (m - mmmin * (need + 1) >= 0)
            {
                ans++;
                cur = n;
                m = m - mmmin * (need + 1);
            }
            else
                return ans;
        }

        else
        {
            int need = pos - (n - cur);
            if (m - mmin * (need + 1) >= 0)
            {
                ans++;
                cur = n;
                m = m - mmin * (need + 1);
            }
            else
                return ans;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    vector<ll> arr;
    int n, k, p, m;
    while (t--)
    {

        cin >> n >> k >> p >> m;

        for (int i = 1; i <= n; i++)
        {
            int a;
            cin >> a;
            arr.push_back(a);
        }
        reverse(arr.begin(),arr.end());
        cout << f(n, k, p, m, arr) << '\n';
    }

    return 0;
}