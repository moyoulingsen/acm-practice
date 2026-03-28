#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

// P(X, Y) = number of pairs (x, y) with 0 <= x <= X, 0 <= y <= Y
// and max(x, y) is even.
long long P(long long X, long long Y) {
    if (X < 0 || Y < 0) return 0;
    if (X > Y) swap(X, Y);

    long long m = X / 2;
    // black points in [0, X] x [0, X]
    long long square = 2 * m * m + 3 * m + 1;

    // even y in [X+1, Y]
    long long even_cnt = Y / 2 - X / 2;
    long long strip = (X + 1) * even_cnt;

    return square + strip;
}

// H(a,b,c,d) for nonnegative rectangle
long long H(long long a, long long b, long long c, long long d) {
    if (a > b || c > d) return 0;
    return P(b, d) - P(a - 1, d) - P(b, c - 1) + P(a - 1, c - 1);
}

int main() {
    long long L, R, D, U;
    cin >> L >> R >> D >> U;

    long long ans = 0;

    // x = 0?
    bool x0 = (L <= 0 && 0 <= R);
    // y = 0?
    bool y0 = (D <= 0 && 0 <= U);

    // positive abs ranges (>0)
    vector<pair<long long,long long>> xs, ys;

    // x absolute-value ranges with multiplicity
    if (L <= -1) xs.push_back({1, -L}); // negative x
    if (R >= 1)  xs.push_back({1, R});  // positive x

    if (D <= -1) ys.push_back({1, -D}); // negative y
    if (U >= 1)  ys.push_back({1, U});  // positive y

    // both |x|>0 and |y|>0 : each abs pair corresponds to 1 original point in each chosen sign block
    for (auto [xl, xr] : xs) {
        for (auto [yl, yr] : ys) {
            ans += H(xl, xr, yl, yr);
        }
    }

    // x = 0, |y|>0
    if (x0) {
        for (auto [yl, yr] : ys) {
            ans += H(0, 0, yl, yr);
        }
    }

    // |x|>0, y = 0
    if (y0) {
        for (auto [xl, xr] : xs) {
            ans += H(xl, xr, 0, 0);
        }
    }

    // x = 0, y = 0
    if (x0 && y0) {
        ans += 1; // (0,0) is black
    }

    cout << ans << '\n';
    return 0;
}
