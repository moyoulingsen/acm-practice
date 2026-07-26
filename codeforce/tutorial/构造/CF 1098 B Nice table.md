# CF 1098 B - Nice table

**题目链接**：<https://codeforces.com/problemset/problem/1098/B>

**题型**：构造 / 枚举

---

## 题意压缩

修改最少格子，使 `n*m` 表中任意 `2x2` 都包含 `A,C,G,T` 四种字符。

---

## 关键观察

合法表要么按行使用两两交替字符，要么按列使用两两交替字符；枚举四个字符的 24 种排列即可。

---

## 思路步骤

1. 枚举 `ACGT` 的排列。
2. 分别构造行模式和列模式。
3. 统计修改次数，保留最优表。

---

## 复杂度

`O(24nm)`。

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
    vector<string> a(n);
    for (string &s : a) cin >> s;

    string c = "ACGT";
    vector<string> ans = a;
    int best = n * m + 1;

    sort(c.begin(), c.end());
    do {
        for (int mode = 0; mode < 2; ++mode) {
            vector<string> cur(n, string(m, ' '));
            int cost = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    int id = mode == 0 ? (i % 2) * 2 + (j % 2) : (j % 2) * 2 + (i % 2);
                    cur[i][j] = c[id];
                    cost += cur[i][j] != a[i][j];
                }
            }
            if (cost < best) best = cost, ans = cur;
        }
    } while (next_permutation(c.begin(), c.end()));

    for (auto &s : ans) cout << s << '\n';
    return 0;
}
```

---

## 一句话总结

枚举行/列交替模式和字符排列。
