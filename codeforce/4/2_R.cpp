#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int M = 0;
    vector<int> vis(n + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        M = max(M, a[i]);
        if (a[i] <= n) vis[a[i]] = 1;
    }

    int G = 0;
    while (G <= n && vis[G]) G++;

    long long ans;
    if (M >= G) {
        ans = 1LL * n * M
            + 1LL * G * (G + 1) / 2
            + 1LL * (n - 1 - G) * G;
    } else {
        ans = 1LL * n * M
            + 1LL * G * (G + 1) / 2
            - M
            + 1LL * (n - G) * G;
    }

    cout << ans << '\n';
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t ;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}