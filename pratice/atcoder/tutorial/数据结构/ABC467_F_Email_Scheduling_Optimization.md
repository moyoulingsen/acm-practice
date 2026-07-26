# ABC467 F - Email Scheduling Optimization

## 网址

https://atcoder.jp/contests/abc467/tasks/abc467_f

## 题解

一封邮件需要先花 `A_i` 分钟写完，发出后再过 `B_i` 分钟收到回复。写邮件不能并行，发送本身不耗时。目标是安排写邮件顺序，使收到所有回复的时间最早。

对于固定的 `A, B`，最优顺序是按 `B_i` 从大到小写。因为如果相邻两封邮件 `i, j` 满足 `B_i < B_j`，但 `i` 排在 `j` 前面，交换它们不会让最大完成时间变差。

排序后答案是：

```text
max(prefix_sum_A + B_i)
```

其中顺序按 `B_i` 降序。

有单点修改，所以把相同 `B` 的邮件合并成一组。设某个 `B` 值对应的总写作时间为 `sumA[B]`，则答案是：

```text
max over B of (sum of sumA[B'] for B' >= B) + B
```

离线读入所有查询，压缩所有可能出现的 `B`。线段树按 `B` 从小到大维护，每个节点保存：

- `sum`：区间内所有 `A` 的总和；
- `best`：只考虑该区间，按 `B` 降序处理时的最大 `prefix_sum + B`。

合并左右儿子时，右儿子代表更大的 `B`，所以先处理右儿子：

```text
sum = left.sum + right.sum
best = max(right.best, right.sum + left.best)
```

时间复杂度：每次修改 `O(log(N + Q))`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll NEG = -(1LL << 60);

struct Query {
    int type, i;
    ll x;
};

struct Node {
    ll sum = 0;
    ll best = NEG;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<ll> A(N), B(N), coords;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) {
        cin >> B[i];
        coords.push_back(B[i]);
    }

    vector<Query> queries(Q);
    for (int q = 0; q < Q; q++) {
        cin >> queries[q].type >> queries[q].i >> queries[q].x;
        queries[q].i--;
        if (queries[q].type == 2) coords.push_back(queries[q].x);
    }

    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());

    auto id = [&](ll x) {
        return int(lower_bound(coords.begin(), coords.end(), x) - coords.begin());
    };

    int V = coords.size();
    vector<ll> group_sum(V, 0);
    vector<int> bid(N);

    for (int i = 0; i < N; i++) {
        bid[i] = id(B[i]);
        group_sum[bid[i]] += A[i];
    }

    vector<Node> seg(4 * V);

    auto pull = [&](int v) {
        seg[v].sum = seg[v * 2].sum + seg[v * 2 + 1].sum;
        seg[v].best = max(seg[v * 2 + 1].best, seg[v * 2 + 1].sum + seg[v * 2].best);
    };

    function<void(int, int, int)> build = [&](int v, int l, int r) {
        if (l == r) {
            seg[v].sum = group_sum[l];
            seg[v].best = group_sum[l] > 0 ? group_sum[l] + coords[l] : NEG;
            return;
        }

        int m = (l + r) / 2;
        build(v * 2, l, m);
        build(v * 2 + 1, m + 1, r);
        pull(v);
    };

    function<void(int, int, int, int)> update = [&](int v, int l, int r, int p) {
        if (l == r) {
            seg[v].sum = group_sum[l];
            seg[v].best = group_sum[l] > 0 ? group_sum[l] + coords[l] : NEG;
            return;
        }

        int m = (l + r) / 2;
        if (p <= m) update(v * 2, l, m, p);
        else update(v * 2 + 1, m + 1, r, p);
        pull(v);
    };

    build(1, 0, V - 1);

    for (auto q : queries) {
        int i = q.i;

        if (q.type == 1) {
            group_sum[bid[i]] += q.x - A[i];
            A[i] = q.x;
            update(1, 0, V - 1, bid[i]);
        } else {
            int old_id = bid[i];
            int new_id = id(q.x);

            group_sum[old_id] -= A[i];
            update(1, 0, V - 1, old_id);

            B[i] = q.x;
            bid[i] = new_id;
            group_sum[new_id] += A[i];
            update(1, 0, V - 1, new_id);
        }

        cout << seg[1].best << '\n';
    }

    return 0;
}
```

## 样例验证

代码用线段树动态维护按 `B` 降序排序后的最大完成时间，每次修改后直接输出根节点答案。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
