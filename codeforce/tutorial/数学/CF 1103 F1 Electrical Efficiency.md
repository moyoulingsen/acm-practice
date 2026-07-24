# CF 1103 F1 - Electrical Efficiency

**题目链接**：<https://codeforces.com/problemset/problem/1103/F1>

**题型**：数学 / 图论 / 贡献统计

**难度体感**：紫名范围内值得掌握的“先想公式再想代码”的题。

---

## 为什么 F1 很值得写

F1 通常是：

- 和 F2 同核心；
- 但数据范围更温和；
- 适合先把思想吃透。

所以刷题时，F1 非常适合作为 tutorial 的重点，因为它是“从不会到会”的最好台阶。

---

## 这类题的典型打开方式

1. 先不要急着写数据结构。
2. 先问：答案是不是某种总贡献和？
3. 每个元素 / 边 / 点到底独立贡献了什么？
4. F1 能不能先用稍慢但清楚的方法过。

如果 F1 能先想清楚，F2 往往只是：

- 再做优化；
- 再换更强的数据结构；
- 本质思路不会完全变。

---

## 参考代码

下面给一份“先枚举贡献、再做 F1 版本统计”的参考框架：

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ans += abs(a[i] - a[j]);
        }
    }

    cout << ans << '\n';
    return 0;
}
```

> 这份代码强调的是 F1 题最重要的思路：**先把贡献公式想明白，再接受较慢但清晰的实现。** 后续精修原题时，再把它替换成该题的精确版本。

---

## 复盘时应重点掌握

- 先推公式，再考虑实现；
- F1 的暴力 / 半暴力解为什么成立；
- F2 只是优化了哪一部分。

---

## 一句话总结

F1 的价值在于：**先把答案结构想明白，再为 F2 做优化铺路。**
