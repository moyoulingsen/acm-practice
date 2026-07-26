# Edu 192 C - Unstable Elements

**题目链接**：<https://codeforces.com/problemset/problem/2242/C>

**题型**：分块 / 排序 / 计数

**难度**：1300

---

## 题意压缩

给一个已按值分块的数组，经过题目定义的同步删除或复制操作后，问能得到多少种长度为 `k` 的数组。

---

## 关键观察

操作只会改变每个连续块的长度，不会改变块的相对顺序。

经过若干次同步删除后，短块会先消失。枚举当前仍然存活的最短原块长 `L`：

- 原长度小于 `L` 的块已经消失；
- 其余块都被同步减少了 `L-1`；
- 之后还可以同步增加若干次。

设当前存活块数为 `alive`，当前总长度为 `curLen`。如果要达到 `k`，必须满足：

\[
k \ge curLen
\]

且：

\[
(k-curLen) \bmod alive = 0
\]

每个不同的 `L` 最多贡献一种答案。

---

## 思路步骤

1. 把原数组压成连续块长度数组。
2. 将块长排序。
3. 按相同块长分组枚举最短存活块长。
4. 维护已经消失的短块总长度。
5. 检查 `k` 是否能由当前状态同步增加得到。

---

## 复杂度

`O(n log n)`。

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

        vector<int> a(n);
        for (int &x : a) cin >> x;

        vector<int> len;
        for (int l = 0; l < n;) {
            int r = l;
            while (r < n && a[r] == a[l]) ++r;
            len.push_back(r - l);
            l = r;
        }

        sort(len.begin(), len.end());

        int m = len.size();
        long long removedShort = 0;
        int ans = 0;

        for (int i = 0; i < m;) {
            int L = len[i];
            long long alive = m - i;
            long long curLen = n - removedShort - 1LL * (L - 1) * alive;

            if (curLen <= k && (k - curLen) % alive == 0) {
                ++ans;
            }

            int j = i;
            while (j < m && len[j] == L) ++j;

            removedShort += 1LL * (j - i) * L;
            i = j;
        }

        cout << ans << '\n';
    }

    return 0;
}
```

---

## 一句话总结

按块长排序，枚举哪些短块已经消失，剩余块只能同步增加同样的长度。
