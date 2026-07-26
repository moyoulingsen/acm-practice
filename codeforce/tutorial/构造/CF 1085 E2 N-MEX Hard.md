# CF 1085 E2 - N-MEX (Counting Version)

**真实题号**：CF 2207 E2

**题目链接**：<https://codeforces.com/problemset/problem/2207/E2>

**题型**：组合计数 / 构造 / mex

**难度体感**：2400，关键是沿用 E1 的结构，把选择数乘起来。

---

## 题意压缩

E2 和 E1 使用同样的 `N-MEX` 约束。

区别是：

- E1 只需要构造一个合法数组；
- E2 要统计合法数组 `b` 的数量。

并且 E2 中要求：

\[
0 \le b_i \le n
\]

答案对 `1e9+7` 取模。

---

## 先判断合法性

和 E1 一样，必须满足两个条件。

### 1. 范围限制

对 0-index 的 `i`：

\[
n-i-1 \le a_i \le n
\]

### 2. 单调不增

\[
a_i \le a_{i-1}
\]

如果任一条件不满足，答案就是 `0`。

---

## 计数公式

合法时，从左到右考虑每个位置。

### 情况 1：`a[i] == a[i-1]`

目标 `k-mex` 没有下降。

当前位置必须填一个新的、尚未出现过的、小于 `a[i]` 的数。

此时可选数量是：

\[
a_i-(n-i-1)
\]

所以贡献：

```text
a[i] - (n - i - 1)
```

### 情况 2：`i==0` 或 `a[i] < a[i-1]`

目标 `k-mex` 下降了。

这一位可以选择的安全方案数量为：

\[
i+1
\]

所以贡献：

```text
i + 1
```

把所有位置的贡献乘起来即可。

---

## 为什么可以直接相乘

E1 已经说明合法数组的结构被 `a` 的下降位置分段控制。

每个位置只需要考虑当前还能填的安全值数量。

这些选择不会再额外产生复杂依赖，因此逐位乘法即可。

---

## 思路步骤

1. 读入 `a`。
2. 检查范围和单调性，不合法输出 `0`。
3. 初始化 `ans=1`。
4. 从左到右：
   - 若 `i>0 && a[i]==a[i-1]`，乘 `a[i]-(n-i-1)`；
   - 否则乘 `i+1`。
5. 输出 `ans`。

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

const long long MOD = 1000000007LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (long long &x : a) cin >> x;

        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (a[i] < n - i - 1 || a[i] > n) ok = false;
            if (i > 0 && a[i] > a[i - 1]) ok = false;
        }

        if (!ok) {
            cout << 0 << '\n';
            continue;
        }

        long long ans = 1;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && a[i] == a[i - 1]) {
                ans = ans * (a[i] - (n - i - 1)) % MOD;
            } else {
                ans = ans * (i + 1) % MOD;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
```

---

## 一句话总结

这题就是：**先用 E1 的条件判断合法，再按“mex 不变/下降”两种位置分别乘可选数量。**
