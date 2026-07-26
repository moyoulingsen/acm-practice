# CF 1103 C - Omsk Programmers

**真实题号**：CF 2236 C

**题目链接**：<https://codeforces.com/problemset/problem/2236/C>

**题型**：贪心 / 数学 / 模拟

**难度体感**：1000，关键是先除后加。

---

## 题意压缩

给定 `a,b,x`。

一次操作可以：

- 把 `a` 或 `b` 加 `1`；
- 把 `a` 或 `b` 变成 `floor(a/x)` 或 `floor(b/x)`。

问让 `a` 和 `b` 相等的最少操作次数。

---

## 关键观察

加法只会让数变大，除法会让数快速变小。

如果某个数以后还要被除，那么在除之前给它加 `1` 通常没有意义，因为加的部分会被除法压缩掉。

所以最优策略可以看成：

> 先做若干次除法，再用加法补齐差值。

---

## 贪心过程

当前如果 `a != b`，让较大的那个数除以 `x`。

在每一步除法之前，都考虑一种方案：

- 现在停止除法；
- 直接用加法把小的补到大的；
- 代价是 `已用除法次数 + abs(a-b)`。

不断更新最小值即可。

因为 `x >= 2`，较大的数每次至少折半，所以循环次数很少。

---

## 思路步骤

1. 令 `cnt=0` 表示已经用了多少次除法。
2. 当 `a != b`：
   - 用 `cnt + abs(a-b)` 更新答案；
   - 把较大的数除以 `x`；
   - `cnt++`。
3. 相等时再用 `cnt` 更新答案。

---

## 复杂度

\[
O(\log \max(a,b))
\]

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        ll a, b, x;
        cin >> a >> b >> x;

        ll ans = LLONG_MAX;
        ll used = 0;

        while (a != b) {
            if (a < b) swap(a, b);

            ans = min(ans, used + a - b);
            a /= x;
            ++used;
        }

        ans = min(ans, used);
        cout << ans << '\n';
    }
    return 0;
}
```

---

## 一句话总结

这题就是：**枚举做了多少次除法，除法总是先作用在较大的数上，然后用加法补差。**
