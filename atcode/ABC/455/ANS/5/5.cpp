#include <bits/stdc++.h>
using namespace std;

struct Node {
    int l = 0, r = 0, p = 0;
    int sz = 1;
    uint32_t pri = 0;
};

static mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<Node> tr(N + 1);
    for (int i = 1; i <= N; ++i) {
        tr[i].pri = rng();
    }

    auto get_sz = [&](int x) -> int {
        return x ? tr[x].sz : 0;
    };

    auto pull = [&](int x) -> void {
        if (!x) return;
        tr[x].sz = get_sz(tr[x].l) + get_sz(tr[x].r) + 1;
        if (tr[x].l) tr[tr[x].l].p = x;
        if (tr[x].r) tr[tr[x].r].p = x;
    };

    function<int(int, int)> merge = [&](int a, int b) -> int {
        if (!a || !b) {
            int rt = a ? a : b;
            if (rt) tr[rt].p = 0;
            return rt;
        }
        if (tr[a].pri > tr[b].pri) {
            tr[a].r = merge(tr[a].r, b);
            if (tr[a].r) tr[tr[a].r].p = a;
            pull(a);
            tr[a].p = 0;
            return a;
        } else {
            tr[b].l = merge(a, tr[b].l);
            if (tr[b].l) tr[tr[b].l].p = b;
            pull(b);
            tr[b].p = 0;
            return b;
        }
    };

    function<pair<int, int>(int, int)> split = [&](int rt, int k) -> pair<int, int> {
        if (!rt) return {0, 0};
        if (get_sz(tr[rt].l) >= k) {
            auto [a, b] = split(tr[rt].l, k);
            tr[rt].l = b;
            if (b) tr[b].p = rt;
            pull(rt);
            if (a) tr[a].p = 0;
            tr[rt].p = 0;
            return {a, rt};
        } else {
            auto [a, b] = split(tr[rt].r, k - get_sz(tr[rt].l) - 1);
            tr[rt].r = a;
            if (a) tr[a].p = rt;
            pull(rt);
            if (b) tr[b].p = 0;
            tr[rt].p = 0;
            return {rt, b};
        }
    };

    auto get_root = [&](int x) -> int {
        while (tr[x].p) x = tr[x].p;
        return x;
    };

    auto get_rank = [&](int x) -> int {
        int res = get_sz(tr[x].l) + 1;
        while (tr[x].p) {
            int fa = tr[x].p;
            if (tr[fa].r == x) {
                res += get_sz(tr[fa].l) + 1;
            }
            x = fa;
        }
        return res;
    };

    for (int i = 0; i < Q; ++i) {
        int C, P;
        cin >> C >> P;

        int root_c = get_root(C);
        int root_p = get_root(P);
        int pos_c = get_rank(C);

        auto [left_part, moved_part] = split(root_c, pos_c - 1);
        merge(root_p, moved_part);
    }

    for (int i = 1; i <= N; ++i) {
        int pos = get_rank(i);
        if (pos == 1) {
            cout << tr[get_root(i)].sz;
        } else {
            cout << 0;
        }
        cout << (i == N ? '\n' : ' ');
    }

    return 0;
}
