# CF 2218 E - The 67th XOR Problem

**题目链接**：<https://codeforces.com/problemset/problem/2218/E>

**对应题单**：CF 1090 Div.4 E

**题型**：位运算 / 暴力枚举

**难度**：1200

---

## 题意压缩

给定数组。每次选择当前一个元素 `x`，把所有元素都异或 `x`，然后删除这个元素。重复直到只剩一个数，问最后剩下的数最大能是多少。

---

## 关键观察

分析操作可以发现，最终剩下的值只和两类原始元素有关：

- 最后一次被选择删除的元素；
- 从头到尾没有被选择、最终留下的元素。

最终值会等于这两个原始元素的异或。

并且任意一对原始元素都可以通过安排删除顺序实现。

所以答案就是：

\[
\max_{i<j}(a_i \oplus a_j)
\]

由于题目总 `n` 不大，直接两层循环枚举即可。

---

## 思路步骤

1. 读入数组。
2. 枚举所有 `i<j`。
3. 用 `a[i] ^ a[j]` 更新答案。

---

## 复杂度

`O(n^2)`。

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
        int n;
        cin >> n;

        vector<long long> a(n);
        for (auto &x : a) cin >> x;

        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ans = max(ans, a[i] ^ a[j]);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
```

---

## 一句话总结

所有操作最后只等价于保留某一对原始数的异或，枚举最大 pair xor 即可。
