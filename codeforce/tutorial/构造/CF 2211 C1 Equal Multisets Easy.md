# CF 2211 C1 - Equal Multisets (Easy Version)

**题目链接**：<https://codeforces.com/problemset/problem/2211/C1>

**对应题单**：Codeforces Round 1088 C1

**题型**：构造 / 置换 / 区间限制

**难度**：1300（绿）

---

## 题意压缩

给定长度为 `n` 的数组 `a` 和部分给定的数组 `b`，未知位置为 `-1`。问能否补全 `b`，使它满足题目给出的所有长度为 `k` 的窗口限制。

Easy 版本中，`a` 是一个排列。

---

## 关键观察

在所有长度为 `k` 的窗口中，只有中间那段位置会同时出现在所有窗口里：

\[
[n-k,\ k-1]
\]

这里用的是 0-index。

- 不在这段交集里的位置没有自由度，若 `b[i]` 已知，必须等于 `a[i]`；
- 在交集里的位置可以重排，但只能使用 `a` 在这段交集里的那些值，并且排列里不能重复。

如果 `n-k > k-1`，交集为空，那么所有已知位置都必须直接等于 `a[i]`。

---

## 思路步骤

1. 令 `L = n-k, R = k-1`。
2. 扫描所有位置：
   - 若 `b[i] = -1`，跳过；
   - 若 `i` 不在 `[L,R]`，检查 `b[i] == a[i]`；
   - 若 `i` 在 `[L,R]`，检查 `b[i]` 是否属于 `a[L..R]`，且没有重复出现。
3. 全部满足则输出 `YES`。

---

## 易错点

- `[L,R]` 可能为空。
- 中间段不是任意填数，只能填来自 `a` 中间段的值。
- Easy 版本 `a` 是排列，所以只需要判重复即可。

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;

        int L = n - k, R = k - 1;
        bool ok = true;
        set<int> can, used;
        if (L <= R) {
            for (int i = L; i <= R; ++i) can.insert(a[i]);
        }

        for (int i = 0; i < n; ++i) {
            if (b[i] == -1) continue;
            if (L <= i && i <= R) {
                if (!can.count(b[i]) || used.count(b[i])) ok = false;
                used.insert(b[i]);
            } else {
                if (b[i] != a[i]) ok = false;
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}
```

---

## 一句话总结

只有所有长度 `k` 窗口的公共交集有重排自由，其他位置已知时必须和 `a` 完全一致。
