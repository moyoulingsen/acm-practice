# CF 1106 C Lunar New Year and Number Division

**题目链接**：<https://codeforces.com/problemset/problem/1106/C>

**题型**：排序 / 贪心

**难度体感**：1400 左右的经典配对题。

---

## 题意压缩

给一个数组，把它分成若干对，每对的代价是两数和的平方。要求总代价最小。

---

## 关键观察

这是一个非常典型的“最小化配对平方和”问题。

最优策略是：

- 把数组排序；
- 最小的和最大的配；
- 次小的和次大的配。

也就是标准的“两头配对”。

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
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());

    long long ans = 0;
    for (int l = 0, r = n - 1; l < r; ++l, --r) {
        long long s = a[l] + a[r];
        ans += s * s;
    }
    cout << ans << '\n';
    return 0;
}
```

---

## 一句话总结

这题就是：**排序后最小和最大配对。**
