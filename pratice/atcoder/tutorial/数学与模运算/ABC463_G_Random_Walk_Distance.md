# ABC463 G - Random Walk Distance

## 网址

https://atcoder.jp/contests/abc463/tasks/abc463_g

## 题解

走 `N` 步，每步等概率 `+1` 或 `-1`。若有 `i` 步为 `+1`，最终位置为：

```text
x = 2i - N
```

概率为 `C(N,i) / 2^N`。要求：

```text
E(|x - X|)
```

若 `|X| >= N`，所有可能的 `x` 都在 `[-N,N]` 内，绝对值符号方向固定，且 `E(x)=0`，答案直接是 `|X|`。

否则令：

```text
M = ceil((N + X) / 2)
```

当 `i < M` 时有 `2i - N < X`。设：

```text
S0 = sum_{i=0}^{M-1} C(N,i)
S1 = sum_{i=0}^{M-1} i * C(N,i)
```

可推出：

```text
E(|x-X|) = -X + 2^(1-N) * ((N+X) * S0 - 2 * S1)
```

问题变成对很多组 `(N,M)` 快速求二项式前缀和。直接逐项求会超时，需要离线处理。

维护当前 `(n,m)` 下的：

```text
S0(n,m) = sum_{i=0}^{m-1} C(n,i)
S1(n,m) = sum_{i=0}^{m-1} i*C(n,i)
```

使用类似莫队的顺序排序查询，使 `n` 和 `m` 的移动总量可控。移动时用组合数恒等式更新：

- 改变 `m`：直接加入或删除边界项 `C(n,m)`；
- 改变 `n`：利用 `C(n+1,i)=C(n,i)+C(n,i-1)` 推导出 `O(1)` 更新。

预处理阶乘和逆阶乘后，单个组合数 `C(n,k)` 可以 `O(1)` 求出。

时间复杂度约为 `O((Nmax + T) sqrt T)`，可通过 `T, N <= 2e5`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int NMAX = 200000;

long long mod_pow(long long a, long long e) {
    long long r = 1;
    while (e > 0) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int norm(long long x) {
    x %= MOD;
    if (x < 0) x += MOD;
    return (int)x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    vector<int> N(T), X(T), M(T);
    for (int i = 0; i < T; i++) {
        cin >> N[i] >> X[i];
        long long m = ((long long)N[i] + X[i] + 1) / 2;
        if (m < 0) m = 0;
        if (m > N[i]) m = N[i];
        M[i] = (int)m;
    }

    vector<int> fact(NMAX + 1), ifact(NMAX + 1);
    fact[0] = 1;
    for (int i = 1; i <= NMAX; i++) fact[i] = 1LL * fact[i - 1] * i % MOD;

    ifact[NMAX] = mod_pow(fact[NMAX], MOD - 2);
    for (int i = NMAX; i >= 1; i--) ifact[i - 1] = 1LL * ifact[i] * i % MOD;

    auto C = [&](int n, int k) -> int {
        if (n < 0 || k < 0 || k > n) return 0;
        return 1LL * fact[n] * ifact[k] % MOD * ifact[n - k] % MOD;
    };

    int inv2 = (MOD + 1) / 2;
    vector<int> invpow2(NMAX + 1);
    invpow2[0] = 1;
    for (int i = 1; i <= NMAX; i++) invpow2[i] = 1LL * invpow2[i - 1] * inv2 % MOD;

    int width = max(1, (int)(NMAX / sqrt((double)max(1, T))));
    vector<int> ord(T);
    iota(ord.begin(), ord.end(), 0);

    sort(ord.begin(), ord.end(), [&](int a, int b) {
        int ba = N[a] / width;
        int bb = N[b] / width;
        if (ba != bb) return ba < bb;
        if (ba & 1) return M[a] > M[b];
        return M[a] < M[b];
    });

    vector<int> sum0(T), sum1(T);
    int curN = 0, curM = 0;
    int s0 = 0;
    int s1 = 0;

    for (int id : ord) {
        int targetN = N[id];
        int targetM = M[id];

        while (curN < targetN) {
            int c = C(curN, curM - 1);
            int ns1 = norm(2LL * s1 + s0 - 1LL * curM * c);
            int ns0 = norm(2LL * s0 - c);
            s0 = ns0;
            s1 = ns1;
            curN++;
        }

        while (curN > targetN) {
            curN--;
            int c = C(curN, curM - 1);
            s0 = 1LL * norm((long long)s0 + c) * inv2 % MOD;
            s1 = 1LL * norm((long long)s1 - s0 + 1LL * curM * c) * inv2 % MOD;
        }

        while (curM < targetM) {
            int c = C(curN, curM);
            s0 = norm((long long)s0 + c);
            s1 = norm((long long)s1 + 1LL * curM * c);
            curM++;
        }

        while (curM > targetM) {
            curM--;
            int c = C(curN, curM);
            s0 = norm((long long)s0 - c);
            s1 = norm((long long)s1 - 1LL * curM * c);
        }

        sum0[id] = s0;
        sum1[id] = s1;
    }

    for (int i = 0; i < T; i++) {
        int ans;
        if (abs(X[i]) >= N[i]) {
            ans = abs(X[i]) % MOD;
        } else {
            long long inside = ((long long)(N[i] + X[i]) * sum0[i] - 2LL * sum1[i]) % MOD;
            ans = norm(1LL * invpow2[N[i] - 1] * inside - X[i]);
        }
        cout << ans << '\n';
    }

    return 0;
}
```

## 样例验证

代码实现官方公式，并用离线移动维护二项式前缀和。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
