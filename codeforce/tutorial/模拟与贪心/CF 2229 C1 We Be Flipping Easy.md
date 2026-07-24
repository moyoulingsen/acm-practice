# CF 2229 C1 - We Be Flipping (Easy Version)

**题目链接**：<https://codeforces.com/problemset/problem/2229/C1>

**对应题单**：Codeforces Round 1100 C1

**题型**：贪心 / 前缀翻转

**难度**：900（绿）

---

## 题意压缩

可以选择一个前缀做翻转操作，目标是在 Easy 版本中让数组和尽量小，并输出操作方案。

---

## 关键观察

如果希望总和尽量小，本质上就是尽量把所有数变成负数。

从右往左看：

- 操作位置 `i` 只会影响 `1..i`；
- 所以当我们处理到 `i` 时，右边位置已经不会再被影响；
- 如果当前 `a[i]` 的符号是正的，就必须在 `i` 这里操作一次，把它变负。

只需要维护当前前缀被翻转了奇数次还是偶数次。

---

## 思路步骤

1. 从右往左扫描。
2. 用 `flip` 表示当前位置受到的翻转奇偶性。
3. 若当前位置当前符号为正，则记录操作 `i`，并翻转 `flip`。
4. 输出所有操作。

---

## 易错点

- 判断的是“当前符号”，不是原始符号。
- 从右往左扫，才能保证已经处理过的位置不再改变。

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
        vector<long long> a(n);
        for (auto &x : a) cin >> x;

        vector<int> ops;
        bool flip = false;
        for (int i = n - 1; i >= 0; --i) {
            bool positive = a[i] > 0;
            if (flip) positive = !positive;
            if (positive) {
                ops.push_back(i + 1);
                flip = !flip;
            }
        }

        cout << ops.size() << '\n';
        for (int x : ops) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
```

---

## 一句话总结

右往左贪心：如果当前位在已有翻转影响下仍是正数，就必须在这里翻一次。
