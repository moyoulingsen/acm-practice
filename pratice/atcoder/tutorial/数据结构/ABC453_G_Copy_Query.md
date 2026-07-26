# ABC453 G - Copy Query

## 网址

https://atcoder.jp/contests/abc453/tasks/abc453_g

## 题解

每个序列用一棵可持久化线段树的根指针表示。

- 初始所有序列共用同一棵全零线段树根；
- `1 X Y`：复制序列，只需 `root[X] = root[Y]`；
- `2 X Y Z`：对 `root[X]` 做可持久化单点赋值，沿路径复制 `O(log M)` 个节点；
- `3 X L R`：在 `root[X]` 上做区间和查询。

这样不需要真正复制整行。

时间复杂度：

- 复制：`O(1)`；
- 单点赋值 / 区间查询：`O(log M)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct PersistentSegTree {
    struct Node {
        ll sum;
        int left, right;
    };

    int n;
    vector<Node> tr;

    PersistentSegTree(int n_) : n(n_) {
        tr.reserve(n * 2 + 4000000);
    }

    int build(int l, int r) {
        int id = (int)tr.size();
        tr.push_back({0, -1, -1});

        if (l + 1 == r) return id;

        int m = (l + r) / 2;
        tr[id].left = build(l, m);
        tr[id].right = build(m, r);
        return id;
    }

    int set_value(int node, int l, int r, int pos, ll val) {
        int id = (int)tr.size();
        tr.push_back(tr[node]);

        if (l + 1 == r) {
            tr[id].sum = val;
            return id;
        }

        int m = (l + r) / 2;
        if (pos < m) tr[id].left = set_value(tr[node].left, l, m, pos, val);
        else tr[id].right = set_value(tr[node].right, m, r, pos, val);

        tr[id].sum = tr[tr[id].left].sum + tr[tr[id].right].sum;
        return id;
    }

    ll query(int node, int l, int r, int ql, int qr) const {
        if (qr <= l || r <= ql) return 0;
        if (ql <= l && r <= qr) return tr[node].sum;

        int m = (l + r) / 2;
        return query(tr[node].left, l, m, ql, qr)
             + query(tr[node].right, m, r, ql, qr);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, Q;
    cin >> N >> M >> Q;

    PersistentSegTree seg(M);
    int zero_root = seg.build(0, M);

    vector<int> root(N, zero_root);

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int X, Y;
            cin >> X >> Y;
            --X;
            --Y;
            root[X] = root[Y];
        } else if (type == 2) {
            int X, Y;
            ll Z;
            cin >> X >> Y >> Z;
            --X;
            --Y;
            root[X] = seg.set_value(root[X], 0, M, Y, Z);
        } else {
            int X, L, R;
            cin >> X >> L >> R;
            --X;
            --L;
            cout << seg.query(root[X], 0, M, L, R) << '\n';
        }
    }

    return 0;
}
```

## 样例验证

```text
输入
4 5 10
2 2 1 2
2 2 2 7
2 2 4 8
1 1 2
2 2 3 1
1 3 2
2 3 2 10
3 1 2 4
3 2 1 4
3 3 2 2

输出
15
18
10
```
