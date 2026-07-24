# CF 2237 C - Duck Surplus

**题目链接**：<https://codeforces.com/problemset/problem/2237/C>

**对应题单**：Codeforces Round 1104 C

**题型**：模拟与贪心

**难度**：1000（绿）

---

## 题意压缩

给定一个序列，按照题目规则从左到右处理，求最后不可避免的剩余值。

---

## 关键观察

维护当前已经处理前缀的结果 `ans`。

读到新数 `x` 时：

- 如果 `ans <= x`，当前数足够大，可以直接成为新的前缀结果：`ans = x`；
- 如果 `ans > x`，说明小的部分会被并入当前前缀结果：`ans += x`。

也就是说，只有当前结果比新数大时，才会发生累加。

---

## 思路步骤

1. 初始化 `ans = 0`。
2. 从左到右扫描每个 `x`：
   - `ans <= x`：令 `ans = x`；
   - 否则令 `ans += x`。
3. 输出 `ans`。

---

## 易错点

- `ans == x` 时走 `ans = x`，不是累加。
- 累加过程可能变大，用 `long long`。

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
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            long long x;
            cin >> x;
            if (ans <= x) ans = x;
            else ans += x;
        }
        cout << ans << '\n';
    }
    return 0;
}
```

---

## 一句话总结

从左到右维护前缀结果：新数够大就替换，否则只能并入累加。
