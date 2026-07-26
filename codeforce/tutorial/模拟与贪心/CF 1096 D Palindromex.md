# CF 1096 D - Palindromex

**真实题号**：CF 2227 D

**题目链接**：<https://codeforces.com/problemset/problem/2227/D>

**题型**：回文 / 暴力枚举中心 / 实现

**难度体感**：1200，重点是把可能的回文中心缩到很少。

---

## 题意压缩

给定长度为 `2n` 的数组，其中 `0..n-1` 每个数都恰好出现两次。

要求找一个回文子数组，使这个子数组的 `mex` 最大，输出最大值。

---

## 关键观察

如果一个子数组里没有 `0`，它的 `mex` 一定是 `0`。

而随便取一个只含 `0` 的单点子数组，`mex` 至少是 `1`。

所以最优答案对应的回文子数组一定包含 `0`。

设两个 `0` 的位置为 `x,y`。

包含 `0` 的回文子数组只有三种关键中心：

1. 只包含第一个 `0`，中心在 `x`；
2. 只包含第二个 `0`，中心在 `y`；
3. 同时包含两个 `0`，两个 `0` 必须关于中心对称，中心在 `x,y` 的中点。

因此不用枚举所有中心，只需要扩展这三个中心。

---

## 如何检查一个中心

从中心向两边扩展，只要两端元素相同，就还是回文。

扩展过程中标记出现过的值，最后从 `0` 开始找第一个没出现的值，就是这个中心能得到的最大 `mex`。

---

## 思路步骤

1. 找到两个 `0` 的位置 `x,y`。
2. 分别检查中心 `(x,x)`、`(y,y)`、`((x+y)/2,(x+y+1)/2)`。
3. 每次向两边扩展回文并统计出现值。
4. 三种情况取最大值。

---

## 复杂度

每个中心最多扩展 `O(n)`，只检查三个中心。

\[
O(n)
\]

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

int check_center(int l, int r) {
    vector<int> seen(n + 1, 0);

    while (l >= 0 && r < 2 * n && a[l] == a[r]) {
        seen[a[l]] = 1;
        --l;
        ++r;
    }

    for (int mex = 0; mex <= n; ++mex) {
        if (!seen[mex]) return mex;
    }
    return n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        a.assign(2 * n, 0);

        int first_zero = -1, second_zero = -1;
        for (int i = 0; i < 2 * n; ++i) {
            cin >> a[i];
            if (a[i] == 0) {
                if (first_zero == -1) first_zero = i;
                else second_zero = i;
            }
        }

        int ans = 1;
        ans = max(ans, check_center(first_zero, first_zero));
        ans = max(ans, check_center(second_zero, second_zero));
        ans = max(ans, check_center((first_zero + second_zero) / 2,
                                    (first_zero + second_zero + 1) / 2));

        cout << ans << '\n';
    }
    return 0;
}
```

---

## 一句话总结

这题核心是：**最优回文一定包含 `0`，所以只需要围绕两个 `0` 推出三个可能中心。**
