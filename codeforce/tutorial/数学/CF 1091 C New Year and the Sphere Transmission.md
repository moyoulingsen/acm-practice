# CF 1091 C - New Year and the Sphere Transmission

**题目链接**：<https://codeforces.com/problemset/problem/1091/C>

**题型**：数学 / 数论 / 约数枚举

---

## 题意压缩

从 1 号点开始在长度为 `n` 的环上按固定步长跳，直到回到 1。对每种步长，求访问到的编号和，输出所有可能值。

---

## 关键观察

若一共访问 `m` 个点，则 `m` 一定是 `n` 的约数，访问点可写成 `1, 1+g, ..., 1+(m-1)g`，其中 `gm=n`。和为 `m + n * (m - 1) / 2`。

---

## 思路步骤

1. 枚举 `n` 的所有约数 `m`。
2. 计算 `m + n * (m - 1) / 2`。
3. 排序输出。

---

## 复杂度

`O(sqrt(n) log n)`。

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    vector<long long> ans;

    for (long long i = 1; i * i <= n; ++i) {
        if (n % i) continue;
        long long m = i;
        ans.push_back(m + n * (m - 1) / 2);
        if (i != n / i) {
            m = n / i;
            ans.push_back(m + n * (m - 1) / 2);
        }
    }

    sort(ans.begin(), ans.end());
    for (long long x : ans) cout << x << ' ';
    cout << '\n';
    return 0;
}
```

---

## 一句话总结

可能访问人数就是 `n` 的约数，套等差数列求和。
