# Edu 189 B - Alternating String

**题目链接**：<https://codeforces.com/problemset/problem/2225/B>

**题型**：字符串 / 贪心

**难度**：900

---

## 题意压缩

给一个字符串，问能否通过题目允许的一次调整，让它变成交替字符串。

---

## 关键观察

交替字符串要求任意相邻字符都不同。

先统计相邻相同的位置数量 `bad`。一次操作能影响的冲突数量有限，官方结论可以化成：

\[
bad \le 2
\]

时可行，否则不可行。

---

## 思路步骤

1. 扫描字符串。
2. 统计 `s[i] == s[i-1]` 的次数。
3. 若次数不超过 `2`，输出 `YES`，否则输出 `NO`。

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

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        int bad = 0;
        for (int i = 1; i < (int)s.size(); ++i) {
            if (s[i] == s[i - 1]) ++bad;
        }

        cout << (bad <= 2 ? "YES" : "NO") << '\n';
    }

    return 0;
}
```

---

## 一句话总结

问题最后只看相邻相同的冲突数是否不超过 `2`。
