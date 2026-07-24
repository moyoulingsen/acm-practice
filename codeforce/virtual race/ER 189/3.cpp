#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    string top, bottom;
    cin >> top >> bottom;

    vector<int> dp(n + 1, (int)1e18);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        dp[i] = min(dp[i], dp[i - 1] + (top[i - 1] != bottom[i - 1]));
        if (i >= 2) {
            dp[i] = min(
                dp[i],
                dp[i - 2] + (top[i - 2] != top[i - 1]) + (bottom[i - 2] != bottom[i - 1])
            );
        }
    }

    cout << dp[n] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
