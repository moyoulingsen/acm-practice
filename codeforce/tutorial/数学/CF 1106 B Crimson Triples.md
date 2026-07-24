# CF 1106 B - Lunar New Year and Food Ordering

**题目链接**：<https://codeforces.com/problemset/problem/1106/B>

**题型**：贪心 / 数据结构

**难度体感**：B 题常见模型：局部先取指定，再从全局最便宜处补。

---

## 题意压缩

有若干种食物，每种有库存和单价。每次顾客先想买某一种，如果该种不够，就需要从全局剩余食物中按最便宜的继续补。

要求输出每次购买的最小花费。

---

## 关键观察

这题最重要的是把两类选择分开：

1. 先尽量满足顾客指定的那一类；
2. 如果还不够，就从所有剩余食物里按单价最小继续拿。

所以需要一个按价格排序的全局结构来维护“当前最便宜还能买的食物”。

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<long long> a(n + 1), c(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> c[i];

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 1);
    sort(ord.begin(), ord.end(), [&](int x, int y) { return c[x] < c[y]; });

    int ptr = 0;
    while (m--) {
        int t;
        long long d;
        cin >> t >> d;
        long long ans = 0;

        long long take = min(d, a[t]);
        a[t] -= take;
        d -= take;
        ans += take * c[t];

        while (d > 0 && ptr < n) {
            int id = ord[ptr];
            if (a[id] == 0) {
                ptr++;
                continue;
            }
            long long cur = min(d, a[id]);
            a[id] -= cur;
            d -= cur;
            ans += cur * c[id];
        }

        if (d > 0) cout << 0 << '\n';
        else cout << ans << '\n';
    }
    return 0;
}
```

---

## 一句话总结

这题核心是：**先吃指定种类，不够再从全局最便宜的库存里补。**
