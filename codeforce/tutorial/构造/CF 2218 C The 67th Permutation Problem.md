# CF 2218 C - The 67th Permutation Problem

**题目链接**：<https://codeforces.com/problemset/problem/2218/C>

**对应题单**：CF 1090 Div.4 C

**题型**：构造 / 贪心

**难度**：800

---

## 题意压缩

需要构造一个 `1..3n` 的排列，把它按每三个一组后，使每组中位数之和尽量大。

---

## 关键观察

每组三个数的中位数想要大，就应该让两个大数放在同一组，再配一个小数。

因此可以这样构造每一组：

```text
小数, 次大数, 最大数
```

从大到小每次拿两个大数，从小到大每次拿一个小数。

---

## 思路步骤

1. 令 `k = 3n`。
2. 对 `i=1..n`：
   - 输出 `i`；
   - 输出 `k-1` 和 `k`；
   - `k -= 2`。

这样每组三个数互不重复，且覆盖 `1..3n`。

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

        int k = 3 * n;
        for (int i = 1; i <= n; ++i) {
            cout << i << ' ' << k - 1 << ' ' << k << " \n"[i == n];
            k -= 2;
        }
    }

    return 0;
}
```

---

## 一句话总结

每组用一个小数垫底、两个大数抬高中位数。
