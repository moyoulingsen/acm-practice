# ABC450 G - Random Subtraction

## 网址

https://atcoder.jp/contests/abc450/tasks/abc450_g

## 题解

最后的结果 `x` 一定可以写成：

```text
x = c_1 A_1 + c_2 A_2 + ... + c_N A_N
```

其中每个 `c_i` 都是 `+1` 或 `-1`。

所以：

```text
E[x^2] = sum A_i^2 + 2 * sum_{i<j} E[c_i c_j] A_i A_j
```

由对称性，任意 `i != j` 的 `E[c_i c_j]` 相同。官方推导结果为：

- `N = 1`：交叉项系数为 `0`；
- `N = 2`：交叉项系数为 `-1`；
- `N >= 3`：交叉项系数为 `-2 / (3(N-1))`。

令 `S=sum A_i`，`Q=sum A_i^2`，因为 `S^2-Q=2*sum_{i<j}A_iA_j`，答案为：

```text
Q + d * (S^2 - Q)
```

时间复杂度：`O(N)`。

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

long long inv(long long x) {
    return mod_pow((x % MOD + MOD) % MOD, MOD - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long S = 0;
    long long Q = 0;

    for (int i = 0; i < N; i++) {
        long long a;
        cin >> a;
        a %= MOD;
        S = (S + a) % MOD;
        Q = (Q + a * a) % MOD;
    }

    long long d;
    if (N == 1) {
        d = 0;
    } else if (N == 2) {
        d = MOD - 1;
    } else {
        d = MOD - 2 * inv(3LL * (N - 1) % MOD) % MOD;
    }

    long long ans = (Q + d * ((S * S % MOD - Q + MOD) % MOD)) % MOD;
    cout << ans << '\n';
    return 0;
}
```

## 样例验证

代码为期望公式的直接实现。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
