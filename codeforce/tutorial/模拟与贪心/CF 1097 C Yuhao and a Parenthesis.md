# CF 1097 C - Yuhao and a Parenthesis

**题目链接**：<https://codeforces.com/problemset/problem/1097/C>

**题型**：括号序列 / 贪心配对 / 分类统计

**难度体感**：C 题偏典型，关键是把一个串压缩成“能和谁配”。

---

## 题意压缩

给 `n` 个括号串，问有多少对字符串拼接后可以成为合法括号序列。

合法括号序列要求：

- 从左到右任意前缀的左括号数不少于右括号数；
- 最终左右括号数量相等。

---

## 关键观察

一个串想和另一个串拼起来合法，它不能“两头都坏”。

对单个串扫描，记：

- `sum`：最终括号和，`(` 为 `+1`，`)` 为 `-1`；
- `mn`：扫描过程中的最小前缀和。

分类：

1. `mn >= 0`：这个串可以放在左边，贡献一个正缺口 `sum`；
2. 如果它不能放左边，但 `sum < 0`，还可能放右边，需要从右往左检查；
3. 其他串无法参与合法拼接。

---

## 为什么要反向检查

假设一个串总和为负，它应该放在右边，帮助抵消左边多出来的左括号。

但它作为右边时，不能从自身尾部看就已经“坏掉”。

所以对右边候选串，从右往左扫描：

- `)` 视作 `+1`；
- `(` 视作 `-1`；
- 过程中不能小于 0。

通过检查后，它就能作为某个左边串的补充。

---

## 思路步骤

1. 对每个字符串计算正向 `sum` 和最小前缀。
2. 如果正向合法，统计 `pos[sum]++`。
3. 否则如果 `sum < 0` 且反向合法，统计 `neg[-sum]++`。
4. 枚举所有差值 `x`，答案加上 `pos[x] * neg[x]`。

---

## 易错点

- 不能只看总和，必须看前缀是否合法；
- `sum=0` 的合法串能和另一个 `sum=0` 合法串配；
- 不合法的混合串要直接丢掉。

---

## 复杂度

设总字符串长度为 `L`：

\[
O(L)
\]

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

bool good_left(const string &s, int &sum) {
    sum = 0;
    int mn = 0;
    for (char c : s) {
        sum += (c == '(' ? 1 : -1);
        mn = min(mn, sum);
    }
    return mn >= 0;
}

bool good_right(const string &s) {
    int bal = 0;
    for (int i = (int)s.size() - 1; i >= 0; --i) {
        bal += (s[i] == ')' ? 1 : -1);
        if (bal < 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<int, long long> pos, neg;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        int sum = 0;
        if (good_left(s, sum)) {
            pos[sum]++;
        } else if (sum < 0 && good_right(s)) {
            neg[-sum]++;
        }
    }

    long long ans = 0;
    for (auto [need, cnt] : pos) {
        ans += cnt * neg[need];
    }

    cout << ans << '\n';
    return 0;
}
```

---

## 一句话总结

这题的本质是：**每个括号串只保留“能当左边/右边”和净差值，再按差值配对。**
