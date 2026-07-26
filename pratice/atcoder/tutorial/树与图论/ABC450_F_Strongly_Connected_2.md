# ABC450 F - Strongly Connected 2

## 网址

https://atcoder.jp/contests/abc450/tasks/abc450_f

## 题解

固定边 `i+1 -> i` 能让任意点一路走回 `1`，所以整张图强连通等价于：从点 `1` 能到达所有点。

把可选边按 `X` 从小到大处理。令 `dp[r]` 表示当前从 `1` 能到达的最大编号是 `r` 的方案数。

处理边 `(x, y)`：

- 如果当前 `r < x`，源点不可达，选这条边也没用；
- 如果 `x <= r < y`，选这条边会把最大可达位置更新成 `y`；
- 如果 `r >= y`，选或不选都不改变最大可达位置，因此这些状态乘 2。

需要支持区间求和、区间乘 2、单点加，用懒标记线段树优化。

时间复杂度：`O((N+M) log N)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

struct SegTree {
    int n;
    vector<long long> sum, lazy;

    SegTree(int sz) {
        n = 1;
        while (n < sz) n <<= 1;
        sum.assign(n * 2, 0);
        lazy.assign(n * 2, 1);
    }

    void apply(int p, long long mul) {
        sum[p] = sum[p] * mul % MOD;
        lazy[p] = lazy[p] * mul % MOD;
    }

    void push(int p) {
        if (lazy[p] == 1) return;
        apply(p * 2, lazy[p]);
        apply(p * 2 + 1, lazy[p]);
        lazy[p] = 1;
    }

    void range_mul(int ql, int qr, long long mul, int p, int l, int r) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            apply(p, mul);
            return;
        }
        push(p);
        int m = (l + r) / 2;
        range_mul(ql, qr, mul, p * 2, l, m);
        range_mul(ql, qr, mul, p * 2 + 1, m + 1, r);
        sum[p] = (sum[p * 2] + sum[p * 2 + 1]) % MOD;
    }

    void range_mul(int l, int r, long long mul) {
        if (l <= r) range_mul(l, r, mul, 1, 1, n);
    }

    void point_add(int pos, long long val, int p, int l, int r) {
        if (l == r) {
            sum[p] = (sum[p] + val) % MOD;
            return;
        }
        push(p);
        int m = (l + r) / 2;
        if (pos <= m) point_add(pos, val, p * 2, l, m);
        else point_add(pos, val, p * 2 + 1, m + 1, r);
        sum[p] = (sum[p * 2] + sum[p * 2 + 1]) % MOD;
    }

    void point_add(int pos, long long val) {
        point_add(pos, val, 1, 1, n);
    }

    long long query(int ql, int qr, int p, int l, int r) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return sum[p];
        push(p);
        int m = (l + r) / 2;
        return (query(ql, qr, p * 2, l, m) + query(ql, qr, p * 2 + 1, m + 1, r)) % MOD;
    }

    long long query(int l, int r) {
        if (l > r) return 0;
        return query(l, r, 1, 1, n);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> edges(M);
    for (auto &[x, y] : edges) cin >> x >> y;
    sort(edges.begin(), edges.end());

    SegTree seg(N);
    seg.point_add(1, 1);

    for (auto [x, y] : edges) {
        long long add = seg.query(x, y);
        seg.range_mul(y + 1, N, 2);
        seg.point_add(y, add);
    }

    cout << seg.query(N, N) << '\n';
    return 0;
}
```

## 样例验证

代码实现的是按最大可达点做 DP 的线段树优化版本。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
