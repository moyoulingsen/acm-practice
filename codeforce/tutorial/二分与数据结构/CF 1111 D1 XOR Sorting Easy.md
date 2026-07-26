# CF 1111 D1 - XOR Sorting (Easy Version)

**真实题号**：CF 2247 D1

**题目链接**：<https://codeforces.com/problemset/problem/2247/D1>

**题型**：位运算 / 分块 / 贪心

**难度体感**：D1 重点在看懂 `i xor j <= k` 对下标连通性的影响。

---

## 题意压缩

给定数组 `a`。

定义 `f(a)` 为最小的 `k`，使得可以通过若干次交换把数组排序。

一次交换允许选择两个下标 `i,j`，要求：

\[
i\oplus j \le k
\]

D1 中没有修改操作，只要求输出初始数组的 `f(a)`。

---

## 关键观察 1：答案只可能是 0 或 2 的幂

如果数组本来已经非降序，那么答案是 `0`。

否则，设：

\[
2^b \le k < 2^{b+1}
\]

在这个范围内，允许交换形成的连通块结构是一样的。

因为下标之间能通过 xor 掩码 `1,2,4,...,2^b` 连起来，同一个长度为 `2^{b+1}` 的对齐块内部是连通的。

所以最小答案只会取每段范围的左端点，也就是某个：

\[
2^b
\]

---

## 关键观察 2：给定 k 时怎么判定

如果 `k` 是 `2` 的幂，那么每个连通块长度是：

```text
2k
```

每个块内部可以任意重排，但块和块之间不能交换。

因此数组能被整体排序，当且仅当每个块的值域不交叉：

```text
max(block_i) <= min(block_{i+1})
```

如果前一个块的最大值大于后一个块的最小值，就说明必须跨块交换，但当前 `k` 做不到。

---

## 思路步骤

1. 如果数组已经有序，输出 `0`。
2. 枚举 `k=1,2,4,...`。
3. 对每个 `k`，按长度 `2k` 分块。
4. 统计每块最小值、最大值。
5. 如果相邻块都满足 `prevMax <= curMin`，输出这个 `k`。

---

## 复杂度

每个 `k` 扫一遍数组，`k` 枚举 `O(log n)` 个：

\[
O(n\log n)
\]

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    const ll INF = (1LL << 62);

    while (T--) {
        int n, q;
        cin >> n >> q;

        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        bool sorted = true;
        for (int i = 1; i < n; ++i) {
            if (a[i - 1] > a[i]) sorted = false;
        }

        if (sorted) {
            cout << 0 << '\n';
            continue;
        }

        auto ok = [&](int k) {
            int block = 2 * k;
            ll prevMax = -INF;
            bool first = true;

            for (int l = 0; l < n; l += block) {
                int r = min(n, l + block);
                ll mn = INF, mx = -INF;

                for (int i = l; i < r; ++i) {
                    mn = min(mn, a[i]);
                    mx = max(mx, a[i]);
                }

                if (!first && prevMax > mn) return false;
                first = false;
                prevMax = mx;
            }
            return true;
        };

        for (int k = 1; ; k <<= 1) {
            if (ok(k)) {
                cout << k << '\n';
                break;
            }
        }
    }
    return 0;
}
```

---

## 一句话总结

这题就是：**`k=2^b` 时每个长度 `2k` 的块内能任意重排，只要块间值域不交叉就能排序。**
