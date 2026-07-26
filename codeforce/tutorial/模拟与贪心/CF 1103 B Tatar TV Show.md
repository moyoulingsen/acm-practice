# CF 1103 B - Tatar TV Show

**真实题号**：CF 2236 B

**题目链接**：<https://codeforces.com/problemset/problem/2236/B>

**题型**：贪心 / 奇偶性 / 模类分组

**难度体感**：800，关键是发现每个模 `k` 的链互不影响。

---

## 题意压缩

给定一个长度为 `n` 的 `01` 串和整数 `k`。

一次操作可以翻转两个位置：`i` 和 `i+k`。

问能否通过若干次操作，把整个串变成全 `0`。

---

## 关键观察

位置按下标对 `k` 取模后，会分成 `k` 条独立的链：

```text
r, r+k, r+2k, ...
```

一次操作只会在同一条链里翻转相邻两个位置。

所以每条链里 `1` 的个数奇偶性不会变，因为一次操作要么：

- 把两个 `0` 变成两个 `1`，`1` 的数量增加 `2`；
- 把两个 `1` 变成两个 `0`，`1` 的数量减少 `2`；
- 一个 `0` 一个 `1`，`1` 的数量不变。

最终全是 `0`，每条链中 `1` 的数量都必须是偶数。

反过来，如果每条链的 `1` 数量都是偶数，也可以从左到右把它们两两消掉。

---

## 思路步骤

1. 开一个长度为 `k` 的数组 `parity`。
2. 扫描字符串，如果 `s[i]=='1'`，就翻转 `parity[i%k]`。
3. 如果所有 `parity` 都是 `0`，输出 `YES`，否则输出 `NO`。

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

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        string s;
        cin >> n >> k >> s;

        vector<int> parity(k, 0);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') parity[i % k] ^= 1;
        }

        bool ok = true;
        for (int x : parity) ok &= (x == 0);

        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}
```

---

## 一句话总结

这题就是：**每个 `i mod k` 的链里，`1` 的个数奇偶性必须为偶数。**
