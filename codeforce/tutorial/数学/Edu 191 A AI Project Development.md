# Edu 191 A - AI Project Development

**题目链接**：<https://codeforces.com/problemset/problem/2233/A>

**题型**：数学 / 分类讨论

**难度**：800

---

## 题意压缩

有一个项目共 `n` 工作量，两个人效率分别为 `x,y`。可以选择让 Nikita 先花 `z` 小时配置 AI，之后他的效率变成 `10y`，问最少完成时间。

---

## 关键观察

有两种主要方案：

1. 不配置 AI，两个人直接一起做，时间为：

\[
\left\lceil\frac n {x+y}\right\rceil
\]

2. 配置 AI。前 `z` 小时只有 Maxim 以速度 `x` 做，若还没完成，之后速度变成 `x+10y`。

如果 `x*z >= n`，说明配置期间 Maxim 已经能单独做完，此时直接比较即可。

---

## 思路步骤

1. 先计算不配置 AI 的答案。
2. 再计算配置 AI 的答案：
   - 若 `x*z < n`，需要 `z + ceil((n-xz)/(x+10y))`；
   - 否则只需要 `ceil(n/x)`。
3. 输出两者最小值。

---

## 复杂度

`O(1)`。

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll ceilDiv(ll a, ll b) {
    return (a + b - 1) / b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        ll n, x, y, z;
        cin >> n >> x >> y >> z;

        ll ans = ceilDiv(n, x + y);

        if (x * z < n) {
            ans = min(ans, z + ceilDiv(n - x * z, x + 10 * y));
        } else {
            ans = min(ans, ceilDiv(n, x));
        }

        cout << ans << '\n';
    }

    return 0;
}
```

---

## 一句话总结

比较“直接两人一起做”和“先配置 AI 再加速”两种时间即可。
