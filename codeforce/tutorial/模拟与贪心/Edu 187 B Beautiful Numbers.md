# Edu 187 B - Beautiful Numbers

**题目链接**：<https://codeforces.com/problemset/problem/2203/B>

**题型**：贪心 / 数位

**难度**：1000

---

## 题意压缩

给一个十进制数，每次可以修改一位数字，问最少修改多少位，能让它变成题目定义下的 beautiful number。

---

## 关键观察

beautiful 的条件可以转成：数字和 `sum` 不超过 `9`。

如果当前数字和已经 `<= 9`，不需要修改。否则每次修改一位时，为了尽快降低数字和：

- 非首位数字 `d` 最多可以降低 `d`；
- 首位数字不能变成 `0`，最多降低 `d-1`。

所以把每一位能减少的贡献放进数组，优先使用最大贡献即可。

---

## 思路步骤

1. 统计所有数字和 `sum`。
2. 对每一位计算最多能减少多少。
3. 降序排序这些减少量。
4. 从大到小扣，直到 `sum <= 9`。

---

## 易错点

- 首位不能降到 `0`；
- 答案是修改位数，不是减少的总和；
- 数字很长时直接按字符串处理。

---

## 复杂度

`O(n log n)`。

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

        int sum = 0;
        vector<int> dec;

        for (int i = 0; i < (int)s.size(); ++i) {
            int d = s[i] - '0';
            sum += d;
            dec.push_back(i == 0 ? d - 1 : d);
        }

        sort(dec.rbegin(), dec.rend());

        int ans = 0;
        for (int x : dec) {
            if (sum <= 9) break;
            sum -= x;
            ++ans;
        }

        cout << ans << '\n';
    }

    return 0;
}
```

---

## 一句话总结

每次修改都尽量让数字和下降最多，直到数字和不超过 `9`。
