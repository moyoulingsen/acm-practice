# ABC457 F - Second Gap

## 网址

https://atcoder.jp/contests/abc457/tasks/abc457_f

## 题解

官方做法从后往前插入元素。只关心相对大小，设：

```text
dp[i][a] = 后缀 P_i..P_N 的相对大小方案数，其中最大值位置为 a
```

关键是不需要记录第二大值的位置。

从 `i+1` 转移到 `i` 时：

1. `P_i` 成为最大值：原最大值位置必须是 `i + D_i`，新最大位置为 `i`；
2. `P_i` 成为第二大值：原最大值位置也必须是 `i + D_i`，最大位置不变；
3. `P_i` 既不是最大也不是第二大：最大和第二大的位置不变，只有当 `D_i == D_{i+1}` 时允许。

第 3 类是整体乘常数，用全局系数 `coef` 延迟维护。

时间复杂度：`O(N)` 均摊。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
const int64 MOD = 998244353;

int64 mod_pow(int64 a, int64 e) {
    int64 r = 1;
    while (e > 0) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> D(N - 1);
    for (int i = 0; i < N - 1; i++) cin >> D[i];

    unordered_map<int, int64> dp;
    dp.reserve(N * 2);

    dp[N - 1] = 1;
    dp[N - 2] = (dp[N - 2] + 1) % MOD;

    int64 coef = 1;

    for (int i = N - 3; i >= 0; i--) {
        int j = i + D[i];

        int64 v = 0;
        auto it = dp.find(j);
        if (it != dp.end()) v = it->second;

        if (D[i] == D[i + 1]) {
            int64 c = N - i - 2;
            coef = coef * c % MOD;

            int64 add = v * mod_pow(c, MOD - 2) % MOD;

            dp[j] += add;
            dp[j] %= MOD;

            dp[i] += add;
            dp[i] %= MOD;
        } else {
            dp.clear();
            if (v != 0) {
                dp[j] = v;
                dp[i] = (dp[i] + v) % MOD;
            }
        }
    }

    int64 ans = 0;
    for (auto &[_, val] : dp) {
        ans += val;
        ans %= MOD;
    }

    ans = ans * coef % MOD;
    cout << ans << '\n';
    return 0;
}
```

## 样例验证

```text
输入
3
1 1

输出
4
```

```text
输入
5
1 2 2 1

输出
0
```

```text
输入
15
4 4 4 4 4 4 3 2 2 2 2 2 1 1

输出
70270200
```
