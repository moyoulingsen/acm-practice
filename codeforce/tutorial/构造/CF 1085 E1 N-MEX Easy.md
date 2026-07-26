# CF 1085 E1 - N-MEX (Constructive Version)

**真实题号**：CF 2207 E1

**题目链接**：<https://codeforces.com/problemset/problem/2207/E1>

**题型**：构造 / 贪心 / mex

**难度体感**：2100，关键是理解前缀的 `k-mex` 约束。

---

## 题意压缩

给定数组 `a`，要求构造一个数组 `b`。

对每个前缀 `b[1..i]`，它的某种 `k-mex` 必须等于 `a[i]`。

E1 只要求判断是否存在，并构造一个合法数组。

---

## 什么是 k-mex

可以把 `k-mex` 理解成：

> 第 `k` 小的没有出现过的非负整数。

普通 mex 就是第 `1` 小的缺失非负整数。

在这题第 `i` 个前缀里，询问的 `k` 会随着 `i` 变化。

---

## 必要条件 1：范围限制

用 0-index 看第 `i` 个位置。

此时要求的是第 `n-i` 小的缺失数为 `a[i]`。

第 `n-i` 小的缺失数至少是：

\[
n-i-1
\]

同时题目只关心 `0..n` 这个范围，因此必须有：

\[
n-i-1 \le a_i \le n
\]

---

## 必要条件 2：单调不增

前缀越长，出现过的数越多，缺失集合只会变少。

同时查询的是越来越靠前的缺失数。

所以 `a[i]` 不可能比 `a[i-1]` 更大，必须满足：

\[
a_i \le a_{i-1}
\]

---

## 构造思路

所有在 `a` 中出现过的数，都必须保持缺失。

否则某个前缀的 `k-mex` 就会被破坏。

所以先建一个集合：

```text
available = {0,1,...,n-1} 中没有在 a 里出现的数
```

从左到右构造 `b`：

- 如果 `a[i] < prev`，说明目标 mex 下降了，这个位置可以放一个很大的数，例如 `1e9`；
- 如果 `a[i] == prev`，说明目标 mex 没变，需要消耗一个小于 `a[i]` 的缺失数，选 available 中 `<a[i]` 的最大值。

选最大的好处是尽量不影响后面更小的限制。

---

## 思路步骤

1. 检查 `n-i-1 <= a[i] <= n`。
2. 检查 `a` 是否单调不增。
3. 建立可用集合 `available`。
4. 从左到右构造：
   - 下降时填 `1e9`；
   - 不下降时从 `available` 里取 `<a[i]` 的最大值。
5. 如果中途取不到数，输出 `NO`。

---

## 复杂度

使用 `set`：

\[
O(n\log n)
\]

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

const int BIG = 1000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vector<int> a(n);
        bool ok = true;
        for (int i = 0; i < n; ++i) cin >> a[i];

        for (int i = 0; i < n; ++i) {
            if (a[i] < n - i - 1 || a[i] > n) ok = false;
            if (i > 0 && a[i] > a[i - 1]) ok = false;
        }

        if (!ok) {
            cout << "NO\n";
            continue;
        }

        vector<int> in_a(n + 1, 0);
        for (int x : a) {
            if (0 <= x && x <= n) in_a[x] = 1;
        }

        set<int> available;
        for (int x = 0; x < n; ++x) {
            if (!in_a[x]) available.insert(x);
        }

        vector<int> b(n);
        int prev = n;

        for (int i = 0; i < n; ++i) {
            if (a[i] < prev) {
                b[i] = BIG;
            } else {
                auto it = available.lower_bound(a[i]);
                if (it == available.begin()) {
                    ok = false;
                    break;
                }
                --it;
                b[i] = *it;
                available.erase(it);
            }
            prev = a[i];
        }

        if (!ok) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            cout << b[i] << " \n"[i + 1 == n];
        }
    }
    return 0;
}
```

---

## 一句话总结

这题就是：**先检查 `a` 的范围和单调性，再把不在 `a` 里的小数按需要填进 `b`。**
