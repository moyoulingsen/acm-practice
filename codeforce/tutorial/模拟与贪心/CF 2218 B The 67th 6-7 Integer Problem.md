# CF 2218 B - The 67th 6-7 Integer Problem

**题目链接**：<https://codeforces.com/problemset/problem/2218/B>

**对应题单**：CF 1090 Div.4 B

**题型**：贪心 / 简单计算

**难度**：800

---

## 题意压缩

给定 `7` 个数，需要选择其中 `6` 个取负，剩下 `1` 个保持正数，使最后总和最大。

---

## 关键观察

设所有数的总和为 `S`，最后保持正数的是 `x`。

最终结果为：

\[
x - (S-x)=2x-S
\]

要最大化这个值，只需要让 `x` 最大。

所以保留最大的数为正，其余六个取负即可。

---

## 思路步骤

1. 读入 7 个数。
2. 统计总和 `sum` 和最大值 `mx`。
3. 输出 `2 * mx - sum`。

---

## 复杂度

`O(1)`。

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
        int sum = 0;
        int mx = -1e9;

        for (int i = 0; i < 7; ++i) {
            int x;
            cin >> x;
            sum += x;
            mx = max(mx, x);
        }

        cout << 2 * mx - sum << '\n';
    }

    return 0;
}
```

---

## 一句话总结

最终只会有一个数为正，当然保留最大值最优。
