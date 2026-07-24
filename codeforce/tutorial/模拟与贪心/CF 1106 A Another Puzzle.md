# CF 1106 A - Another Puzzle

**题目链接**：<https://codeforces.com/problemset/problem/1106/A>

**题型**：构造 / 观察

**难度体感**：截图范围内的低难度题，先按典型 A 题思路整理。

---

## 题意压缩

这类 A 题通常不会卡在复杂算法，而是卡在能不能把条件直接压成一个简单判定或直接构造。

---

## 关键观察

看到这种题，第一反应应该是：

1. 条件里有没有明显的奇偶性；
2. 是否只和边界值有关；
3. 能不能一行构造答案。

很多 800 分 A 题，本质就是把题面翻译成一个非常短的数学判断。

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> g(n);
    for (int i = 0; i < n; ++i) cin >> g[i];

    int ans = 0;
    for (int i = 1; i + 1 < n; ++i) {
        for (int j = 1; j + 1 < n; ++j) {
            if (g[i][j] == 'X' && g[i - 1][j - 1] == 'X' && g[i - 1][j + 1] == 'X' &&
                g[i + 1][j - 1] == 'X' && g[i + 1][j + 1] == 'X') {
                ans++;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
```

---

## 一句话总结

这题本质是：**枚举中心点，检查周围固定形状是否满足条件。**
