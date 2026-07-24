# CF 2234 B - Palindrome, Twelve and Two Terms

**题目链接**：<https://codeforces.com/problemset/problem/2234/B>

**题型**：数学 / 构造 / 回文数

**难度体感**：B 题，核心是围绕 `mod 12` 构造一个很小的回文补数。

---

## 题意压缩

给一个正整数 `n`，要找两个非负整数 `a,b`，满足：

- `a + b = n`；
- `a` 是回文数；
- `b` 能被 `12` 整除。

找不到则输出 `-1`。

---

## 关键观察

因为 `b` 要被 `12` 整除，所以只需要让：

\[
a \equiv n \pmod{12}
\]

也就是说，先看 `r = n % 12`。

- 如果 `r != 10`，那么 `r` 本身就是一位数回文，可以令 `a=r`，`b=n-r`。
- 如果 `r == 10`，一位数里没有 `10` 这个回文。此时如果 `n > 10`，可以用 `a=22`，因为 `22` 是回文且 `22 % 12 = 10`。
- 特殊地，`n=10` 时没有可行解。

---

## 思路步骤

1. 计算 `r = n % 12`。
2. 如果 `n == 10`，输出 `-1`。
3. 否则如果 `r == 10`，输出 `22 n-22`。
4. 否则输出 `r n-r`。

---

## 易错点

- `a,b` 可以是非负整数，所以 `a=0` 合法；
- `0` 也是回文数；
- 只有 `n=10` 是特殊失败情况。

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
        long long n;
        cin >> n;

        if (n == 10) {
            cout << -1 << '\n';
        } else if (n % 12 == 10) {
            cout << 22 << ' ' << n - 22 << '\n';
        } else {
            long long a = n % 12;
            cout << a << ' ' << n - a << '\n';
        }
    }

    return 0;
}
```

---

## 一句话总结

让回文数 `a` 承担 `n mod 12` 的余数；余数是 `10` 时用 `22` 替代。
