
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void f(ll n,vector<ll> &arr )
{
    ll ans = 0;
    ll mmax = arr[0];
    ll mmin = arr[0];
    for(ll i=0;i<n;i++){
        mmax = max(mmax,arr[i]);
        mmin = min(mmin,arr[i]);
    }
    ans = (mmax-mmin+1);
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
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
        {
            ll a;
            cin >> a;
            arr.push_back(a);
        }

        f(n, arr);
    }

    return 0;
}