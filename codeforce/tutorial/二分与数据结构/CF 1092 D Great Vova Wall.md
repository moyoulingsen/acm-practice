# CF 1092 D - Great Vova Wall

**题目链接**：<https://codeforces.com/problemset/problem/1092/D>

**题型**：栈 / 贪心

---

## 题意压缩

给出一排墙高，只能给相邻两列同时加高，问能否最终变成等高。

---

## 关键观察

相邻等高的未匹配段可以配对消掉；若低段尚未闭合就遇到更高高度，则不可能。

---

## 思路步骤

1. 用栈维护未匹配高度。
2. 等于栈顶就弹出，小于栈顶就压入，大于栈顶失败。
3. 最后栈为空或只剩全局最大值则成功。

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
    vector<int> a(n);
    int mx = 0;
    for (int &x : a) cin >> x, mx = max(mx, x);

    vector<int> st;
    bool ok = true;
    for (int x : a) {
        if (st.empty() || st.back() > x) st.push_back(x);
        else if (st.back() == x) st.pop_back();
        else ok = false;
        if (!ok) break;
    }

    if (!st.empty() && ((int)st.size() > 1 || st.back() != mx)) ok = false;
    cout << (ok ? "YES" : "NO") << '\n';
    return 0;
}
```

---

## 一句话总结

把可配对的相邻同高段用栈消掉。
