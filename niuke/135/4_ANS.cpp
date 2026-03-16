#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void f(ll n, multiset<ll> &s)
{
    ll ans = 0;
    while (s.count(*s.begin()) != n)
    {
        if ((*s.begin()) + 1 != *s.rbegin())
        {
            ll mmin = *s.begin();
            ll mmax = *s.rbegin();
            s.erase(s.begin());
            // erase(s.rbegin());错误的
            s.erase(prev(s.end()));
            s.insert(mmax - 1);
            s.insert(mmin + 1);
            ans++;
        }
        else
        {
            ans += (s.count(*s.begin()));
            break;
        }
    }
    cout << ans << '\n';
}

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
        multiset<ll> s;
        for (ll i = 0; i < n; i++)
        {
            ll a;
            cin >> a;
            s.insert(a);
        }

        f(n, s);
    }

    return 0;
}