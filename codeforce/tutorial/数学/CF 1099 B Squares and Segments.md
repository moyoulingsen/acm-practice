# CF 1099 B - Squares and Segments

**题目链接**：<https://codeforces.com/problemset/problem/1099/B>

**题型**：数学 / 枚举

**难度体感**：B 题，关键在把式子转成接近平方根的枚举。

---

## 题意压缩

要找两个正整数 `a,b`，满足：

\[
a \cdot b \ge n
\]

并让：

\[
a+b
\]

尽量小。

---

## 关键观察

在乘积固定附近时，两个数越接近，和越小。

所以最优解一定会在 `sqrt(n)` 附近。

因此我们只需要枚举：

- `a` 从 `1` 到 `sqrt(n)`
- 令 `b = ceil(n/a)`
- 更新最小值 `a+b`

---

## 为什么这样对

因为当 `a` 很小或很大时，`a+b` 都会偏大；
最平衡的时候最优，所以围绕平方根找就足够。

朴素从 `1..n` 枚举也行，但没必要。

---

## 思路步骤

1. 枚举 `a=1..sqrt(n)`
2. 计算 `b=(n+a-1)/a`
3. 更新答案 `min(ans,a+b)`
4. 输出答案

---

## 复杂度

\[
O(\sqrt n)
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

    long long ans = (long long)4e18;
    for (long long a = 1; a * a <= n; ++a) {
        long long b = (n + a - 1) / a;
        ans = min(ans, a + b);
    }

    cout << ans << '\n';
    return 0;
}
```

---

## 一句话总结

这题就是：**最优时两个数尽量接近，所以枚举到 `sqrt(n)` 即可。**
