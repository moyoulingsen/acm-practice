# CF 2241 D - An Alternative Way

**题目链接**：<https://codeforces.com/problemset/problem/2241/D>

**题型**：前缀和 / 构造可行性

**难度体感**：D 题，核心是把操作影响转成“前缀和只能增加”。

---

## 题意压缩

给两个数组 `a,b`。有一种操作可以对某个区间加上交替的 `+1,-1,+1,-1...`。

问能否通过若干次操作把 `a` 变成 `b`。

---

## 关键观察

看前缀和：

\[
p_i=\sum_{j=1}^{i}a_j,\quad q_i=\sum_{j=1}^{i}b_j
\]

一次操作对前缀和的影响是：某些前缀增加 `1`，其余不变。

也就是说：**每个前缀和只能增加，不能减少**。

因此必要条件是：

\[
p_i \le q_i \quad \forall i
\]

同时这个条件也是充分的：长度为 1 或 2 的操作可以独立增加需要的前缀和。

---

## 思路步骤

1. 读入 `a,b`。
2. 分别计算前缀和。
3. 如果存在 `prefixA[i] > prefixB[i]`，输出 `NO`。
4. 否则输出 `YES`。

---

## 易错点

- 不是逐位比较 `a[i] <= b[i]`；
- 要比较的是每一个前缀和；
- 用 `long long` 存前缀和。

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
        int n;
        cin >> n;
        vector<long long> a(n), b(n);
        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x;

        bool ok = true;
        long long pa = 0, pb = 0;
        for (int i = 0; i < n; ++i) {
            pa += a[i];
            pb += b[i];
            if (pa > pb) ok = false;
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}
```

---

## 一句话总结

把数组转成前缀和后，问题就变成判断 `a` 的每个前缀和是否都不超过 `b`。
