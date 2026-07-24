# CF 1102 A - Integer Sequence Dividing

**题目链接**：<https://codeforces.com/problemset/problem/1102/A>

**题型**：数学 / 规律

**难度体感**：A 题，打表找 `n mod 4` 规律即可。

---

## 题意压缩

把 `1..n` 这些数分成两组，让两组和的差尽量小，输出最小差值。

---

## 关键观察

总和：

\[
S = \frac{n(n+1)}{2}
\]

如果 `S` 是偶数，理论上可以分成相等两组，答案是 `0`；否则答案至少是 `1`。

进一步看 `n mod 4`：

- `n % 4 == 0` 或 `3`：总和为偶数，答案 `0`；
- `n % 4 == 1` 或 `2`：总和为奇数，答案 `1`。

---

## 思路步骤

1. 读入 `n`。
2. 判断 `n % 4`。
3. 如果是 `0/3` 输出 `0`，否则输出 `1`。

---

## 易错点

- 不需要真的构造两组；
- 可以用总和奇偶判断，也可以直接用 `n%4`。

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

    long long n;
    cin >> n;

    int r = n % 4;
    cout << (r == 0 || r == 3 ? 0 : 1) << '\n';
    return 0;
}
```

---

## 一句话总结

这题只看 `n mod 4`：`0/3` 可平分，`1/2` 差值为 1。
