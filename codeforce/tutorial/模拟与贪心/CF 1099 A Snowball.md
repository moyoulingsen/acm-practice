# CF 1099 A - Snowball

**题目链接**：<https://codeforces.com/problemset/problem/1099/A>

**题型**：模拟

**难度体感**：A 题，按过程直接模拟即可。

---

## 题意压缩

有一个雪球从高度 `h` 往下滚，每下降一层，重量增加当前高度值；
在某些特定高度会撞到障碍，如果此时重量不少于障碍高度要求，就会减少一些重量。

要求最后落地时雪球重量是多少。

---

## 关键观察

题目过程完全是线性的：

- 从高到低一层层往下走；
- 每层先加重量；
- 如果这层有障碍，再扣重量；
- 重量不能变负数。

所以直接模拟就行。

---

## 思路步骤

1. 读入初始重量 `w` 和初始高度 `h`
2. 读入两组障碍 `(u1,d1)`、`(u2,d2)`
3. 从高度 `h` 枚举到 `0`
4. 每层先 `w += 当前高度`
5. 若该层有障碍，则 `w = max(0, w-u)`
6. 输出最后结果

---

## 复杂度

\[
O(h)
\]

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int w, h;
    cin >> w >> h;
    int u1, d1, u2, d2;
    cin >> u1 >> d1 >> u2 >> d2;

    for (int cur = h; cur >= 0; --cur) {
        w += cur;
        if (cur == d1) w = max(0, w - u1);
        if (cur == d2) w = max(0, w - u2);
    }

    cout << w << '\n';
    return 0;
}
```

---

## 一句话总结

这题就是：**按高度从上往下逐层模拟。**
