# ABC455 F - Merge Slimes 2

## 网址

https://atcoder.jp/contests/abc455/tasks/abc455_f

## 题解

合并若干史莱姆时，每次合并 `x,y` 的代价是 `x*y`。最终总代价与合并顺序无关，恒为：

```text
((sum B_i)^2 - sum(B_i^2)) / 2
```

所以每次查询只需要：

1. 对区间加 `a`；
2. 查询该区间的元素和 `sum` 与平方和 `sq`。

区间加 `x` 时：

```text
sum' = sum + len * x
sq'  = sq + 2*x*sum + len*x^2
```

用懒标记线段树维护即可。

时间复杂度：`O((N+Q) log N)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 998244353;
const ll INV2 = (MOD + 1) / 2;

struct Node {
    ll len = 0;
    ll sum = 0;
    ll sq = 0;
};

Node merge_node(const Node &a, const Node &b) {
    return {(a.len + b.len) % MOD, (a.sum + b.sum) % MOD, (a.sq + b.sq) % MOD};
}

struct SegTree {
    int n;
    vector<Node> seg;
    vector<ll> lazy;

    SegTree(int n_) : n(n_), seg(4 * n_), lazy(4 * n_) {
        build(1, 0, n);
    }

    void build(int idx, int l, int r) {
        seg[idx].len = r - l;
        if (r - l == 1) return;
        int m = (l + r) / 2;
        build(idx * 2, l, m);
        build(idx * 2 + 1, m, r);
    }

    void apply(int idx, ll x) {
        x %= MOD;
        ll old_sum = seg[idx].sum;
        seg[idx].sq = (seg[idx].sq + 2 * x % MOD * old_sum + seg[idx].len * x % MOD * x) % MOD;
        seg[idx].sum = (seg[idx].sum + seg[idx].len * x) % MOD;
        lazy[idx] = (lazy[idx] + x) % MOD;
    }

    void push(int idx) {
        if (lazy[idx] == 0) return;
        apply(idx * 2, lazy[idx]);
        apply(idx * 2 + 1, lazy[idx]);
        lazy[idx] = 0;
    }

    void range_add(int ql, int qr, ll x) {
        range_add(1, 0, n, ql, qr, x);
    }

    void range_add(int idx, int l, int r, int ql, int qr, ll x) {
        if (qr <= l || r <= ql) return;
        if (ql <= l && r <= qr) {
            apply(idx, x);
            return;
        }

        push(idx);
        int m = (l + r) / 2;
        range_add(idx * 2, l, m, ql, qr, x);
        range_add(idx * 2 + 1, m, r, ql, qr, x);
        seg[idx] = merge_node(seg[idx * 2], seg[idx * 2 + 1]);
    }

    Node query(int ql, int qr) {
        return query(1, 0, n, ql, qr);
    }

    Node query(int idx, int l, int r, int ql, int qr) {
        if (qr <= l || r <= ql) return Node{};
        if (ql <= l && r <= qr) return seg[idx];

        push(idx);
        int m = (l + r) / 2;
        return merge_node(query(idx * 2, l, m, ql, qr), query(idx * 2 + 1, m, r, ql, qr));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    SegTree seg(N);

    while (Q--) {
        int l, r;
        ll a;
        cin >> l >> r >> a;
        --l;

        seg.range_add(l, r, a);
        Node res = seg.query(l, r);

        ll ans = (res.sum * res.sum % MOD - res.sq + MOD) % MOD;
        ans = ans * INV2 % MOD;

        cout << ans << '\n';
    }

    return 0;
}
```

## 样例验证

```text
输入
5 4
1 3 22
3 4 13
5 5 455
1 5 1000000000

输出
1452
455
0
21421644
```
