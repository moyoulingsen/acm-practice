# Edu 187 A - Towers of Boxes

**题目链接**：<https://codeforces.com/problemset/problem/2203/A>

**题型**：数学 / 贪心

**难度**：800

---

## 题意压缩

有 `n` 个盒子，每个盒子重量为 `m`，承重能力为 `d`。把盒子叠成若干摞，要求每个盒子上方盒子的总重量不超过它的承重能力，求最少需要多少摞。

---

## 关键观察

一摞高度为 `h` 时，最下面的盒子承受 `(h-1)m` 的重量，所以必须满足：

\[
(h-1)m \le d
\]

因此单摞最大高度为：

\[
\left\lfloor\frac d m\right\rfloor+1
\]

然后把 `n` 个盒子按这个最大高度分组即可。

---

## 思路步骤

1. 计算单摞最大高度 `h = d / m + 1`。
2. 答案是 `ceil(n / h)`。

---

## 复杂度

`O(1)`。

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
        long long n, m, d;
        cin >> n >> m >> d;

        long long h = d / m + 1;
        cout << (n + h - 1) / h << '\n';
    }

    return 0;
}
```

---

## 一句话总结

先算一摞最多能放多少个盒子，再对 `n` 做上取整分组。
