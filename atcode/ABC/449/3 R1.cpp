#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, l, r;
    cin >> n >> l >> r;

    string s;
    cin >> s;

    map<char, vector<ll>> pos;
    for (ll i = 0; i < n; i++) {
        pos[s[i]].push_back(i);
    }

    ll ans = 0;

    for (auto &[ch, arr] : pos) {
        ll sz = arr.size();
        ll p1 = 1, p2 = 1;

        for (ll i = 0; i < sz; i++) {
            p1 = max(p1, i + 1);
            p2 = max(p2, i + 1);

            while (p1 < sz && arr[p1] - arr[i] < l) p1++;
            while (p2 < sz && arr[p2] - arr[i] <= r) p2++;

            ans += (p2 - p1);
        }
    }

    cout << ans << '\n';
    return 0;
}
