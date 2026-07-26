# CF 1111 D2 - XOR Sorting (Hard Version)

**真实题号**：CF 2247 D2

**题目链接**：<https://codeforces.com/problemset/problem/2247/D2>

**题型**：线段树 / 位运算 / 分治结构

**难度体感**：Hard 的重点是把 D1 的分块判定改成可维护的线段树信息。

---

## 题意压缩

给定数组 `a`，并有 `q` 次单点修改。

每次都要输出当前数组的 `f(a)`。

`f(a)` 的定义和 D1 一样：最小的 `k`，使得能通过交换满足 `i xor j <= k` 的位置，把数组排序。

---

## 核心结论

答案等于所有“必须跨越的二进制分割线”的最大半长。

考虑一个长度为 `2h` 的对齐区间：

```text
左半 [l, l+h-1]
右半 [l+h, l+2h-1]
```

如果：

```text
max(左半) > min(右半)
```

说明排序时一定有元素需要从左半和右半之间跨过去。

而跨越这条边界所需要的最小 xor 阈值正好是：

```text
h
```

所以当前分割线会要求答案至少为 `h`。

把所有这样的分割线取最大值，就是 `f(a)`。

---

## 线段树维护什么

把数组长度补到二的幂 `S`。

线段树每个节点表示一个对齐区间，维护：

```cpp
mn  // 这个区间里的最小值
mx  // 这个区间里的最大值
ans // 这个区间内部需要的最大 k
```

合并两个儿子 `L,R` 时：

```cpp
mn = min(L.mn, R.mn)
mx = max(L.mx, R.mx)
ans = max(L.ans, R.ans)

if (L.mx > R.mn) ans = max(ans, 当前区间长度 / 2)
```

这个合并正好对应上面的二进制分割线判断。

---

## 为什么根节点 ans 就是答案

线段树的每个内部节点，都对应一个长度为二的幂的对齐区间。

它的左右儿子就是某条二进制分割线。

所有可能影响答案的分割线都会在线段树中出现一次。

所以根节点维护的最大要求，就是整个数组的 `f(a)`。

---

## 空位置怎么处理

如果 `n` 不是二的幂，需要补到 `S`。

补出来的空叶子设为：

```cpp
mn = +INF
mx = -INF
ans = 0
```

这样不会影响真实元素的最小值、最大值和答案。

---

## 复杂度

建树：

\[
O(S)
\]

每次单点修改：

\[
O(\log S)
\]

总复杂度：

\[
O((n+q)\log n)
\]

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Node {
    ll mn;
    ll mx;
    int ans;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    const ll INF = (1LL << 62);

    while (T--) {
        int n, q;
        cin >> n >> q;

        int S = 1;
        while (S < n) S <<= 1;

        vector<Node> seg(2 * S, {INF, -INF, 0});
        vector<int> len(2 * S, 1);

        for (int i = 0; i < n; ++i) {
            ll x;
            cin >> x;
            seg[S + i] = {x, x, 0};
        }

        auto pull = [&](int v) {
            Node L = seg[v << 1];
            Node R = seg[v << 1 | 1];

            seg[v].mn = min(L.mn, R.mn);
            seg[v].mx = max(L.mx, R.mx);
            seg[v].ans = max(L.ans, R.ans);

            if (L.mx > R.mn) {
                seg[v].ans = max(seg[v].ans, len[v] / 2);
            }
        };

        for (int v = S - 1; v >= 1; --v) {
            len[v] = len[v << 1] + len[v << 1 | 1];
            pull(v);
        }

        cout << seg[1].ans << '\n';

        while (q--) {
            int p;
            ll x;
            cin >> p >> x;

            int v = S + p;
            seg[v] = {x, x, 0};

            for (v >>= 1; v >= 1; v >>= 1) {
                pull(v);
            }

            cout << seg[1].ans << '\n';
        }
    }
    return 0;
}
```

---

## 一句话总结

这题就是：**线段树每个节点判断“左半最大值是否大于右半最小值”，若是就要求答案至少为半区间长度。**
