**题解（D - Card Pile Query）**

把每一堆牌看成一个从下到上的序列。

一次操作：

- 取出 `C` 以及它上面的所有牌
- 并保持顺序，接到 `P` 的上面

题目还保证了操作前 `P` 一定是其所在牌堆的最上面一张，所以这次操作其实就是：

- 从 `C` 所在序列中，切下一个后缀
- 把这个后缀拼接到 `P` 所在序列的末尾

这正是一个典型的“动态维护序列 + 分裂 + 合并”问题，适合用**隐式 Treap**。

---

**Treap 中维护什么**

每张牌对应 Treap 的一个节点，Treap 的中序顺序就是这堆牌从下到上的顺序。

需要支持：

1. 找到某张牌所在的 Treap 根
2. 求某张牌在当前序列中的位置
3. 按位置分裂
4. 合并两个序列

于是对一次操作 `(C, P)`：

1. 找到 `C` 所在序列，设 `C` 的位置为 `pos`
2. 将这个序列按 `pos-1` 分裂成：
   - 左半部分：`C` 下方的牌
   - 右半部分：从 `C` 到栈顶的整段
3. 找到 `P` 所在序列
4. 将 `P` 所在序列与“右半部分”合并

复杂度是每次 `O(log N)`。

---

**为什么最后输出时这样判断**

初始时第 `i` 堆只有牌 `i`，并且牌堆底牌永远不会改变：

- 如果某次把底牌也搬走了，那么这堆就永久变空
- 否则这堆的底牌始终还是原来的那张牌

所以最终：

- 如果牌 `i` 在其当前序列中的位置是 `1`，说明它仍然是某一堆的底牌，那么第 `i` 堆的大小就是这个 Treap 的大小
- 否则说明原来的第 `i` 堆已经空了，答案是 `0`

---

**时间复杂度**

- 每次操作：`O(log N)`
- 总复杂度：`O((N+Q) log N)`

可以通过 `N,Q ≤ 3×10^5`。

---

**C++ 代码**

```cpp
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
```
