# CF 1102 D - Balanced Ternary String

**题目链接**：<https://codeforces.com/problemset/problem/1102/D>

**题型**：字符串 / 贪心构造

**难度体感**：D 题，关键是保证字典序最小，同时每个数字出现 `n/3` 次。

---

## 题意压缩

给一个长度为 `n` 的三进制字符串，只包含 `0,1,2`，且 `n` 是 3 的倍数。

要修改尽量少的字符，使得 `0,1,2` 各出现 `n/3` 次。

在修改次数最少的前提下，输出字典序最小的结果。

---

## 关键观察

目标每个数字都出现 `need = n/3` 次。

为了字典序最小：

- 想把字符变小，例如 `1/2 -> 0`，应该从左往右改；
- 被迫把字符变大，例如 `0 -> 1/2`，应该从右往左改，尽量不影响前面字典序。

---

## 贪心顺序

1. 从左到右，把多余的 `1/2` 改成缺少的 `0`。
2. 从左到右，把多余的 `2` 改成缺少的 `1`。
3. 从右到左，把多余的 `0` 改成缺少的 `2/1`。
4. 从右到左，把多余的 `1` 改成缺少的 `2`。

更简单的实现方式是：不断判断当前字符是否“多余”，以及目标字符是否“缺少”。

---

## 易错点

- 修改次数最少并不难，难在字典序最小；
- 变小操作尽量靠左；
- 变大操作尽量靠右。

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

    int n;
    string s;
    cin >> n >> s;

    int need = n / 3;
    vector<int> cnt(3, 0);
    for (char c : s) cnt[c - '0']++;

    for (int i = 0; i < n; ++i) {
        int cur = s[i] - '0';
        for (int d = 0; d < cur; ++d) {
            if (cnt[cur] > need && cnt[d] < need) {
                cnt[cur]--;
                cnt[d]++;
                s[i] = char('0' + d);
                break;
            }
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        int cur = s[i] - '0';
        for (int d = 2; d > cur; --d) {
            if (cnt[cur] > need && cnt[d] < need) {
                cnt[cur]--;
                cnt[d]++;
                s[i] = char('0' + d);
                break;
            }
        }
    }

    cout << s << '\n';
    return 0;
}
```

---

## 一句话总结

为了字典序最小：**变小从左改，变大从右改。**
