#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long INF = (1LL << 62);

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1), s(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] ^ a[i];
    }

    vector<long long> dp(n + 1, INF);
    dp[0] = 0;

    for (int r = 1; r <= n; r++) {
        long long mn = INF;
        for (int l = r; l >= 1; l--) {
            mn = min(mn, dp[l - 1]);   // 这里逐步维护 min(dp[k]), k in [l-1, r-1]
            dp[r] = min(dp[r], mn + (s[r] ^ s[l - 1]));
        }
    }

    cout << dp[n] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
