#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

struct BIT {
    int n;
    vector<int> a;

    BIT(int n = 0) { init(n); }

    void init(int n_) {
        n = n_;
        a.assign(n + 1, 0);
    }

    void add(int i, int x) {
        i++; // 0-indexed -> 1-indexed
        while (i <= n) {
            a[i] += x;
            i += i & -i;
        }
    }

    int sum_prefix(int r) const {
        int s = 0;
        while (r > 0) {
            s += a[r];
            r -= r & -r;
        }
        return s;
    }

    int sum(int l, int r) const {
        return sum_prefix(r) - sum_prefix(l);
    }

    // minimize i such that sum_prefix(i) >= w
    // return 1-indexed position
    int lower_bound(int w) const {
        int x = 0;
        int k = 1;
        while ((k << 1) <= n) k <<= 1;
        while (k) {
            if (x + k <= n && a[x + k] < w) {
                w -= a[x + k];
                x += k;
            }
            k >>= 1;
        }
        return x + 1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        --a[i];
    }

    vector<int64> c(m, 0);
    for (int v : a) c[v]++;

    vector<pair<int64, int>> s;
    s.reserve(m);
    for (int i = 0; i < m; i++) {
        s.push_back({c[i], i});
    }
    sort(s.begin(), s.end());

    vector<long long> r(m + 1, 0);
    r[0] = n;
    for (int i = 0; i < m - 1; i++) {
        r[i + 1] = 1LL * (i + 1) * (s[i + 1].first - s[i].first) + r[i];
    }
    r[m] = (long long)1e18 + 2026;

    int q;
    cin >> q;

    vector<int> ans(q, -1);
    vector<tuple<int, int, int>> que; // (ok, x, query_index)

    for (int i = 0; i < q; i++) {
        long long x;
        cin >> x;

        if (x <= n) {
            ans[i] = a[x - 1];
            continue;
        }

        int ng = 0, ok = m;
        while (ok - ng != 1) {
            int vs = (ok + ng) >> 1;
            if (r[vs] >= x) ok = vs;
            else ng = vs;
        }

        x -= r[ng] + 1;
        x %= ok;
        que.emplace_back(ok, (int)x, i);
    }

    sort(que.begin(), que.end());

    BIT fw(m);
    int idx = 0;
    for (auto [ok, x, qi] : que) {
        while (idx < ok) {
            fw.add(s[idx].second, 1);
            idx++;
        }
        ans[qi] = fw.lower_bound(x + 1) - 1;
    }

    for (int v : ans) {
        cout << v + 1 << '\n';
    }

    return 0;
}
