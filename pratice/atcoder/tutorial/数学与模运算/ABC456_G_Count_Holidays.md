# ABC456 G - Count Holidays

## 网址

https://atcoder.jp/contests/abc456/tasks/abc456_g

## 题解

先求：

```text
F(k) = 合法日程中最长连续假日长度不超过 k 的方案数
```

则最长连续假日恰好为 `k` 的方案数是：

```text
F(k) - F(k-1)
```

因为固定工作日 `x` 会切断连续假日，所以把字符串按 `x` 分成若干段，每段全是 `.`。全局 `F(k)` 是各段贡献的乘积。

对长度为 `n` 的全 `.` 段，记 `f(n,k)` 为最长连续假日不超过 `k` 的方案数。如果 `k >= n`，则 `f(n,k)=2^n`。否则用官方容斥公式，单次计算复杂度约为 `O(n/(k+2))`。枚举所有 `k` 的总复杂度为 `O(N log N)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

long long mod_pow(long long a, long long e) {
    long long r = 1;
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
    string S;
    cin >> N >> S;

    vector<long long> fact(N + 1), ifact(N + 1), pow2(N + 1), invpow2(N + 1);

    fact[0] = 1;
    for (int i = 1; i <= N; i++) fact[i] = fact[i - 1] * i % MOD;

    ifact[N] = mod_pow(fact[N], MOD - 2);
    for (int i = N; i >= 1; i--) ifact[i - 1] = ifact[i] * i % MOD;

    pow2[0] = 1;
    for (int i = 1; i <= N; i++) pow2[i] = pow2[i - 1] * 2 % MOD;

    long long inv2 = (MOD + 1) / 2;
    invpow2[0] = 1;
    for (int i = 1; i <= N; i++) invpow2[i] = invpow2[i - 1] * inv2 % MOD;

    auto C = [&](int n, int r) -> long long {
        if (r < 0 || r > n || n < 0) return 0;
        return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
    };

    auto f = [&](int n, int k) -> long long {
        if (k >= n) return pow2[n];

        long long res = 0;
        int max_m = (n + 1) / (k + 2);

        for (int m = 0; m <= max_m; m++) {
            int top = n - (k + 1) * m;
            long long g = 0;

            int e1 = n - (k + 2) * m;
            if (e1 >= 0) {
                g += pow2[e1] * C(top, m) % MOD;
                g %= MOD;
            }

            int e2 = n - (k + 2) * m + 1;
            if (m >= 1 && e2 >= 0) {
                g += pow2[e2] * C(top, m - 1) % MOD;
                g %= MOD;
            }

            if (m & 1) {
                res -= g;
                if (res < 0) res += MOD;
            } else {
                res += g;
                if (res >= MOD) res -= MOD;
            }
        }

        return res;
    };

    int q = 0;
    for (char c : S) {
        if (c == '.') q++;
    }

    vector<long long> leq(N + 1, pow2[q]);

    for (int i = 0; i < N;) {
        if (S[i] == 'x') {
            i++;
            continue;
        }

        int j = i;
        while (j < N && S[j] == '.') j++;

        int len = j - i;

        for (int k = 0; k < len; k++) {
            leq[k] = leq[k] * f(len, k) % MOD * invpow2[len] % MOD;
        }

        i = j;
    }

    long long prev = leq[0];
    for (int k = 1; k <= N; k++) {
        long long ans = (leq[k] - prev + MOD) % MOD;
        cout << ans << '\n';
        prev = leq[k];
    }

    return 0;
}
```

## 样例验证

```text
输入
5
.x...

输出
9
4
2
0
0
```
