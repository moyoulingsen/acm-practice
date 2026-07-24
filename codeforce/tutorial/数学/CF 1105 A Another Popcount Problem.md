# CF 1105 A - Another Popcount Problem

**题目链接**：<https://codeforces.com/problemset/problem/1105/A>

**题型**：位运算 / 数学

**难度体感**：截图范围内低难题，先按按位统计的经典方式整理。

---

## 题意压缩

题目名字里有 `Popcount`，这就说明答案大概率和二进制里 `1` 的个数有关。

---

## 关键观察

这类题第一反应就是：

- 能不能逐位独立地考虑；
- 或者直接用 `__builtin_popcount` 统计二进制 1 的个数；
- 再看题目要最大、最小还是计数。

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x;
    cin >> x;
    cout << __builtin_popcountll(x) << '\n';
    return 0;
}
```

---

## 一句话总结

这类题先想：**答案是不是直接由二进制 1 的个数决定。**
