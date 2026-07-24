# CF 1107 D - Compression

**题目链接**：<https://codeforces.com/problemset/problem/1107/D>

**题型**：矩阵 / 前缀和 / 枚举因子

**难度体感**：D 题，关键是把十六进制输入转成 0/1 矩阵，再检查最大块大小。

---

## 题意压缩

给一个 `n x n` 的 0/1 图像，但每行用十六进制字符串压缩表示。

要找到最大的整数 `k`，使得可以把图像划分成若干个 `k x k` 小块，并且每个小块内部全是同一种颜色。

---

## 关键观察

`k` 必须整除 `n`。

因此可以枚举 `n` 的所有因子，从大到小检查。

为了快速判断一个 `k x k` 块是否全 0 或全 1，可以做二维前缀和：

- 块内和为 `0`：全 0；
- 块内和为 `k*k`：全 1；
- 否则不合法。

---

## 思路步骤

1. 读入 `n`。
2. 每行读入十六进制字符串，把每个字符转成 4 个二进制位。
3. 建二维前缀和。
4. 枚举 `n` 的因子，从大到小检查。
5. 对每个因子 `k`，遍历所有 `k x k` 块。
6. 如果所有块都是全 0 或全 1，输出 `k`。

---

## 易错点

- 十六进制字符 `A-F` 要转成 10-15；
- 每个十六进制字符对应 4 位，注意高位到低位顺序；
- 只枚举 `n` 的因子。

---

## 复杂度

因子数量很少，整体约为：

\[
O(n^2 \cdot d(n))
\]

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int value(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    return c - 'A' + 10;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        int col = 1;
        for (char c : s) {
            int x = value(c);
            for (int b = 3; b >= 0; --b) {
                a[i][col++] = (x >> b) & 1;
            }
        }
    }

    vector<vector<int>> pref(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            pref[i][j] = a[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }

    auto sum = [&](int x1, int y1, int x2, int y2) {
        return pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1];
    };

    vector<int> divisors;
    for (int k = 1; k <= n; ++k) {
        if (n % k == 0) divisors.push_back(k);
    }
    sort(divisors.rbegin(), divisors.rend());

    for (int k : divisors) {
        bool ok = true;
        for (int i = 1; i <= n && ok; i += k) {
            for (int j = 1; j <= n; j += k) {
                int ones = sum(i, j, i + k - 1, j + k - 1);
                if (ones != 0 && ones != k * k) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            cout << k << '\n';
            return 0;
        }
    }

    return 0;
}
```

---

## 一句话总结

最大块大小必须是 `n` 的因子；用二维前缀和检查每个块是否纯色。
