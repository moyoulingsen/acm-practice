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

    // 用 map<char, vector<ll>> 直接存每个字符出现的位置
    map<char, vector<ll>> pos;

    for (ll i = 0; i < n; i++) {
        pos[s[i]].push_back(i);
    }

    ll ans = 0;

    for (auto &[ch, arr] : pos) {
        ll sz = arr.size();
        for (ll i = 0; i < sz; i++) {
            auto left = lower_bound(arr.begin() + i + 1, arr.end(), arr[i] + l);
            auto right = upper_bound(arr.begin() + i + 1, arr.end(), arr[i] + r);
            ans += (right - left);
        }
    }
    ///////////这里的i+1表示 

    cout << ans << '\n';
    return 0;
}
