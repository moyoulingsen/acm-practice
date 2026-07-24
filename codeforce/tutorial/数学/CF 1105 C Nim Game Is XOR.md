# CF 1105 C - Ayoub and Lost Array

**题目链接**：<https://codeforces.com/problemset/problem/1105/C>

**题型**：DP / 取模计数

**难度体感**：1300 左右的经典 DP 题。

---

## 题意压缩

给定区间 `[l,r]`，要构造长度为 `n` 的数组，并统计满足某种模条件的方案数。

---

## 关键观察

因为题目只关心某个值模 `3` 后的结果，所以：

1. 先统计区间 `[l,r]` 中有多少个数模 `3` 分别等于 `0,1,2`；
2. 再做 DP，表示前 `i` 个位置选完后，当前和模 `3` 为多少的方案数。

这就是最标准的“小模数 DP”。

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

long long count_mod(long long l, long long r, int rem) {
    long long ans = 0;
    for (int x = rem; x <= r; x += 3) {
        if (x >= l) ans++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, l, r;
    cin >> n >> l >> r;

    long long cnt[3] = {0, 0, 0};
    for (int rem = 0; rem < 3; ++rem) {
        long long first = l + ((rem - l % 3 + 3) % 3);
        if (first > r) cnt[rem] = 0;
        else cnt[rem] = (r - first) / 3 + 1;
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(3, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int s = 0; s < 3; ++s) {
            for (int rem = 0; rem < 3; ++rem) {
                dp[i + 1][(s + rem) % 3] = (dp[i + 1][(s + rem) % 3] + dp[i][s] * cnt[rem]) % MOD;
            }
        }
    }

    cout << dp[n][0] << '\n';
    return 0;
}
```

---

## 一句话总结

这题就是：**先数出每种余数有几个，再做模 3 的 DP。**
