# CF 2234 A - Euclid, Sequence and Two Numbers

**题目链接**：<https://codeforces.com/problemset/problem/2234/A>

**题型**：数学 / 欧几里得算法 / 排序

**难度体感**：A 题，关键是看出欧几里得序列必须按非增顺序排列。

---

## 题意压缩

给一个长度为 `n` 的序列 `b`。问能否重排它，使它成为某两个正整数 `x >= y` 的欧几里得算法序列：

\[
a_1=x,\quad a_2=y,\quad a_{i+2}=a_i \bmod a_{i+1}
\]

如果可以，输出一组 `x y`；否则输出 `-1`。

---

## 关键观察

因为：

\[
a_i \bmod a_{i+1} < a_{i+1}
\]

所以从第三项开始，每一项都小于前一项。同时又有 `x >= y`，因此整个序列一定是**非增**的。

也就是说，`b` 如果能重排成合法序列，那么唯一可能的顺序就是从大到小排序。

---

## 思路步骤

1. 将 `b` 降序排序。
2. 检查每个 `i >= 3` 是否满足：

\[
b_i = b_{i-2} \bmod b_{i-1}
\]

3. 如果全部满足，输出 `b[0] b[1]`。
4. 否则输出 `-1`。

---

## 易错点

- 不需要枚举排列，降序顺序是唯一候选；
- `n=2` 时只需要输出排序后的前两项即可；
- 用 `long long` 更稳。

---

## 复杂度

\[
O(n \log n)
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
        vector<long long> b(n);
        for (auto &x : b) cin >> x;

        sort(b.rbegin(), b.rend());

        bool ok = true;
        for (int i = 0; i + 2 < n; ++i) {
            if (b[i + 2] != b[i] % b[i + 1]) {
                ok = false;
                break;
            }
        }

        if (ok) cout << b[0] << ' ' << b[1] << '\n';
        else cout << -1 << '\n';
    }

    return 0;
}
```

---

## 一句话总结

欧几里得序列天然非增，所以先降序排序，再逐项验证取模关系。
