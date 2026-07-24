# CF 1102 C - Doors Breaking and Repairing

**题目链接**：<https://codeforces.com/problemset/problem/1102/C>

**题型**：博弈 / 贪心 / 计数

**难度体感**：C 题，关键是发现只需要关心 `a[i] <= x` 的门。

---

## 题意压缩

有 `n` 扇门，每扇门有耐久 `a[i]`。

两个人轮流操作：

- 第一个人每次能破坏一扇耐久不超过 `x` 的门；
- 第二个人每次能修复一扇门，使其耐久增加 `y`。

问第一个人最多能破坏多少扇门。

---

## 关键观察

如果 `x > y`，第一个人破坏能力强于修复，最终所有门都能被破坏，答案是 `n`。

如果 `x <= y`，只有初始耐久 `<= x` 的门有机会被破坏。

原因：

- 耐久大于 `x` 的门，第一人一开始就打不了；
- 第二人只会修，不会让门变弱；
- 所以这些门永远不会成为可破坏目标。

对于 `cnt` 扇初始可破坏的门，两人轮流：第一人每回合破坏一扇，第二人能保住一扇，所以最多破坏：

\[
\left\lceil \frac{cnt}{2} \right\rceil
\]

---

## 思路步骤

1. 读入 `n,x,y` 和数组。
2. 如果 `x > y`，输出 `n`。
3. 否则统计 `cnt = a[i] <= x` 的数量。
4. 输出 `(cnt + 1) / 2`。

---

## 易错点

- 条件是 `x > y` 时答案才是 `n`；
- `x <= y` 时只数初始 `<=x` 的门。

---

## 复杂度

\[
O(n)
\]

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, y;
    cin >> n >> x >> y;

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a <= x) cnt++;
    }

    if (x > y) cout << n << '\n';
    else cout << (cnt + 1) / 2 << '\n';

    return 0;
}
```

---

## 一句话总结

`x > y` 全能破；否则只能在初始可破坏的门里抢一半向上取整。
