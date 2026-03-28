#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using i128 = __int128_t;

struct Fenwick {
    int n;
    vector<int> bit;
    Fenwick(int n = 0) { init(n); }
    void init(int n_) {
        n = n_;
        bit.assign(n + 1, 0);
    }
    void add(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) bit[idx] += val;
    }
    int sumPrefix(int idx) const {
        int s = 0;
        for (; idx > 0; idx -= idx & -idx) s += bit[idx];
        return s;
    }
    // 返回第k小的位置（1-indexed）
    int kth(int k) const {
        int pos = 0;
        int pw = 1;
        while ((pw << 1) <= n) pw <<= 1;
        for (int d = pw; d > 0; d >>= 1) {
            int np = pos + d;
            if (np <= n && bit[np] < k) {
                pos = np;
                k -= bit[np];
            }
        }
        return pos + 1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> A(N + 1);
    vector<int64> cnt(M + 1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        cnt[A[i]]++;
    }

    vector<pair<int64,int>> vp;
    vp.reserve(M);
    for (int v = 1; v <= M; v++) {
        vp.push_back({cnt[v], v});
    }
    sort(vp.begin(), vp.end()); // 先按cnt，再按v

    vector<int64> c(M + 1);
    vector<int> id(M + 1);
    for (int i = 1; i <= M; i++) {
        c[i] = vp[i - 1].first;
        id[i] = vp[i - 1].second;
    }

    // S[k] = 前k层总共用了多少步，k=0..M-1
    vector<i128> S(M, 0); // S[0]=0
    for (int k = 1; k < M; k++) {
        i128 need = (i128)k * (c[k + 1] - c[k]);
        S[k] = S[k - 1] + need;
    }

    int Q;
    cin >> Q;

    vector<int64> ans(Q);

    // 离线：bucket[k] 存放落在第k层的查询 (r, idx)
    vector<vector<pair<int,int>>> bucket(M + 1);

    for (int qi = 0; qi < Q; qi++) {
        long long X;
        cin >> X;
        if (X <= N) {
            ans[qi] = A[X];
            continue;
        }

        i128 K = (i128)X - N;

        if (M == 1) {
            ans[qi] = 1;
            continue;
        }

        if (K > S[M - 1]) {
            // 最终循环阶段：1..M
            i128 rem = K - S[M - 1];
            ans[qi] = (long long)((rem - 1) % M) + 1;
        } else {
            // 找最小k使 S[k] >= K
            int l = 1, r = M - 1, pos = M - 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (S[mid] >= K) {
                    pos = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            i128 prev = S[pos - 1];
            i128 rem = K - prev;
            int kth = (int)((rem - 1) % pos) + 1;
            bucket[pos].push_back({kth, qi});
        }
    }

    // Fenwick离线维护前k个id中的第r小值
    Fenwick fw(M);
    for (int k = 1; k <= M; k++) {
        fw.add(id[k], 1);
        for (auto [rk, qi] : bucket[k]) {
            ans[qi] = fw.kth(rk);
        }
    }

    for (int i = 0; i < Q; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}
