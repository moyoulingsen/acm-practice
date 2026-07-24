# CF 1107 B - Digital root

**题目链接**：<https://codeforces.com/problemset/problem/1107/B>

**题型**：数学 / 数位根

**难度体感**：B 题，核心是数位根为 `x` 的第 `k` 个正整数公式。

---

## 题意压缩

给 `k` 和 `x`，找第 `k` 个数位根等于 `x` 的正整数。

数位根规律：一个数 `n` 的数位根等于：

- 如果 `n % 9 == 0`，数位根为 9；
- 否则为 `n % 9`。

---

## 关键观察

数位根等于 `x` 的数形成等差数列：

\[
x, x+9, x+18, x+27, \dots
\]

所以第 `k` 个就是：

\[
x + 9(k-1)
\]

---

## 思路步骤

1. 读入 `k,x`。
2. 输出 `x + 9 * (k - 1)`。

---

## 易错点

- `x` 范围是 `1..9`，所以不用单独处理 `x=0`；
- 注意用 `long long`。

---

## 复杂度

\[
O(1)
\]

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
        long long k, x;
        cin >> k >> x;
        cout << x + 9 * (k - 1) << '\n';
    }

    return 0;
}
```

---

## 一句话总结

数位根相同的数每隔 9 出现一次，第 `k` 个就是 `x + 9(k-1)`。
