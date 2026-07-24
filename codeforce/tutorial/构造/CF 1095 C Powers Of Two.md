# CF 1095 C - Powers Of Two

**题目链接**：<https://codeforces.com/problemset/problem/1095/C>

**题型**：贪心 / 位运算 / 构造

**难度体感**：C 题常见模型：把一个数拆成恰好 `k` 个 `2` 的幂。

---

## 题意压缩

给定 `n` 和 `k`。

要求把 `n` 表示成恰好 `k` 个 `2` 的幂之和。

如果能做到，输出一种方案；否则输出 `NO`。

---

## 关键观察 1：最少项数是多少

一个数的二进制展开本身就是若干个 `2` 的幂之和。

因此最少项数就是：

\[
\text{popcount}(n)
\]

因为每个二进制 `1` 都必须至少对应一项。

---

## 关键观察 2：最多项数是多少

最多当然可以全拆成 `1`，也就是：

\[
n
\]

项。

所以只有当：

\[
\text{popcount}(n) \le k \le n
\]

时才有解。

---

## 如何构造

先把 `n` 的二进制中每个 `1` 对应的 `2` 的幂放进一个大根堆。

然后如果当前项数还不到 `k`：

- 取出一个最大的幂 `x`
- 如果 `x=1` 就不能再拆
- 否则拆成两个 `x/2`

这样项数就会增加 `1`。

不断拆，直到项数变成 `k` 为止。

---

## 为什么贪心拆最大的是对的

因为：

- 大的幂还有继续拆分空间；
- 小的幂尤其是 `1` 已经不能再拆；
- 想增加项数，就优先拆还能拆的最大项最自然。

---

## 思路步骤

1. 判断 `popcount(n) <= k <= n` 是否成立。
2. 若不成立输出 `NO`。
3. 否则把二进制幂丢进大根堆。
4. 不断拆最大的幂，直到堆大小变成 `k`。
5. 输出 `YES` 和堆里的所有数。

---

## 复杂度

设最终项数为 `k`。

堆操作总复杂度：

\[
O(k\log k)
\]

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int pc = __builtin_popcount((unsigned)n);
    if (k < pc || k > n) {
        cout << "NO\n";
        return 0;
    }

    priority_queue<int> pq;
    for (int b = 0; b < 31; ++b) {
        if (n & (1 << b)) pq.push(1 << b);
    }

    while ((int)pq.size() < k) {
        int x = pq.top();
        pq.pop();
        if (x == 1) {
            cout << "NO\n";
            return 0;
        }
        pq.push(x / 2);
        pq.push(x / 2);
    }

    cout << "YES\n";
    vector<int> ans;
    while (!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }
    for (int x : ans) cout << x << ' ';
    cout << '\n';
    return 0;
}
```

---

## 一句话总结

这题就是：**先看 `popcount(n)` 和 `n` 夹不夹得住 `k`，再不断把最大的幂拆成两半。**
