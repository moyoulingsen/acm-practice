# Edu 191 C - Cost of a Bracket Sequence

**题目链接**：<https://codeforces.com/problemset/problem/2233/C>

**题型**：括号序列 / 贪心 / 前缀统计

**难度**：1400

---

## 题意压缩

给定括号串，需要选择最多 `k` 个字符删除，使剩余串的最长合法括号子序列尽量短，并输出删除方案。

---

## 关键观察

最长合法括号子序列本质上由匹配的 `(` 和 `)` 组成。

任取一个切分点 `p`，下面这些字符可以拦住所有跨越匹配：

- `p` 左边的所有 `(`；
- `p` 右边的所有 `)`。

因此对每个切分点，都能得到一个候选删除集合。选择集合大小最小的切分点，然后在这个集合里优先删最多 `k` 个字符，就是最优方案。

---

## 思路步骤

1. 预处理前缀 `(` 数量和 `)` 数量。
2. 枚举切分点 `p`，计算：

\[
cover(p)=\#(左边的 '(')+\#(右边的 ')')
\]

3. 找到最小的 `cover(p)`。
4. 在对应集合中标记删除，最多删除 `k` 个。

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
        int n, k;
        string s;
        cin >> n >> k >> s;

        vector<int> prefOpen(n + 1), prefClose(n + 1);
        for (int i = 0; i < n; ++i) {
            prefOpen[i + 1] = prefOpen[i] + (s[i] == '(');
            prefClose[i + 1] = prefClose[i] + (s[i] == ')');
        }

        int totalClose = prefClose[n];

        auto coverSize = [&](int p) {
            return prefOpen[p] + (totalClose - prefClose[p]);
        };

        int pos = 0;
        for (int p = 1; p <= n; ++p) {
            if (coverSize(p) < coverSize(pos)) pos = p;
        }

        string ans(n, '0');
        int rem = k;

        for (int i = 0; i < pos && rem > 0; ++i) {
            if (s[i] == '(') {
                ans[i] = '1';
                --rem;
            }
        }

        for (int i = pos; i < n && rem > 0; ++i) {
            if (s[i] == ')') {
                ans[i] = '1';
                --rem;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
```

---

## 一句话总结

枚举切分点，用“左括号 + 右括号”形成阻断集合，再从最小集合中删字符。
