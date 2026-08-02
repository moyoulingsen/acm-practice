#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    int n = S.size();
    long long ans = 0;

    // 奇数长度子串：中心是一个字符
    for (int center = 0; center < n; center++) {
        int diff = 0;

        for (int l = center, r = center; l >= 0 && r < n; l--, r++) {
            if (S[l] != S[r]) {
                diff++;
            }

            if (diff <= 1) {
                ans++;
            } else {
                break;
            }
        }
    }

    // 偶数长度子串：中心在两个字符之间
    for (int center = 0; center + 1 < n; center++) {
        int diff = 0;

        for (int l = center, r = center + 1; l >= 0 && r < n; l--, r++) {
            if (S[l] != S[r]) {
                diff++;
            }

            if (diff <= 1) {
                ans++;
            } else {
                break;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}