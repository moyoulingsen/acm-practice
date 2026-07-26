# CF 1092 B - Teams Forming

**题目链接**：<https://codeforces.com/problemset/problem/1092/B>

**题型**：排序 / 贪心

---

## 题意压缩

偶数个学生两两组队，低技能者可以训练到高技能者，求最小训练量。

---

## 关键观察

排序后相邻配对最优，跨区间配对只会让差值更大。

---

## 思路步骤

1. 排序。
2. 每两个相邻元素配对。
3. 累加差值。

---

## 复杂度

`O(n log n)`。

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
    vector<int> a(n);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i < n; i += 2) ans += a[i + 1] - a[i];
    cout << ans << '\n';
    return 0;
}
```

---

## 一句话总结

排序后相邻两两配对。
