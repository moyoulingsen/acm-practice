# CF 1102 B - Array K-Coloring

**题目链接**：<https://codeforces.com/problemset/problem/1102/B>

**题型**：贪心 / 计数 / 染色

**难度体感**：B 题，核心是同一个数字不能重复使用同一种颜色。

---

## 题意压缩

给长度为 `n` 的数组，要给每个位置染上 `1..k` 中的一种颜色。

要求：对于任意两个值相同的位置，它们的颜色必须不同。

问是否存在方案，存在则输出 `YES` 和每个位置的颜色。

---

## 关键观察

如果某个数出现次数超过 `k`，那么它需要超过 `k` 种不同颜色，必然不可能。

否则可以贪心：

- 对每个值的所有出现位置，依次分配颜色 `1,2,3...`；
- 不同值之间可以复用颜色。

---

## 思路步骤

1. 用 map/vector 收集每个数出现的位置。
2. 如果任意值出现次数大于 `k`，输出 `NO`。
3. 否则对每个值的位置列表，从 `1` 开始依次分配颜色。
4. 输出答案。

---

## 易错点

- 约束只针对“值相同”的位置，不同值之间颜色可以重复；
- 输出颜色要按原数组顺序；
- 如果 `k` 比某个值出现次数大，也不必强行用完所有颜色。

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    map<int, vector<int>> pos;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        pos[x].push_back(i);
    }

    vector<int> ans(n);
    for (auto &[x, ids] : pos) {
        if ((int)ids.size() > k) {
            cout << "NO\n";
            return 0;
        }
        for (int i = 0; i < (int)ids.size(); ++i) {
            ans[ids[i]] = i + 1;
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " \n"[i + 1 == n];
    }

    return 0;
}
```

---

## 一句话总结

每个值自己内部不能撞色，所以只要最大出现次数不超过 `k`，按出现顺序染色即可。
