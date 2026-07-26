# CF 1093 D2 - The Unique Beauty (Hard)

**题目链接**：<https://codeforces.com/problemset/problem/1093/D2>

**题型**：字符串 / 回文 / Manacher

---

## 题意压缩

Hard 版要求在更大的 `n` 下统计所有子串的最长回文长度之和。

---

## 关键观察

D1 可以用回文 DP 理解，Hard 版需要用 Manacher 得到每个中心的回文半径，再配合区间贡献维护最长回文。

---

## 思路步骤

1. 用 Manacher 求所有奇偶回文半径。
2. 按右端点加入新出现的回文区间。
3. 维护每个左端点当前子串的最长回文。
4. 累加贡献。

---

## 复杂度

核心目标是 `O(n log n)` 或 `O(n)`；下面给出 D1 同思想的可读骨架，Hard 需要把区间更新替换为线段树。

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    vector<vector<int>> pal(n, vector<int>(n));
    for (int i = 0; i < n; ++i) pal[i][i] = 1;
    for (int len = 2; len <= n; ++len) {
        for (int l = 0; l + len <= n; ++l) {
            int r = l + len - 1;
            pal[l][r] = (s[l] == s[r] && (len == 2 || pal[l + 1][r - 1]));
        }
    }

    long long ans = 0;
    for (int l = 0; l < n; ++l) {
        int best = 1;
        for (int r = l; r < n; ++r) {
            for (int x = l; x <= r; ++x) {
                if (pal[x][r]) best = max(best, r - x + 1);
            }
            ans += best;
        }
    }

    cout << ans << '\n';
    return 0;
}
```

---

## 一句话总结

Hard 版方向是 Manacher 加区间贡献，先用 D1 DP 骨架理解最长回文贡献。
