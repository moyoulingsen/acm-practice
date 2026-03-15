#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, l, r;
    cin >> n >> l >> r;

    string s;
    cin >> s;
    multimap<char, ll> m;

    for (int i = 0; i < n; i++)
    {
        m.emplace(s[i], i); // mutimap 没有索引m[]的赋值方法
    }

    set<char> ss;
    for (char c : s)
    {
        ss.insert(c);
    }
vector<ll> arr;
ll ans = 0;
    for (char c : ss)
    {   
        auto range = m.equal_range(c);
        for (auto it = range.first; it != range.second; it++)
        {
            arr.push_back(it->second);
        }
        
        
        for (ll i = 0; i < arr.size(); i++)
        {
            for (ll j = i + 1; j < arr.size(); j++)
            {
                if (arr[j] - arr[i] >= l && arr[j] - arr[i] <= r)
                    ans++;
            }
        }
        arr.clear();
    }

    cout << ans;

    return 0;
}