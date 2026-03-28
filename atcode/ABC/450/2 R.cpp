#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool exists_split_cheaper(int n, const vector<vector<ll>>& c) {
    for (int a = 1; a <= n - 2; a++) {
        for (int b = a + 1; b <= n - 1; b++) {
            for (int d = b + 1; d <= n; d++) {
                if (c[a][b] + c[b][d] < c[a][d]) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<ll>> c(n + 1, vector<ll>(n + 1));

    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }

    cout << (exists_split_cheaper(n, c) ? "Yes" : "No") << '\n';
    return 0;
}
