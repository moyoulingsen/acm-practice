#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long k = 0;

        for (int i = 0; i + 1 < n; i++) {
            if (a[i] > a[i + 1]) {
                k = max(k, a[i] - a[i + 1]);
            }
        }

        if (k == 0) {
            cout << "YES\n";
            continue;
        }

        bool can0 = true;
        bool can1 = true;

        for (int i = 0; i + 1 < n; i++) {
            bool nxt0 = false;
            bool nxt1 = false;

            // 当前不加，下一个不加
            if (can0 && a[i] <= a[i + 1]) {
                nxt0 = true;
            }

            // 当前不加，下一个加
            if (can0 && a[i] <= a[i + 1] + k) {
                nxt1 = true;
            }

            // 当前加，下一个不加
            if (can1 && a[i] + k <= a[i + 1]) {
                nxt0 = true;
            }

            // 当前加，下一个加
            if (can1 && a[i] <= a[i + 1]) {
                nxt1 = true;
            }

            can0 = nxt0;
            can1 = nxt1;
        }

        if (can0 || can1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}