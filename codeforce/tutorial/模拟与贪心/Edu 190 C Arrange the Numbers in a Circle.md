# Edu 190 C - Arrange the Numbers in a Circle

**题目链接**：<https://codeforces.com/problemset/problem/2230/C>

**题型**：贪心 / 构造计数

**难度**：1300

---

## 题意压缩

给出每种数字的出现次数，问最多能取多少个数字排成一个环，使任意连续三个数字中至少有两个相等。

---

## 关键观察

出现次数为 `1` 的数字最难处理，因为它不能靠自己形成相邻相等。

一个单独出现的数字需要被放进某个重复数字提供的“槽”中，形如：

```text
x single x
```

对于出现次数 `c > 1` 的数字，它大致能提供：

\[
\left\lfloor\frac c2\right\rfloor - 1
\]

个这样的槽。

如果只有一种非 singleton，环结构还能额外提供一个槽。

不能放进槽的 singleton 必须丢掉。

---

## 思路步骤

1. 统计总数量 `sum`。
2. 统计出现次数为 `1` 的种类数 `ones`。
3. 对每个 `c > 1`，累加 `c / 2 - 1` 到 `slots`。
4. 若 `ones == n - 1`，额外加一个槽。
5. 丢掉 `max(0, ones - slots)` 个 singleton。

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

        long long sum = 0;
        long long ones = 0;
        long long slots = 0;

        for (int i = 0; i < n; ++i) {
            long long x;
            cin >> x;
            sum += x;

            if (x == 1) ++ones;
            else slots += x / 2 - 1;
        }

        if (ones == n - 1) ++slots;

        long long wasted = max(0LL, ones - slots);
        long long ans = sum - wasted;

        if (ans < 3) ans = 0;
        cout << ans << '\n';
    }

    return 0;
}
```

---

## 一句话总结

关键是算重复数字能提供多少槽来安放只出现一次的数字。
