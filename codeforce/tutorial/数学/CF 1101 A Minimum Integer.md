# CF 1101 A - Minimum Integer

**题目链接**：<https://codeforces.com/problemset/problem/1101/A>

**题型**：数学 / 分类讨论

**难度体感**：A 题，按区间位置直接判断。

---

## 题意压缩

给 `l, r, d`，找一个最小的正整数 `x`，满足：

- `x` 是 `d` 的倍数；
- `x` 不在区间 `[l,r]` 内。

---

## 关键观察

最小的 `d` 的倍数就是 `d`。

如果 `d < l`，那么 `d` 本身就在区间左边，可以直接输出。

否则答案一定是第一个大于 `r` 的 `d` 的倍数。

---

## 思路步骤

1. 如果 `d < l`，输出 `d`。
2. 否则输出：

\[
\left(\left\lfloor\frac{r}{d}\right\rfloor+1\right) \cdot d
\]

---

## 易错点

- 只要 `d < l` 就可以输出 `d`；
- 当 `d > r` 时，公式也会输出 `d`，仍然正确。

---

## 复杂度

\[
O(1)
\]

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
        long long l, r, d;
        cin >> l >> r >> d;
        if (d < l) cout << d << '\n';
        else cout << (r / d + 1) * d << '\n';
    }

    return 0;
}
```

---

## 一句话总结

最小倍数先试 `d`，如果落进区间，就跳到 `r` 右边的第一个倍数。
