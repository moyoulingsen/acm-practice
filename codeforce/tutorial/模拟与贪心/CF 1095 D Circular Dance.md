# CF 1095 D - Circular Dance

**题目链接**：<https://codeforces.com/problemset/problem/1095/D>

**题型**：构造 / 模拟

---

## 题意压缩

每个人记得自己后面的两个人，但顺序不确定，要求还原环形顺序。

---

## 关键观察

若已知连续的 `prev, cur`，则 `prev` 记住的另一个人就是 `next`。固定 1 号和它的一个后继后，整圈唯一确定。

---

## 思路步骤

1. 固定第一个人为 1。
2. 尝试 1 记住的两个候选作为第二人。
3. 依次推出后续节点。
4. 验证并输出合法环。

---

## 复杂度

`O(n)`。

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<array<int, 2>> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i][0] >> a[i][1];

    auto build = [&](int second) {
        vector<int> ans(n);
        ans[0] = 1;
        ans[1] = second;
        for (int i = 2; i < n; ++i) {
            int p = ans[i - 2], c = ans[i - 1];
            if (a[p][0] == c) ans[i] = a[p][1];
            else if (a[p][1] == c) ans[i] = a[p][0];
            else return vector<int>();
        }
        vector<int> seen(n + 1);
        for (int x : ans) {
            if (x < 1 || x > n || seen[x]) return vector<int>();
            seen[x] = 1;
        }
        return ans;
    };

    vector<int> ans = build(a[1][0]);
    if (ans.empty()) ans = build(a[1][1]);
    for (int x : ans) cout << x << ' ';
    cout << '\n';
    return 0;
}
```

---

## 一句话总结

连续两人确定后，下一个人就是前前一人的另一个记忆。
