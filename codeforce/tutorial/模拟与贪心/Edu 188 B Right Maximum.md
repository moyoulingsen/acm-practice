# Edu 188 B - Right Maximum

**题目链接**：<https://codeforces.com/problemset/problem/2204/B>

**题型**：贪心 / 前缀最大值

**难度**：800

---

## 题意压缩

给一个数组，按题目规则不断选择某段里的“最右最大值”，问最终会被选中的位置数量。

---

## 关键观察

一个位置会成为某次选择的最右最大值，当且仅当它不小于左边所有数。

也就是它满足：

\[
a_i \ge \max(a_1,a_2,\dots,a_{i-1})
\]

所以答案就是“带等号的前缀最大值”的个数。

---

## 思路步骤

1. 从左到右扫描数组。
2. 维护当前最大值 `mx`。
3. 如果 `a[i] >= mx`，答案加一。
4. 更新 `mx`。

---

## 复杂度

`O(n)`。

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
        int n;
        cin >> n;

        long long mx = LLONG_MIN;
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            long long x;
            cin >> x;

            if (x >= mx) ++ans;
            mx = max(mx, x);
        }

        cout << ans << '\n';
    }

    return 0;
}
```

---

## 一句话总结

被选中的位置正好是从左到右看见的新前缀最大值。
