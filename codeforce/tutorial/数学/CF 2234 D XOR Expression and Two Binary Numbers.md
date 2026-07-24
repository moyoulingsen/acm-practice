# CF 2234 D - XOR, Expression and Two Binary Numbers

**题目链接**：<https://codeforces.com/problemset/problem/2234/D>

**题型**：位运算 / 数学规律 / 计数

**难度体感**：D 题，关键是发现递归异或过程里只会出现 `A`、`B`、`A xor B` 三类数。

---

## 题意压缩

给两个 `n` 位二进制数 `A` 和 `B`，它们分别是序列首尾。中间位置按规则不断用左右端点异或填充，共进行 `k` 层。

对最终序列中每个二进制数，设：

- `x_i` 为 1 的个数；
- `y_i` 为 0 的个数。

要求计算：

\[
\sum x_i y_i
\]

---

## 关键观察

令：

\[
C = A \oplus B
\]

递归填充过程中，出现的数只会是 `A/B/C` 三种之一。

所以问题变成：

1. 统计 `A/B` 在每一位上的组合类型；
2. 根据 `k` 的奇偶，算 `A/B/C` 在最终序列里各出现多少次；
3. 对每种位置组合贡献做计数。

更直接的公式实现：统计四类位对 `(A_i,B_i)`：

- `00`
- `01`
- `10`
- `11`

然后按照官方推导的三组集合大小 `p,q,r` 计算答案。

---

## 思路步骤

1. 统计每个位上 `(A_i,B_i)` 属于哪一类。
2. 如果 `k` 为奇数，使用一组 `p,q,r`；如果 `k` 为偶数，使用另一组。
3. 对每组贡献使用 `cnt * (n-cnt)`。
4. 乘上序列中重复出现的次数系数。

---

## 易错点

- `k` 最大到 30，`1LL << k` 要用 `long long`；
- 答案可能很大，要用 `long long`；
- 这题不是直接模拟 `2^k+1` 个数。

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

    int T;
    cin >> T;
    while (T--) {
        long long n, k;
        cin >> n >> k;

        string a, b;
        cin >> a >> b;

        vector<long long> c(4, 0);
        for (int i = 0; i < n; ++i) {
            int type = 2 * (a[i] - '0') + (b[i] - '0');
            c[type]++;
        }

        long long p, q, r;
        long long base = ((1LL << k) + 1) / 3;
        long long ans;

        if (k % 2 == 1) {
            p = c[0] + c[1];
            q = c[0] + c[3];
            r = c[0] + c[2];
            ans = base * (p * (n - p) + q * (n - q) + r * (n - r));
        } else {
            p = c[0] + c[1];
            q = c[0] + c[2];
            r = c[0] + c[3];
            ans = base * (p * (n - p) + q * (n - q) + r * (n - r));
            ans += p * (n - p) + q * (n - q);
        }

        cout << ans << '\n';
    }

    return 0;
}
```

---

## 一句话总结

别模拟整条序列；递归异或最终只在 `A/B/A xor B` 三类数之间循环，按位分类计贡献即可。
