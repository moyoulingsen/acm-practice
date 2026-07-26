# CF 1096 C - Snowfall

**真实题号**：CF 2227 C

**题目链接**：<https://codeforces.com/problemset/problem/2227/C>

**题型**：构造 / 数学 / 分类讨论

**难度体感**：800，关键是看出只和因子 `2`、`3` 有关。

---

## 题意压缩

给定一个数组，可以任意重排。

一个子数组的乘积如果能被 `6` 整除，就会产生贡献。

要求构造一种重排方式，让这种子数组数量尽量少，输出任意一种最优重排。

---

## 关键观察

乘积能被 `6` 整除，等价于这个子数组里同时出现：

- 至少一个因子 `2`；
- 至少一个因子 `3`。

所以每个数只需要按是否贡献 `2`、是否贡献 `3` 分类。

分成四类：

- `S6`：能被 `6` 整除，同时贡献 `2` 和 `3`；
- `S2`：能被 `2` 整除，但不能被 `3` 整除；
- `S3`：能被 `3` 整除，但不能被 `2` 整除；
- `S1`：既不贡献 `2`，也不贡献 `3`。

---

## 如何构造

最优顺序可以写成：

```text
S6 + S2 + S1 + S3
```

原因是：

- `S2` 和 `S3` 一旦靠近，中间跨过去的子数组就容易同时含有 `2` 和 `3`；
- `S1` 放在它们中间，可以尽量隔开两类危险元素；
- `S6` 自己已经同时含有 `2` 和 `3`，放在一端即可。

---

## 思路步骤

1. 扫描数组，把每个数分到四个桶里。
2. 按 `S6, S2, S1, S3` 的顺序输出。

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
        int n;
        cin >> n;

        vector<int> s6, s2, s1, s3;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (x % 6 == 0) s6.push_back(x);
            else if (x % 2 == 0) s2.push_back(x);
            else if (x % 3 == 0) s3.push_back(x);
            else s1.push_back(x);
        }

        vector<int> ans;
        for (int x : s6) ans.push_back(x);
        for (int x : s2) ans.push_back(x);
        for (int x : s1) ans.push_back(x);
        for (int x : s3) ans.push_back(x);

        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " \n"[i + 1 == n];
        }
    }
    return 0;
}
```

---

## 一句话总结

这题就是：**按是否含因子 `2`、`3` 分类，然后把 `2` 类和 `3` 类尽量隔开。**
