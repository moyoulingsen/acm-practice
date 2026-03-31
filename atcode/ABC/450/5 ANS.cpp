#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
const int64 LIM = (int64)1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string X, Y;
    cin >> X >> Y;

    int Q;
    cin >> Q;

    // 预处理 X, Y 的前缀字符计数
    vector<array<int64, 26>> preX(X.size() + 1), preY(Y.size() + 1);
    for (int i = 0; i < (int)X.size(); i++) {
        preX[i + 1] = preX[i];
        preX[i + 1][X[i] - 'a']++;
    }
    for (int i = 0; i < (int)Y.size(); i++) {
        preY[i + 1] = preY[i];
        preY[i + 1][Y[i] - 'a']++;
    }

    // len[i] = |S_i|，cnt[i][c] = S_i 中字符 c 的总出现次数
    vector<int64> len = {0, (int64)X.size(), (int64)Y.size()};
    vector<array<int64, 26>> cnt(3);

    for (char ch : X) cnt[1][ch - 'a']++;
    for (char ch : Y) cnt[2][ch - 'a']++;

    while (len.back() < LIM) {
        int n = (int)len.size() - 1; // 当前最后一个下标
        int64 nxt_len = min(LIM, len[n] + len[n - 1]); // 长度只需封顶到 1e18
        len.push_back(nxt_len);

        array<int64, 26> nxt_cnt{};
        for (int c = 0; c < 26; c++) {
            nxt_cnt[c] = cnt[n][c] + cnt[n - 1][c];
        }
        cnt.push_back(nxt_cnt);
    }

    int T = (int)len.size() - 1;

    auto get_prefix = [&](int64 p, int c) -> int64 {
        if (p <= 0) return 0;

        int64 ans = 0;
        int i = T;

        while (i > 2) {
            if (p <= len[i - 1]) {
                i = i - 1;
            } else {
                ans += cnt[i - 1][c];
                p -= len[i - 1];
                i = i - 2;
            }
        }

        if (i == 1) {
            ans += preX[p][c];
        } else {
            ans += preY[p][c];
        }

        return ans;
    };

    while (Q--) {
        int64 L, R;
        char C;
        cin >> L >> R >> C;
        int c = C - 'a';

        cout << get_prefix(R, c) - get_prefix(L - 1, c) << '\n';
    }

    return 0;
}