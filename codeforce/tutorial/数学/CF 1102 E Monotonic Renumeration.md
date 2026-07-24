# CF 1102 E - Monotonic Renumeration

**题目链接**：<https://codeforces.com/problemset/problem/1102/E>

**题型**：区间覆盖 / 组合计数

**难度体感**：E 题里较清晰的一类，核心是把相同数字的首末位置连成区间。

---

## 题意压缩

给一个数组，要把它重新编号成一个单调相关的形式。关键约束可以转化为：

如果某个值在数组中多次出现，那么它从第一次出现到最后一次出现之间的所有位置，必须属于同一个连续块。

问这样的分块方案数。

---

## 关键观察

对每个不同的值，记录它的：

- 第一次出现位置 `first[x]`；
- 最后一次出现位置 `last[x]`。

这个值要求区间 `[first[x], last[x]]` 必须被同一个块覆盖。

扫描数组时维护当前块必须覆盖到的最远右端点 `r`：

- 当前走到位置 `i`；
- 更新 `r = max(r, last[a[i]])`；
- 当 `i == r`，说明当前块闭合，可以切一刀。

如果一共得到 `blocks` 个块，那么相邻块之间有 `blocks-1` 个缝隙，每个缝隙可以选择是否合并，因此答案是：

\[
2^{blocks-1}
\]

---

## 思路步骤

1. 读入数组。
2. 记录每个值最后出现的位置。
3. 从左往右扫描，维护当前段最远右端点 `r`。
4. 如果 `i == r`，说明形成一个独立块，`blocks++`。
5. 输出 `2^(blocks-1) mod 998244353`。

---

## 易错点

- 只需要最后出现位置即可，第一次出现由扫描自然决定；
- 块数至少为 1，所以指数是 `blocks-1`；
- 取模是 `998244353`。

---

## 复杂度

\[
O(n \log n)
\]

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> last;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        last[a[i]] = i;
    }

    int blocks = 0;
    int r = -1;
    for (int i = 0; i < n; ++i) {
        r = max(r, last[a[i]]);
        if (i == r) blocks++;
    }

    long long ans = 1;
    for (int i = 0; i < blocks - 1; ++i) {
        ans = ans * 2 % MOD;
    }

    cout << ans << '\n';
    return 0;
}
```

---

## 一句话总结

把每个数字的首末出现看成必须覆盖的区间，扫描闭合出块，答案是块间缝隙的选择数。
