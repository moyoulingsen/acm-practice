# CF 2241 C - RemovevomeR

**题目链接**：<https://codeforces.com/problemset/problem/2241/C>

**题型**：字符串 / 回文删除 / 分块观察

**难度体感**：C 题，关键是把字符串按连续相同字符分块。

---

## 题意压缩

给一个字符串。每次可以选择一个长度至少为 2 的回文子串，并删除其中一个字符。

问最终能把字符串最短变成多长。

---

## 关键观察

只需要看相邻字符变化次数 `c`：

- 如果 `c = 0`：整串字符都相同，可以一直删到长度 1；
- 如果 `c = 1`：字符串只有两段连续块，操作永远不能完全消掉其中一段，答案为 2；
- 如果 `c >= 2`：可以先把每个连续块缩成长度 1，再利用交替串中的长度 3 回文继续缩，最终也能到 1。

所以答案只有两种：

\[
\text{answer} = \begin{cases}
2, & c=1\\
1, & c \ne 1
\end{cases}
\]

---

## 思路步骤

1. 统计相邻位置 `s[i] != s[i+1]` 的次数 `c`。
2. 如果 `c == 1`，输出 `2`。
3. 否则输出 `1`。

---

## 易错点

- 答案不是块数，而只和变化次数是否等于 1 有关；
- 全相同字符串可以删到 1；
- 三段及以上也可以通过交替回文继续删到 1。

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
        string s;
        cin >> n >> s;

        int changes = 0;
        for (int i = 0; i + 1 < n; ++i) {
            if (s[i] != s[i + 1]) changes++;
        }

        cout << (changes == 1 ? 2 : 1) << '\n';
    }

    return 0;
}
```

---

## 一句话总结

只有刚好两段连续块时最短为 2，其余情况都能删到 1。
