# Edu 189 D - Exceptional Segments

**题目链接**：<https://codeforces.com/problemset/problem/2225/D>

**题型**：数学 / 前缀异或 / 计数

**难度**：1500

---

## 题意压缩

统计包含位置 `x` 的区间 `[l,r]` 数量，使得：

\[
l \oplus (l+1) \oplus \cdots \oplus r = 0
\]

答案对 `998244353` 取模。

---

## 关键观察

令：

\[
P(i)=1\oplus2\oplus\cdots\oplus i,\quad P(0)=0
\]

则 `[l,r]` 的异或和为 `0` 等价于：

\[
P(l-1)=P(r)
\]

因为区间要包含 `x`，所以令 `a=l-1`，需要统计：

\[
0 \le a < x,\quad x \le r \le n,\quad P(a)=P(r)
\]

前缀异或有周期规律：

- `P(i)=0`：`i=0` 或 `i ≡ 3 (mod 4)`；
- `P(i)=1`：`i ≡ 1 (mod 4)`；
- 其他值不会形成这种跨区间重复贡献。

所以分别统计左右两边 `P=0` 和 `P=1` 的数量并相乘。

---

## 思路步骤

1. 写函数统计 `0..m` 中 `P(i)=0` 的数量。
2. 写函数统计 `0..m` 中 `P(i)=1` 的数量。
3. 左边是 `0..x-1`，右边是 `x..n`。
4. 答案为 `left0*right0 + left1*right1`。

---

## 复杂度

`O(1)`。

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
const int64 MOD = 998244353;

int64 cnt0(int64 m) {
    if (m < 0) return 0;
    return 1 + (m + 1) / 4;
}

int64 cnt1(int64 m) {
    if (m < 0) return 0;
    return (m + 3) / 4;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int64 n, x;
        cin >> n >> x;

        int64 left0 = cnt0(x - 1);
        int64 right0 = cnt0(n) - cnt0(x - 1);

        int64 left1 = cnt1(x - 1);
        int64 right1 = cnt1(n) - cnt1(x - 1);

        int64 ans = 0;
        ans = (ans + left0 % MOD * (right0 % MOD)) % MOD;
        ans = (ans + left1 % MOD * (right1 % MOD)) % MOD;

        cout << ans << '\n';
    }

    return 0;
}
```

---

## 一句话总结

把区间异或为零转成左右两侧前缀异或值相等，再用 `P(i)` 的周期直接计数。
