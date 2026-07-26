# Edu 190 A - Optimal Purchase

**题目链接**：<https://codeforces.com/problemset/problem/2230/A>

**题型**：数学 / 分类讨论

**难度**：800

---

## 题意压缩

需要买 `n` 个物品，单买价格为 `a`，每组三个的价格为 `b`。问最小花费。

---

## 关键观察

只需要比较三种方案：

1. 全部单买：`n * a`；
2. 买 `n / 3` 组，剩下的单买；
3. 多买一组，覆盖余数。

因为优惠包固定是三个一组，除了最后余数外没有其他复杂情况。

---

## 思路步骤

1. 令 `c = n / 3`，`d = n % 3`。
2. 计算：
   - `n * a`
   - `c * b + d * a`
   - `(c + 1) * b`
3. 取最小值。

---

## 复杂度

`O(1)`。

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
        long long n, a, b;
        cin >> n >> a >> b;

        long long c = n / 3;
        long long d = n % 3;

        long long ans = min({n * a, c * b + d * a, (c + 1) * b});
        cout << ans << '\n';
    }

    return 0;
}
```

---

## 一句话总结

三件套优惠只会影响最后的余数，比较“补单买”和“多买一组”即可。
