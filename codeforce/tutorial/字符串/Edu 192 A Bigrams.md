# Edu 192 A - Bigrams

**题目链接**：<https://codeforces.com/problemset/problem/2242/A>

**题型**：字符串 / 计数

**难度**：800

---

## 题意压缩

给出每种字符的出现次数，问能否构造一个字符串，使其中存在两个相同的 bigram。

---

## 关键观察

相同 bigram 可以通过两种方式出现：

1. 某个字符至少出现 `3` 次，例如 `aaa` 中有两个重叠的 `aa`；
2. 至少有两个字符各出现 `2` 次，例如 `abab` 中有两个 `ab`。

所以只需要检查：

- 是否存在 `cnt >= 3`；
- 或者是否有至少两个 `cnt == 2`。

---

## 思路步骤

1. 读入每种字符出现次数。
2. 统计是否有 `>=3` 的字符。
3. 统计出现次数恰为 `2` 的字符数量。
4. 满足任一条件输出 `YES`。

---

## 复杂度

`O(k)`。

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
        int k;
        cin >> k;

        int cntTwo = 0;
        bool hasThree = false;

        for (int i = 0; i < k; ++i) {
            long long c;
            cin >> c;
            if (c >= 3) hasThree = true;
            if (c == 2) ++cntTwo;
        }

        cout << (hasThree || cntTwo >= 2 ? "YES" : "NO") << '\n';
    }

    return 0;
}
```

---

## 一句话总结

重复 bigram 要么来自 `aaa`，要么来自两个成对字符组成的 `abab`。
