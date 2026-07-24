# CF 1096 F - It Just Keeps Going On and On

**题目链接**：<https://codeforces.com/problemset/problem/1096/F>

**题型**：概率 / 期望 / 逆序对 / 组合计数

**难度体感**：紫名常见的“线性期望 + 贡献拆分”题。

---

## 题意压缩

给定一个长度为 `n` 的排列雏形：

- 已知位置放的是 `1..n` 中的一些数；
- 未知位置用 `-1` 表示；
- 所有没有出现过的数会被**等概率随机**填进这些 `-1` 位置，形成一个完整排列。

要求：

- 求这个随机排列的**逆序对数量的期望值**；
- 对 `998244353` 取模。

---

## 为什么这题是线性期望模板题

很多期望题的核心都不是“整体算”，而是：

> **把答案拆成很多个小事件的和，再对每个事件单独求概率。**

这题里最自然的小事件就是：

- 对于每一对位置 `i < j`，判断最后是否会形成逆序对。

设指示变量：

\[
X_{i,j}=
\begin{cases}
1,& a_i>a_j\\
0,& \text{否则}
\end{cases}
\]

那么总逆序对数就是：

\[
X=\sum_{i<j} X_{i,j}
\]

于是根据线性期望：

\[
E[X]=\sum_{i<j} E[X_{i,j}]
\]

所以问题就变成：**每一对位置形成逆序对的概率是多少。**

---

## 把所有位置对分成 3 类

设缺失数字个数为 `k`。

### 1. 两个位置都已知

这时完全确定。

- 如果本来就是逆序对，贡献 `1`
- 否则贡献 `0`

所以这一部分就是：**已知数字之间的逆序对数**。

这部分可以用树状数组统计。

---

### 2. 一个已知，一个未知

这是这题最关键的一部分。

假设位置 `i` 是已知值 `a[i]`，位置 `j` 是未知。

那么 `j` 最后会从“所有缺失的数字”里等概率拿到一个数。

于是：

- 如果 `i < j`，想形成逆序对，需要 `a[i] > x`
- 如果 `i > j`，想形成逆序对，需要 `x > a[i]`

所以我们只要知道：

- 缺失数字里有多少个 **小于** `a[i]`
- 缺失数字里有多少个 **大于** `a[i]`

就能直接得到概率。

---

### 3. 两个位置都未知

设有 `k` 个未知位置。

对于任意一对未知位置 `(i,j)`，最后放进去的是两个不同的缺失数字，且相对大小等概率：

- 前面的大、后面的小：概率 `1/2`
- 前面的小、后面的大：概率 `1/2`

所以每一对未知位置对期望贡献都是：

\[
\frac{1}{2}
\]

而这样的对数有：

\[
\binom{k}{2}
\]

所以这一部分总贡献是：

\[
\binom{k}{2}\cdot \frac{1}{2} = \frac{k(k-1)}{4}
\]

---

## 如何快速统计“缺失数字中比某个值小/大”的个数

先扫一遍数组，把出现过的值标出来。

然后构造：

- `missPrefix[x]`：表示 `1..x` 中缺失了多少个数。

那么对于某个已知值 `v`：

- 缺失数字里 **小于 `v`** 的个数 = `missPrefix[v-1]`
- 缺失数字里 **大于 `v`** 的个数 = `k - missPrefix[v]`

这样就能 `O(1)` 算出某个已知值和未知位置之间的期望贡献。

---

## 如何统计“已知-未知”这部分

从左到右扫数组。

维护：

- `unknownLeft`：当前位置左边有多少个未知位置

对于当前已知值 `v`：

1. 左边未知、右边当前已知：
   - 想形成逆序对，需要左边未知值 `> v`
   - 贡献：
   \[
   unknownLeft \cdot \frac{\text{greaterMissing}(v)}{k}
   \]

2. 当前已知、右边未知：
   - 设总未知数是 `k`，那么右边未知个数是 `k-unknownLeft`
   - 想形成逆序对，需要右边未知值 `< v`
   - 贡献：
   \[
   (k-unknownLeft) \cdot \frac{\text{smallerMissing}(v)}{k}
   \]

把这两部分都加进去即可。

---

## 思路步骤

1. 读入数组，统计未知位置个数 `k`。
2. 标记哪些值已经出现，得到所有缺失数字。
3. 构造 `missPrefix`，支持查询缺失数字里 `<v` 和 `>v` 的个数。
4. 用树状数组统计已知值之间的逆序对数。
5. 再扫描一遍数组，统计“已知-未知”这部分的期望贡献。
6. 加上“未知-未知”这部分：
   \[
   \frac{k(k-1)}{4}
   \]
7. 输出答案。

---

## 易错点

### 1. 未知-未知不是 `C(k,2)`，而是 `C(k,2) / 2`

因为一对未知位置形成逆序对的概率只有 `1/2`。

### 2. “左边未知”和“右边未知”条件不一样

- 左边未知时，要数 **比当前值大的缺失数**
- 右边未知时，要数 **比当前值小的缺失数**

别写反。

### 3. `k = 0` 要特判

如果没有未知位置，就只剩下普通逆序对统计，不能去算 `inv(k)`。

### 4. 期望要在模意义下处理

除法都要改成乘逆元。

---

## 复杂度

- 构造缺失前缀：`O(n)`
- 树状数组统计已知逆序对：`O(n log n)`
- 扫描统计已知-未知贡献：`O(n)`

总复杂度：

\[
O(n\log n)
\]

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 998244353;

long long mod_pow(long long a, long long e) {
    long long r = 1;
    while (e > 0) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

struct BIT {
    int n;
    vector<long long> bit;
    BIT(int n = 0) : n(n), bit(n + 1, 0) {}

    void add(int idx, long long val) {
        for (; idx <= n; idx += idx & -idx) bit[idx] += val;
    }

    long long sum(int idx) const {
        long long res = 0;
        for (; idx > 0; idx -= idx & -idx) res += bit[idx];
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> used(n + 1, 0);

    int missingCnt = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == -1) {
            missingCnt++;
        } else {
            used[a[i]] = 1;
        }
    }

    vector<int> missPrefix(n + 1, 0);
    for (int v = 1; v <= n; ++v) {
        missPrefix[v] = missPrefix[v - 1] + (used[v] ? 0 : 1);
    }

    long long ans = 0;

    // 1) 已知-已知 逆序对
    BIT bit(n);
    long long seenKnown = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == -1) continue;
        ans = (ans + seenKnown - bit.sum(a[i])) % MOD;
        bit.add(a[i], 1);
        seenKnown++;
    }

    if (missingCnt == 0) {
        cout << (ans % MOD + MOD) % MOD << '\n';
        return 0;
    }

    long long invMissing = mod_pow(missingCnt, MOD - 2);
    long long unknownLeft = 0;

    // 2) 已知-未知
    for (int i = 1; i <= n; ++i) {
        if (a[i] == -1) {
            unknownLeft++;
            continue;
        }

        long long smallerMissing = missPrefix[a[i] - 1];
        long long greaterMissing = missingCnt - missPrefix[a[i]];
        long long unknownRight = missingCnt - unknownLeft;

        ans = (ans + unknownLeft % MOD * greaterMissing) % MOD * invMissing % MOD;
        ans = (ans + unknownRight % MOD * smallerMissing) % MOD * invMissing % MOD;
    }

    // 3) 未知-未知
    long long inv4 = mod_pow(4, MOD - 2);
    ans = (ans + 1LL * missingCnt * (missingCnt - 1) % MOD * inv4) % MOD;

    cout << (ans % MOD + MOD) % MOD << '\n';
    return 0;
}
```

---

## 一句话总结

这题的本质就是：**把逆序对按“已知-已知 / 已知-未知 / 未知-未知”拆开，再用线性期望分别统计。**
