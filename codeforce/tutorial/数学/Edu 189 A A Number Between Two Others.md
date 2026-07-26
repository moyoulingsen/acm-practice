# Edu 189 A - A Number Between Two Others

**题目链接**：<https://codeforces.com/problemset/problem/2225/A>

**题型**：数学 / 构造

**难度**：800

---

## 题意压缩

给定 `x < y`，且 `y` 是 `x` 的倍数。问是否存在一个数 `z`，满足：

- `x < z < y`；
- `z` 是 `x` 的倍数；
- `y` 不是 `z` 的倍数。

---

## 关键观察

令：

\[
k = \frac y x
\]

所有在 `(x,y)` 之间且是 `x` 倍数的数，都形如 `tx`，其中 `2 <= t <= k-1`。

如果 `k = 2`，中间没有这样的倍数，必然不行。

如果 `k >= 3`，取：

\[
z = (k-1)x
\]

因为 `k` 不可能被 `k-1` 整除，所以 `y` 不会是 `z` 的倍数。

---

## 思路步骤

只需要判断 `y > 2x`。

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
        long long x, y;
        cin >> x >> y;
        cout << (y > 2 * x ? "YES" : "NO") << '\n';
    }

    return 0;
}
```

---

## 一句话总结

只有 `y/x >= 3` 时，才能在中间找到一个合适的 `x` 的倍数。
