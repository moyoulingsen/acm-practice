# CF 2234 C - Vessels, Heights and Two Versions (Easy Version)

**题目链接**：<https://codeforces.com/problemset/problem/2234/C>

**题型**：模拟 / 前后缀最大值 / 环形枚举

**难度体感**：C 题 Easy，重点是固定空杯位置后直接算每个位置最多能装多少水。

---

## 题意压缩

有 `n` 个环形排列的容器，高度为 `h[i]`。对每个位置 `s`，把它看作空位置，要求计算其他位置最多能形成的水量总和。

Easy 版允许直接对每个 `s` 枚举计算。

---

## 关键观察

固定空位置 `s` 后，一个位置能装的水量受左右两边最高障碍共同限制。

在环上从 `s` 出发：

- 顺时针方向维护左侧最大高度 `w1`；
- 逆时针方向维护右侧最大高度 `w2`；
- 某点最终水位为 `min(w1[i], w2[i])`。

Easy 版直接对每个 `s` 都做两遍扫描即可。

---

## 思路步骤

1. 枚举空位置 `s`。
2. 从 `s` 顺时针扫一圈，得到每个点左侧最大高度 `w1`。
3. 从 `s` 逆时针扫一圈，得到每个点右侧最大高度 `w2`。
4. 对每个位置累加 `min(w1[i], w2[i])`。
5. 输出每个 `s` 对应答案。

---

## 易错点

- 数组是环形，取下标要 `% n`；
- 空位置自身水位为 0；
- 求和用 `long long`。

---

## 复杂度

\[
O(n^2)
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
        vector<int> h(n);
        for (int &x : h) cin >> x;

        for (int s = 0; s < n; ++s) {
            vector<int> w1(n), w2(n);

            for (int i = 1; i < n; ++i) {
                int cur = (s + i) % n;
                int pre = (s + i - 1) % n;
                w1[cur] = max(w1[pre], h[pre]);
            }

            for (int i = 1; i < n; ++i) {
                int cur = (s + n - i) % n;
                int pre = (s + n - i + 1) % n;
                w2[cur] = max(w2[pre], h[cur]);
            }

            long long ans = 0;
            for (int i = 0; i < n; ++i) {
                ans += min(w1[i], w2[i]);
            }

            cout << ans << " \n"[s + 1 == n];
        }
    }

    return 0;
}
```

---

## 一句话总结

固定空杯后，从两边各扫出最高挡板，每点水位就是两侧最大值的较小者。
