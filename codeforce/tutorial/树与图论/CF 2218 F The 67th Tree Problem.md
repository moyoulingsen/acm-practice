# CF 2218 F - The 67th Tree Problem

**题目链接**：<https://codeforces.com/problemset/problem/2218/F>

**对应题单**：CF 1090 Div.4 F

**题型**：树 / 构造

**难度**：1500

---

## 题意压缩

需要构造一棵以 `1` 为根、共 `x+y` 个点的树，使得：

- 恰好 `x` 个点的子树大小为偶数；
- 恰好 `y` 个点的子树大小为奇数。

若无法构造，输出 `NO`。

---

## 关键观察

令 `n=x+y`。

有两个无解情况：

1. `n` 为偶数且 `x=0`：根的子树大小是 `n`，必然是偶数；
2. `x > n/2`：偶数子树数量不可能这么多。

否则可以构造。

构造方法：

- 建一条长度为 `m = 2x + (n mod 2)` 的链；
- 剩下所有点都挂到链尾 `m` 上。

链上的子树大小会连续递减，奇偶交替；挂在链尾的额外叶子都是奇数子树，从而正好满足数量。

---

## 思路步骤

1. 判断无解条件。
2. 输出 `YES`。
3. 先输出链边 `1-2-...-m`。
4. 再把 `m+1..n` 全部连到 `m`。

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
        int x, y;
        cin >> x >> y;

        int n = x + y;
        if ((n % 2 == 0 && x == 0) || x > n / 2) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        int m = 2 * x + (n % 2);
        for (int i = 2; i <= m; ++i) {
            cout << i - 1 << ' ' << i << '\n';
        }
        for (int i = m + 1; i <= n; ++i) {
            cout << m << ' ' << i << '\n';
        }
    }

    return 0;
}
```

---

## 一句话总结

用一条奇偶交替的链控制偶子树数量，剩余点全部作为奇叶子挂到链尾。
