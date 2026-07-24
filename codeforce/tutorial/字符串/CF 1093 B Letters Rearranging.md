# CF 1093 B - Letters Rearranging

**题目链接**：<https://codeforces.com/problemset/problem/1093/B>

**题型**：字符串 / 构造

**难度体感**：B 题，结论很直接。

---

## 题意压缩

给你一个字符串，要求重新排列字符，使它**不是回文串**。

如果做不到，输出 `-1`。

---

## 关键观察

什么时候做不到？

只有一种情况：

- 字符串所有字符都相同

因为无论你怎么重排，结果都还是一样，自然还是回文。

只要字符串里存在至少两种不同字符，那么把它排序后：

- 最小字符会在前面
- 最大字符会在后面

整个串一定不会是回文。

所以做法就是：

- 若所有字符相同，输出 `-1`
- 否则输出排序后的字符串

---

## 思路步骤

1. 读入字符串 `s`
2. 检查是否所有字符都相同
3. 若是，输出 `-1`
4. 否则排序并输出

---

## 复杂度

排序占主导：

\[
O(n\log n)
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
        string s;
        cin >> s;
        bool same = true;
        for (char c : s) {
            if (c != s[0]) {
                same = false;
                break;
            }
        }
        if (same) {
            cout << -1 << '\n';
        } else {
            sort(s.begin(), s.end());
            cout << s << '\n';
        }
    }
    return 0;
}
```

---

## 一句话总结

这题核心是：**只要不是全相同字符串，排序后一定能得到一个非回文串。**
