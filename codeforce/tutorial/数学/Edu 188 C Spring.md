# Edu 188 C - Spring

**题目链接**：<https://codeforces.com/problemset/problem/2204/C>

**题型**：数学 / 容斥 / lcm

**难度**：1000

---

## 题意压缩

三个人分别每隔 `a,b,c` 天来一次，总共有 `m` 天。某天如果一个人独自来、两人同来、三人同来，贡献不同。求三个人各自的总贡献。

---

## 关键观察

对某个人周期为 `x`，另外两人为 `y,z`。

他来的总次数是：

\[
\left\lfloor\frac m x\right\rfloor
\]

和 `y` 同来的次数是 `m / lcm(x,y)`，和 `z` 同来的次数是 `m / lcm(x,z)`，三人同来的次数是 `m / lcm(x,y,z)`。

用容斥可以得到：

- 独自来的次数；
- 恰好和一个人同来的次数；
- 三人同来的次数。

再分别乘以题目给的贡献即可。

---

## 思路步骤

1. 写函数 `solveOne(x,y,z,m)` 计算周期为 `x` 的人的贡献。
2. 用 lcm 和容斥计算三类天数。
3. 对三个人分别调用一次。

---

## 易错点

- lcm 可能溢出，要做上界截断；
- 恰好两人同来时，三人同来的天数会被算两次，需要减掉 `2 * allThree`。

---

## 复杂度

`O(log max(a,b,c))`。

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using i128 = __int128_t;

int64 lcmCap(int64 a, int64 b, int64 cap) {
    int64 g = gcd(a, b);
    i128 v = (i128)(a / g) * b;
    if (v > cap) return cap + 1;
    return (int64)v;
}

int64 solveOne(int64 x, int64 y, int64 z, int64 m) {
    int64 xy = lcmCap(x, y, m);
    int64 xz = lcmCap(x, z, m);
    int64 xyz = lcmCap(xy, z, m);

    int64 total = m / x;
    int64 bothXY = m / xy;
    int64 bothXZ = m / xz;
    int64 allThree = m / xyz;

    int64 alone = total - bothXY - bothXZ + allThree;
    int64 withOne = bothXY + bothXZ - 2 * allThree;

    return alone * 6 + withOne * 3 + allThree * 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int64 a, b, c, m;
        cin >> a >> b >> c >> m;

        cout << solveOne(a, b, c, m) << ' '
             << solveOne(b, a, c, m) << ' '
             << solveOne(c, a, b, m) << '\n';
    }

    return 0;
}
```

---

## 一句话总结

每个人的贡献只需要按“独自来、两人来、三人来”用 lcm 容斥拆开。
