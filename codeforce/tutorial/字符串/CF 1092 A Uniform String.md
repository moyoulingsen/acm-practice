# CF 1092 A - Uniform String

**题目链接**：<https://codeforces.com/problemset/problem/1092/A>

**题型**：构造 / 字符串

**难度体感**：A 题标准构造。

---

## 题意压缩

构造一个长度为 `n` 的字符串，只使用前 `k` 个小写字母，并满足题目要求的“uniform”性质。

这题本质上就是让你输出一个合法构造。

---

## 关键观察

最简单的构造就是：

- 先按顺序写 `abc...` 的前 `k` 个字母
- 然后不断循环重复

也就是：

\[
s_i = 'a' + (i \bmod k)
\]

这样：

- 只会用到前 `k` 个字母
- 构造显然合法
- 实现也最简单

---

## 思路步骤

1. 读入 `n,k`
2. 对每个位置 `i` 输出 `char('a' + i % k)`

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
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cout << char('a' + (i % k));
        }
        cout << '\n';
    }
    return 0;
}
```

---

## 一句话总结

这题就是：**把前 `k` 个字母循环输出到长度 `n`。**
