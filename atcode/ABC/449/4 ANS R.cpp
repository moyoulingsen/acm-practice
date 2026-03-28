//gpt改进答案版
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int l, r, d, u;
    cin >> l >> r >> d >> u;

    ll ans = 0;

    // Case 1: |x| > |y|, color determined by |x|
    for (int x = l; x <= r; x++) {
        if (abs(x) % 2 == 0) {
            int low = max(d, -abs(x) + 1);
            int high = min(u, abs(x) - 1);
            if (low <= high) ans += (high - low + 1);
        }
    }

    // Case 2: |x| <= |y|, color determined by |y|
    for (int y = d; y <= u; y++) {
        if (abs(y) % 2 == 0) {
            int low = max(l, -abs(y));
            int high = min(r, abs(y));
            if (low <= high) ans += (high - low + 1);
        }
    }

    cout << ans << '\n';
    return 0;
}
