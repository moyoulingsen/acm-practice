# CF 2228 B - Remilia Plays Soku

**题目链接**：<https://codeforces.com/problemset/problem/2228/B>

**题型**：数学 / 环形距离

---

## 题意压缩

两人在长度为 `n` 的环上行动，给出初始位置和 Remilia 可拖延的步数 `k`，求最优情况下被抓到的时间。

---

## 关键观察

先算两人在环上的最短距离：

```text
d = min(abs(x1 - x2), n - abs(x1 - x2))
```

当 `n <= 3` 时，空间太小，答案固定为 `1`。

否则 Remilia 可以把 `k` 步全部用于拖延，所以答案是：

```text
d + k
```

---

## 思路步骤

1. 读入 `n, x1, x2, k`。
2. 若 `n <= 3` 输出 `1`。
3. 否则计算环形最短距离，加上 `k`。

---

## 复杂度

`O(1)` 每组数据。

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
        long long n, x1, x2, k;
        cin >> n >> x1 >> x2 >> k;

        if (n <= 3) {
            cout << 1 << '\n';
        } else {
            long long diff = llabs(x1 - x2);
            long long d = min(diff, n - diff);
            cout << d + k << '\n';
        }
    }
    return 0;
}
```

---

## 一句话总结

答案就是环形最短距离加拖延步数，特判小环。
