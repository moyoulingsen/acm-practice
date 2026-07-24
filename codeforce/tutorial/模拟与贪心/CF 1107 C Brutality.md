# CF 1107 C - Brutality

**题目链接**：<https://codeforces.com/problemset/problem/1107/C>

**题型**：贪心 / 分组 / 排序

**难度体感**：C 题，核心是对连续相同字符段分别取最大的 `k` 个价值。

---

## 题意压缩

给长度为 `n` 的字符串 `s` 和每个位置的价值 `a[i]`。

可以选择一些位置，但同一段连续相同字符中，最多只能选择 `k` 个。

问最大总价值。

---

## 关键观察

限制只在“连续相同字符段”内部生效。

所以可以把字符串切成若干段：

- 每段字符都相同；
- 不同段互不影响。

对于每一段，只需要选价值最大的 `min(k, 段长)` 个。

---

## 思路步骤

1. 从左到右扫描字符串。
2. 把连续相同字符的一段价值收集到数组 `v`。
3. 对 `v` 从大到小排序。
4. 加上前 `k` 个。
5. 处理所有段，输出总和。

---

## 易错点

- 不是全局每个字符最多选 `k` 个，而是每个连续段最多 `k` 个；
- 价值和可能较大，用 `long long`。

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

    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (long long &x : a) cin >> x;

    string s;
    cin >> s;

    long long ans = 0;
    for (int l = 0; l < n; ) {
        int r = l;
        vector<long long> v;
        while (r < n && s[r] == s[l]) {
            v.push_back(a[r]);
            r++;
        }

        sort(v.rbegin(), v.rend());
        for (int i = 0; i < min(k, (int)v.size()); ++i) {
            ans += v[i];
        }

        l = r;
    }

    cout << ans << '\n';
    return 0;
}
```

---

## 一句话总结

把连续相同字符分段，每段独立选最大的 `k` 个价值。
