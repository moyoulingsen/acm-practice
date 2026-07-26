# ABC467 G - Many Sweets Problem

## 网址

https://atcoder.jp/contests/abc467/tasks/abc467_g

## 题解

每次查询先执行一次单点修改：

```text
A_c = x
```

然后在区间 `[l, r]` 中选尽量少的数，使选出的数的和至少为 `k`。如果总和都不到 `k`，输出 `-1`。

因为所有 `A_i` 都是正数，要让选出的数量最少，最优策略一定是优先选区间里数值最大的元素。

所以问题变成动态维护数组，并支持：

- 单点修改；
- 查询区间 `[l, r]` 内按值从大到小取，最少取几个能使和达到 `k`。

离线读入初始值和所有修改值，进行值域压缩。建立一棵按“数值大小”划分的线段树，每个值域节点里维护两个 Fenwick 树：

- `bit_cnt`：这个值域内，每个位置当前有多少个数；
- `bit_sum`：这个值域内，每个位置当前的数值总和。

单点修改时，在旧值对应的值域路径上删除位置 `c`，在新值对应的值域路径上加入位置 `c`。

查询时先求 `[l, r]` 的总和，如果小于 `k`，答案是 `-1`。否则从值域线段树根开始，优先看右儿子，也就是更大的值：

- 如果右儿子在 `[l, r]` 中的总和已经不少于 `k`，递归右儿子；
- 否则右儿子的数全部要选，再去左儿子中补剩下的和。

到叶子时所有数值相同，设值为 `v`，还需要 `need`，需要数量是：

```text
ceil(need / v)
```

时间复杂度：每次修改和查询 `O(log V log N)`，其中 `V` 是不同数值个数。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Query {
    int c, l, r;
    ll x, k;
};

struct Node {
    vector<int> pos;
    vector<int> bit_cnt;
    vector<ll> bit_sum;
};

struct ValueSegTree {
    int V;
    vector<ll> value;
    vector<Node> tree;

    ValueSegTree(const vector<ll>& value) : V((int)value.size()), value(value), tree(4 * V) {}

    void add_position(int v, int l, int r, int id, int p) {
        tree[v].pos.push_back(p);
        if (l == r) return;

        int m = (l + r) / 2;
        if (id <= m) add_position(v * 2, l, m, id, p);
        else add_position(v * 2 + 1, m + 1, r, id, p);
    }

    void prepare(int v, int l, int r) {
        auto& xs = tree[v].pos;
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        tree[v].bit_cnt.assign(xs.size() + 1, 0);
        tree[v].bit_sum.assign(xs.size() + 1, 0);

        if (l == r) return;
        int m = (l + r) / 2;
        prepare(v * 2, l, m);
        prepare(v * 2 + 1, m + 1, r);
    }

    void add_cnt(vector<int>& bit, int i, int x) {
        for (; i < (int)bit.size(); i += i & -i) bit[i] += x;
    }

    void add_sum(vector<ll>& bit, int i, ll x) {
        for (; i < (int)bit.size(); i += i & -i) bit[i] += x;
    }

    int sum_cnt(const vector<int>& bit, int i) {
        int res = 0;
        for (; i > 0; i -= i & -i) res += bit[i];
        return res;
    }

    ll sum_ll(const vector<ll>& bit, int i) {
        ll res = 0;
        for (; i > 0; i -= i & -i) res += bit[i];
        return res;
    }

    void apply(int v, int p, int delta_cnt, ll delta_sum) {
        auto& xs = tree[v].pos;
        int i = int(lower_bound(xs.begin(), xs.end(), p) - xs.begin()) + 1;
        add_cnt(tree[v].bit_cnt, i, delta_cnt);
        add_sum(tree[v].bit_sum, i, delta_sum);
    }

    void update(int v, int l, int r, int id, int p, int delta_cnt, ll delta_sum) {
        apply(v, p, delta_cnt, delta_sum);
        if (l == r) return;

        int m = (l + r) / 2;
        if (id <= m) update(v * 2, l, m, id, p, delta_cnt, delta_sum);
        else update(v * 2 + 1, m + 1, r, id, p, delta_cnt, delta_sum);
    }

    ll range_sum_node(int v, int L, int R) {
        auto& xs = tree[v].pos;
        int right = int(upper_bound(xs.begin(), xs.end(), R) - xs.begin());
        int left = int(lower_bound(xs.begin(), xs.end(), L) - xs.begin());
        return sum_ll(tree[v].bit_sum, right) - sum_ll(tree[v].bit_sum, left);
    }

    int range_count_node(int v, int L, int R) {
        auto& xs = tree[v].pos;
        int right = int(upper_bound(xs.begin(), xs.end(), R) - xs.begin());
        int left = int(lower_bound(xs.begin(), xs.end(), L) - xs.begin());
        return sum_cnt(tree[v].bit_cnt, right) - sum_cnt(tree[v].bit_cnt, left);
    }

    ll total_sum(int L, int R) {
        return range_sum_node(1, L, R);
    }

    ll solve(int v, int l, int r, int L, int R, ll need) {
        if (l == r) {
            return (need + value[l] - 1) / value[l];
        }

        int m = (l + r) / 2;
        int rc = v * 2 + 1;
        ll right_sum = range_sum_node(rc, L, R);

        if (right_sum >= need) {
            return solve(rc, m + 1, r, L, R, need);
        }

        int right_count = range_count_node(rc, L, R);
        return right_count + solve(v * 2, l, m, L, R, need - right_sum);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<ll> A(N), coords;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        coords.push_back(A[i]);
    }

    vector<Query> queries(Q);
    for (int q = 0; q < Q; q++) {
        cin >> queries[q].c >> queries[q].x >> queries[q].l >> queries[q].r >> queries[q].k;
        queries[q].c--;
        queries[q].l--;
        queries[q].r--;
        coords.push_back(queries[q].x);
    }

    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());

    auto id = [&](ll x) {
        return int(lower_bound(coords.begin(), coords.end(), x) - coords.begin());
    };

    ValueSegTree seg(coords);

    for (int i = 0; i < N; i++) {
        seg.add_position(1, 0, seg.V - 1, id(A[i]), i);
    }
    for (auto q : queries) {
        seg.add_position(1, 0, seg.V - 1, id(q.x), q.c);
    }

    seg.prepare(1, 0, seg.V - 1);

    vector<int> cur_id(N);
    vector<ll> cur_value = A;

    for (int i = 0; i < N; i++) {
        cur_id[i] = id(A[i]);
        seg.update(1, 0, seg.V - 1, cur_id[i], i, 1, A[i]);
    }

    for (auto q : queries) {
        int c = q.c;

        seg.update(1, 0, seg.V - 1, cur_id[c], c, -1, -cur_value[c]);
        cur_value[c] = q.x;
        cur_id[c] = id(q.x);
        seg.update(1, 0, seg.V - 1, cur_id[c], c, 1, cur_value[c]);

        ll sum_all = seg.total_sum(q.l, q.r);
        if (sum_all < q.k) {
            cout << -1 << '\n';
        } else {
            cout << seg.solve(1, 0, seg.V - 1, q.l, q.r, q.k) << '\n';
        }
    }

    return 0;
}
```

## 样例验证

代码每次都优先查询较大的值域，等价于从区间中按数值从大到小贪心选择。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
