# Edu 188 E - Sum of Digits (and Again)

**题目链接**：<https://codeforces.com/problemset/problem/2204/E>

**题型**：构造 / 数位 / 枚举

**难度**：1800

---

## 题意压缩

给一个数字串，需要判断或构造它是否能重排成某个数不断取数字和后拼接出来的形式。

---

## 关键观察

设原数为 `x`，`y = sumDigits(x)`。

如果 `x` 不是一位数，那么最终串形如：

```text
digits(x) + digits(y) + digits(sumDigits(y)) + ...
```

所以可以枚举 `y`。对每个 `y`，它后面的链是确定的，只要检查：

1. 给定数字 multiset 是否包含这条后缀链；
2. 剩余数字的数字和是否正好等于 `y`；
3. 剩余部分能作为至少两位的 `x`，且不能有前导零。

---

## 思路步骤

1. 统计原串每个数字出现次数和总数字和。
2. 枚举 `y`，范围到 `9n`。
3. 构造 `y -> sumDigits(y) -> ...` 的后缀。
4. 检查后缀是否能被原串提供。
5. 检查剩余数字和是否为 `y`。
6. 若可行，把剩余数字降序作为 `x`，再接后缀。

---

## 复杂度

`O(9n * C)`，其中 `C` 是数字和链长度，很小。

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int digitSum(int x) {
    int res = 0;
    while (x > 0) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

string buildSuffix(int y) {
    string res;
    while (true) {
        res += to_string(y);
        if (y <= 9) break;
        y = digitSum(y);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        int n = s.size();
        if (n == 1) {
            cout << s << '\n';
            continue;
        }

        vector<int> cnt(10);
        int totalSum = 0;
        for (char ch : s) {
            int d = ch - '0';
            ++cnt[d];
            totalSum += d;
        }

        string answer;
        bool found = false;

        for (int y = 1; y <= 9 * n && !found; ++y) {
            string suf = buildSuffix(y);
            vector<int> need(10);
            int sufSum = 0;

            for (char ch : suf) {
                int d = ch - '0';
                ++need[d];
                sufSum += d;
            }

            bool ok = true;
            for (int d = 0; d <= 9; ++d) {
                if (need[d] > cnt[d]) ok = false;
            }
            if (!ok) continue;

            int remLen = n - (int)suf.size();
            if (remLen < 2) continue;
            if (totalSum - sufSum != y) continue;

            string x;
            for (int d = 9; d >= 0; --d) {
                int c = cnt[d] - need[d];
                while (c--) x.push_back(char('0' + d));
            }

            if (!x.empty() && x[0] != '0') {
                answer = x + suf;
                found = true;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}
```

---

## 一句话总结

枚举第一次数字和 `y`，后缀链随之固定，剩下只要检查数字 multiset 和剩余数字和。
