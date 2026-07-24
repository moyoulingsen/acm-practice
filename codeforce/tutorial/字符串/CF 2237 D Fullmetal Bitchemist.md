# CF 2237 D - Fullmetal Bitchemist

**题目链接**：<https://codeforces.com/problemset/problem/2237/D>

**对应题单**：Codeforces Round 1104 D

**题型**：字符串 / 前缀和 / 计数

**难度**：1500（青）

---

## 题意压缩

给定一个 01 串，统计满足题目化简规则的子串数量。

---

## 关键观察

把字符映射成模 3 权值：

- `0 -> 1`
- `1 -> 2`

操作过程中，子串权值和模 3 是关键不变量。

不能化简的坏子串分两类：

1. 权值和为 `0 mod 3` 的子串；
2. 长度至少为 3 的奇数长度交替串，例如 `010`、`10101`。

第二类交替串不会和第一类重叠，因为奇数长度交替串的权值和不为 `0 mod 3`。

所以答案就是：

\[
\text{总子串数} - \text{第一类坏串数} - \text{第二类坏串数}
\]

---

## 思路步骤

1. 用前缀模 3 统计权值和为 `0 mod 3` 的子串数量。
2. 扫描字符串，维护当前交替后缀长度 `len`。
3. 每个位置结尾的长度至少 3 的奇数交替子串数量为 `(len - 1) / 2`。
4. 总子串数减去两类坏串。

---

## 易错点

- `0` 和 `1` 的权值不是自身，而是 `1` 和 `2`。
- 交替坏串只统计奇数长度且长度至少为 3。
- 两类坏串不重叠，可以直接相减。

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
        int n = s.size();

        long long badMod = 0;
        long long cnt[3] = {1, 0, 0};
        int pref = 0;
        for (char c : s) {
            pref = (pref + (c == '0' ? 1 : 2)) % 3;
            badMod += cnt[pref];
            cnt[pref]++;
        }

        long long badAlt = 0;
        int len = 0;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && s[i] != s[i - 1]) len++;
            else len = 1;
            badAlt += (len - 1) / 2;
        }

        long long total = 1LL * n * (n + 1) / 2;
        cout << total - badMod - badAlt << '\n';
    }
    return 0;
}
```

---

## 一句话总结

坏串只有两种：模 3 和为 0，或者奇数长度交替串；总数减掉它们即可。
