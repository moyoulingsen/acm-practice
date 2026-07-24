# CF 1099 C - Postcard

**题目链接**：<https://codeforces.com/problemset/problem/1099/C>

**题型**：字符串构造 / 贪心

**难度体感**：C 题，核心是理解 `?` 和 `*` 对前一个字符的影响。

---

## 题意压缩

给一个带特殊符号的字符串 `s` 和目标长度 `k`。

特殊符号含义：

- `?`：前一个普通字符可以删掉一次；
- `*`：前一个普通字符可以删掉，也可以重复任意多次。

要求构造一个长度正好为 `k` 的字符串。如果无法构造，输出 `Impossible`。

---

## 关键观察

先统计：

- `base`：普通字符数量；
- `q`：`?` 数量；
- `star`：`*` 数量。

如果没有 `*`：

- 最多只能删 `q` 个字符；
- 可构造长度范围是 `[base-q, base]`。

如果有 `*`：

- 最短长度是 `base-q-star`；
- 因为 `*` 可以无限复制，所以最长无限。

---

## 思路步骤

1. 统计普通字符数和特殊符号数。
2. 判断能否构造目标长度 `k`。
3. 如果 `base > k`：需要删除 `base-k` 个被特殊符号修饰的字符。
4. 如果 `base < k`：必须使用某个 `*` 复制前一个字符。
5. 从左到右生成答案。

---

## 易错点

- 特殊符号作用在**前一个普通字符**上；
- `?` 不能扩展长度，只能删；
- 只有 `*` 才能把长度变大。

---

## 复杂度

\[
O(|s| + k)
\]

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int k;
    cin >> s >> k;

    int base = 0, q = 0, star = 0;
    for (char c : s) {
        if (c == '?') q++;
        else if (c == '*') star++;
        else base++;
    }

    if (base > k && base - k > q + star) {
        cout << "Impossible\n";
        return 0;
    }
    if (base < k && star == 0) {
        cout << "Impossible\n";
        return 0;
    }

    string ans;
    int del = max(0, base - k);
    int add = max(0, k - base);
    bool expanded = false;

    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == '?' || s[i] == '*') continue;

        char nxt = (i + 1 < (int)s.size() ? s[i + 1] : '#');
        bool removable = (nxt == '?' || nxt == '*');
        bool repeatable = (nxt == '*');

        if (del > 0 && removable) {
            del--;
            continue;
        }

        ans += s[i];
        if (add > 0 && repeatable && !expanded) {
            ans += string(add, s[i]);
            expanded = true;
        }
    }

    cout << ans << '\n';
    return 0;
}
```

---

## 一句话总结

这题就是先算普通字符数，再决定：**长度多了用特殊符号删，长度少了必须靠 `*` 扩展。**
