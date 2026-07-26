# CF 1096 E - It All Went Sideways

**真实题号**：CF 2227 E

**题目链接**：<https://codeforces.com/problemset/problem/2227/E>

**题型**：贪心 / 后缀最小值 / 贡献统计

**难度体感**：1400，关键是把移动方块数转成“不会动的方块数”。

---

## 题意压缩

给定每一列的高度 `a[i]`。

方块会因为高度差向侧面移动。你可以选择一列，把它的高度减少 `1`，问最多能让多少个方块发生移动。

---

## 关键观察

从左往右看，第 `i` 列中不会移动的方块数量，正好等于：

\[
\min(a_i,a_{i+1},\dots,a_n)
\]

也就是后缀最小值。

记：

\[
suf_i=\min(a_i,a_{i+1},\dots,a_n)
\]

那么不进行减少操作时：

\[
\text{moving}=\sum a_i-\sum suf_i
\]

---

## 减少一列会带来什么变化

如果把某一列减少 `1`：

- 总方块数减少 `1`；
- 如果它影响了一段长度为 `len` 的后缀最小值，那么 `sum(suf)` 也会减少 `len`；
- 所以移动方块数的净增加是 `len-1`。

因此我们要找的是：

> 后缀最小值数组里最长的一段相同值。

设最长段长度为 `best`，答案就是：

\[
\sum a_i-\sum suf_i+best-1
\]

---

## 为什么看相同后缀最小值段

如果若干个连续位置的 `suf` 相同，说明它们的后缀最低高度由同一个水平线控制。

把这个控制值减少 `1`，这一整段的 `suf` 都会一起减少。

影响的位置越多，答案增加越多。

---

## 思路步骤

1. 从右往左求 `suf[i]`。
2. 计算 `sum(a)` 和 `sum(suf)`。
3. 扫描 `suf`，找最长连续相同段长度 `best`。
4. 输出 `sum(a)-sum(suf)+best-1`。

---

## 复杂度

\[
O(n)
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
    while (T--) {
        int n;
        cin >> n;

        vector<ll> a(n), suf(n);
        ll total = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            total += a[i];
        }

        suf[n - 1] = a[n - 1];
        ll stable = suf[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suf[i] = min(a[i], suf[i + 1]);
            stable += suf[i];
        }

        int best = 1, cur = 1;
        for (int i = 1; i < n; ++i) {
            if (suf[i] == suf[i - 1]) {
                ++cur;
            } else {
                best = max(best, cur);
                cur = 1;
            }
        }
        best = max(best, cur);

        cout << total - stable + best - 1 << '\n';
    }
    return 0;
}
```

---

## 一句话总结

这题就是：**先用后缀最小值算不会动的方块，再找哪一段后缀最小值一起下降最赚。**
