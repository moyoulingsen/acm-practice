# CF 1107 A - Digits Sequence Dividing

**题目链接**：<https://codeforces.com/problemset/problem/1107/A>

**题型**：字符串 / 贪心构造

**难度体感**：A 题，核心是把数字串分成两个严格递增的数。

---

## 题意压缩

给一个长度为 `n` 的数字串 `s`，要把它分成若干个非空连续段，使得这些段表示的整数严格递增。

这题只需要判断能不能分，并输出一种方案。

---

## 关键观察

如果 `n == 2` 且 `s[0] >= s[1]`，无法分成 `s[0] < s[1]`。

除此之外，都可以分成两段：

- 第一段：`s[0]`
- 第二段：`s[1..n-1]`

当 `n > 2` 时，第二段位数更长，一定大于第一段的一位数。

---

## 思路步骤

1. 如果 `n == 2` 且 `s[0] >= s[1]`，输出 `NO`。
2. 否则输出 `YES`。
3. 输出分成 `2` 段：第一段为第一个字符，第二段为剩余字符串。

---

## 易错点

- `n == 2` 时第二段也是一位数，需要比较大小；
- `n > 2` 时第二段位数更多，天然更大。

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

        if (n == 2 && s[0] >= s[1]) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << 2 << '\n';
            cout << s[0] << ' ' << s.substr(1) << '\n';
        }
    }

    return 0;
}
```

---

## 一句话总结

除了两位数且前一位不小于后一位的情况，其余都切成“首位 + 剩余”。
