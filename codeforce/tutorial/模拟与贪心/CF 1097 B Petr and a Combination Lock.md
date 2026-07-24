# CF 1097 B - Petr and a Combination Lock

**题目链接**：<https://codeforces.com/problemset/problem/1097/B>

**题型**：暴力枚举 / 位运算 / 子集枚举

**难度体感**：B 题，关键是看到 `n <= 15` 后直接枚举所有转向。

---

## 题意压缩

有 `n` 次旋转，每次角度为 `a[i]`。

每个角度可以选择：

- 顺时针加上 `a[i]`；
- 逆时针减去 `a[i]`。

问能不能让最终角度是 `360` 的倍数。

---

## 关键观察

每个角度只有两种选择，所以总方案数是：

\[
2^n
\]

而 `n <= 15`，最多 `32768` 种，可以直接枚举。

---

## 思路步骤

1. 用二进制状态 `mask` 表示每个角度选加还是减。
2. 枚举 `mask = 0..(1<<n)-1`。
3. 对每个角度，如果对应 bit 是 1 就加，否则就减。
4. 如果最终和 `sum % 360 == 0`，输出 `YES`。
5. 所有状态都不行，输出 `NO`。

---

## 易错点

- C++ 负数取模可能是负数，但判断 `sum % 360 == 0` 没问题；
- 不需要贪心，枚举即可。

---

## 复杂度

\[
O(n \cdot 2^n)
\]

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    for (int mask = 0; mask < (1 << n); ++mask) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (mask >> i & 1) sum += a[i];
            else sum -= a[i];
        }
        if (sum % 360 == 0) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}
```

---

## 一句话总结

看到 `n <= 15`，就把每个角度的正负选择当作二进制状态暴力枚举。
