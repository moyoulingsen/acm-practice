# CF 2228 C1 - Cirno and Number (Easy Version)

**题目链接**：<https://codeforces.com/problemset/problem/2228/C1>

**题型**：枚举 / 贪心 / 数位

---

## 题意压缩

给定数字 `a` 和允许使用的数字集合，找一个只由允许数字组成的非负整数 `b`，使 `|a-b|` 最小。

Easy 版规模很小，可以直接枚举候选范围。

---

## 关键观察

只要判断一个数的所有十进制位是否都在允许集合里，就能暴力向两边找最近合法数。

Easy 版数据范围允许这种写法。

---

## 思路步骤

1. 标记允许数字。
2. 从 `a` 开始向下找第一个合法数。
3. 从 `a` 开始向上找第一个合法数。
4. 输出两者距离最小值。

---

## 复杂度

Easy 版可接受暴力枚举。

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

bool ok(long long x, const vector<int> &can) {
    if (x == 0) return can[0];
    while (x > 0) {
        if (!can[x % 10]) return false;
        x /= 10;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        long long a;
        int n;
        cin >> a >> n;

        vector<int> can(10);
        for (int i = 0; i < n; ++i) {
            int d;
            cin >> d;
            can[d] = 1;
        }

        long long ans = (long long)4e18;
        for (long long x = a; x >= 0; --x) {
            if (ok(x, can)) {
                ans = min(ans, a - x);
                break;
            }
        }
        for (long long x = a; ; ++x) {
            if (ok(x, can)) {
                ans = min(ans, x - a);
                break;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
```

---

## 一句话总结

Easy 版直接从 `a` 往上下找最近的合法数字。
