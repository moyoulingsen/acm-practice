# CF 1103 F1 - Elections in Saransk (Easy Version)

**真实题号**：CF 2236 F1

**题目链接**：<https://codeforces.com/problemset/problem/2236/F1>

**题型**：数论 / 质因数分解 / 组合计数

**难度体感**：1700，关键是把 `lcm = product` 转成两两互质。

---

## 题意压缩

给定若干数 `a[i]`。

要求统计若干选择方案，使得选出来的数满足特定的 `lcm` 与乘积关系。

在 easy version 中，参数 `x=1`，条件可以化简为：

\[
lcm(p_1,p_2,\dots,p_n)=p_1p_2\cdots p_n
\]

---

## 关键观察

什么时候多个数的 `lcm` 等于它们的乘积？

答案是：这些数必须两两互质。

因为如果某个质因子同时出现在两个数里，那么乘积里会把它算两次，而 `lcm` 只会取最大指数，这样就不相等。

所以每个质因子最多只能被分配给一个 `p_i`。

---

## 按质因子独立计数

考虑某个质数 `q`。

假设它在所有 `a[i]` 的质因数分解中总共出现了 `cnt[q]` 次。

对于这个质因子，有这些选择：

- 不使用它；
- 使用其中某一次出现的位置。

所以一共有：

\[
cnt[q]+1
\]

种选择。

不同质因子之间互相独立，因此答案是：

\[
\prod_q (cnt[q]+1)
\]

对 `1e9+7` 取模。

---

## 思路步骤

1. 预处理最小质因子 `spf`。
2. 对每个 `a[i]` 分解质因数。
3. 每出现一次质因子 `p`，就令 `cnt[p]++`。
4. 最后把所有 `(cnt[p]+1)` 乘起来。

---

## 复杂度

设最大值为 `V`。

预处理：

\[
O(V\log\log V)
\]

每个数分解近似：

\[
O(\log V)
\]

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAXA = 500000;
const long long MOD = 1000000007LL;

int spf[MAXA + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 2; i <= MAXA; ++i) {
        if (spf[i] == 0) {
            for (long long j = i; j <= MAXA; j += i) {
                if (spf[j] == 0) spf[j] = i;
            }
        }
    }

    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;

        unordered_map<int, int> cnt;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            while (a > 1) {
                int p = spf[a];
                while (a % p == 0) {
                    ++cnt[p];
                    a /= p;
                }
            }
        }

        long long ans = 1;
        for (auto [p, c] : cnt) {
            ans = ans * (c + 1) % MOD;
        }

        cout << ans << '\n';
    }
    return 0;
}
```

---

## 一句话总结

这题就是：**`lcm = product` 等价于所有选出的数两两互质，所以每个质因子独立选择“不用或用一次”。**
