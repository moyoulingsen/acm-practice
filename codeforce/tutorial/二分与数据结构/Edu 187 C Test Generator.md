# Edu 187 C - Test Generator

**题目链接**：<https://codeforces.com/problemset/problem/2203/C>

**题型**：二分答案 / 位运算 / 贪心

**难度**：1500

---

## 题意压缩

给定 `s` 和 `m`，问最短需要多少个数，使这些数的和为 `s`，并且每个数都只能使用 `m` 中为 `1` 的二进制位。

---

## 关键观察

固定答案长度为 `n` 时，`m` 的每个二进制 `1` 位最多能被 `n` 个数各使用一次。

因此可以从高位到低位检查 `s` 的需求能否被这些容量满足：

- 从高位往低位走时，未满足的高位需求到下一位会翻倍；
- 如果 `s` 当前位是 `1`，需求加一；
- 如果 `m` 当前位是 `1`，当前位最多能消掉 `n` 份需求。

最后需求为 `0`，说明长度 `n` 可行。

可行性关于 `n` 单调，所以二分最小可行值。

---

## 思路步骤

1. 写 `can(n)` 判断长度 `n` 是否能构造。
2. 若 `s=0`，答案为 `0`。
3. 若 `can(s)` 都不成立，输出 `-1`。
4. 否则在 `[1,s]` 上二分最小答案。

---

## 复杂度

每次判断 `O(log s)`，总复杂度 `O(log^2 s)`。

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using i128 = __int128_t;

bool can(int64 s, int64 m, int64 n) {
    i128 need = 0;

    for (int bit = 62; bit >= 0; --bit) {
        need *= 2;

        if ((s >> bit) & 1LL) {
            ++need;
        }

        if ((m >> bit) & 1LL) {
            i128 use = min<i128>(need, n);
            need -= use;
        }
    }

    return need == 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int64 s, m;
        cin >> s >> m;

        if (s == 0) {
            cout << 0 << '\n';
            continue;
        }

        if (!can(s, m, s)) {
            cout << -1 << '\n';
            continue;
        }

        int64 l = 1, r = s, ans = s;
        while (l <= r) {
            int64 mid = l + (r - l) / 2;
            if (can(s, m, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
```

---

## 一句话总结

把每个二进制位看成容量，固定长度后从高位到低位贪心消需求，再二分长度。
