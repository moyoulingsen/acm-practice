# CF 1105 B - AI Finds Nothing

**题目链接**：<https://codeforces.com/problemset/problem/1105/B>

**题型**：模拟 / 枚举

**难度体感**：1100 分左右常见模型：扫描 + 维护局部最优。

---

## 题意压缩

这类 B 题经常都是给一个字符串或数组，然后让你统计某种最长段、出现次数或者最优值。

---

## 关键观察

最常见做法就是：

- 从左到右扫；
- 维护当前连续段长度 `cur`；
- 随时更新答案 `best`。

很多 1000~1200 分的题本质都只是这个套路的不同外壳。

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
    string s;
    cin >> s;

    int ans = 0;
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        int cur = 0;
        for (char c : s) {
            if (c == ch) cur++;
            else cur = 0;
            ans = max(ans, cur / k);
        }
    }
    cout << ans << '\n';
    return 0;
}
```

---

## 一句话总结

这类题核心通常是：**线性扫描，维护当前连续段。**
