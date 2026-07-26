# Edu 190 B - Digit String

**题目链接**：<https://codeforces.com/problemset/problem/2230/B>

**题型**：字符串 / 贪心 / 子序列

**难度**：1000

---

## 题意压缩

给一个只包含 `1..4` 的数字串，删除最少字符，使得剩下的串不存在能被 `4` 整除的子序列。

---

## 关键观察

能否被 `4` 整除只看最后一位或最后两位：

- 单个数字 `4` 本身能被 `4` 整除，所以所有 `4` 都不能保留；
- 两位数中，和 `1..4` 有关且能被 `4` 整除的主要威胁是 `12, 24, 32, 44`。

删掉所有 `4` 后，只需要避免子序列 `12` 和 `32`。

这等价于保留一个形态：

- 分割点左侧保留所有 `2`；
- 分割点右侧保留所有 `1/3`。

枚举分割点，最大化保留数量。

---

## 思路步骤

1. 统计右侧还剩多少个 `1/3`。
2. 从左到右扫描，维护左侧 `2` 的数量。
3. 每个分割点用 `left2 + right13` 更新最大保留数。
4. 答案为原长度减最大保留数。

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

        int right13 = 0;
        for (char c : s) {
            if (c == '1' || c == '3') ++right13;
        }

        int left2 = 0;
        int best = right13;

        for (char c : s) {
            if (c == '2') ++left2;
            if (c == '1' || c == '3') --right13;
            best = max(best, left2 + right13);
        }

        cout << (int)s.size() - best << '\n';
    }

    return 0;
}
```

---

## 一句话总结

删掉所有 `4` 后，剩余串只要不存在 `1/3` 在 `2` 前面即可。
