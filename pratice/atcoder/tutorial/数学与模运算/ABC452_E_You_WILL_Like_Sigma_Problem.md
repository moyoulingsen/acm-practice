# ABC452 E - You WILL Like Sigma Problem

## 网址

https://atcoder.jp/contests/abc452/tasks/abc452_e

## 题解

要求：

```text
sum A_i * B_j * (i mod j)
```

利用：

```text
i mod j = i - j * floor(i / j)
```

先把所有 `A_i * B_j * i` 的部分算出来：

```text
(sum A_i*i) * (sum B_j)
```

再减去：

```text
B_j * j * floor(i/j) * A_i
```

固定 `j`，对于相同的 `k=floor(i/j)`，合法 `i` 是连续区间：

```text
k*j <= i <= min(N, (k+1)*j - 1)
```

用 `A_i` 的前缀和可以快速求这段的 `sum A_i`。

总枚举次数是调和级数 `O(N log N)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<ll> A(N + 1), B(M + 1);
    vector<ll> prefA(N + 1), prefAi(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        A[i] %= MOD;
        prefA[i] = (prefA[i - 1] + A[i]) % MOD;
        prefAi[i] = (prefAi[i - 1] + A[i] * i) % MOD;
    }

    ll sumB = 0;
    for (int j = 1; j <= M; j++) {
        cin >> B[j];
        B[j] %= MOD;
        sumB = (sumB + B[j]) % MOD;
    }

    ll ans = prefAi[N] * sumB % MOD;

    for (int j = 1; j <= min(N, M); j++) {
        ll subtract = 0;

        for (ll k = 1; k * j <= N; k++) {
            int l = (int)(k * j);
            int r = (int)min<ll>(N, (k + 1) * j - 1);
            ll sumA = (prefA[r] - prefA[l - 1] + MOD) % MOD;
            subtract = (subtract + (k % MOD) * j % MOD * sumA) % MOD;
        }

        ans = (ans - B[j] * subtract) % MOD;
        if (ans < 0) ans += MOD;
    }

    cout << ans << '\n';
    return 0;
}
```

## 样例验证

```text
输入
6 4
1 6 9 2 3 1
1 10 3 7

输出
508
```

```text
输入
20 20
36625 195265 98908 111868 111868 47382 147644 472464 472464 416653 111868 195265 327972 327972 262769 75439 381156 451275 36625 195265
327972 111868 416653 177330 340019 262769 47382 262769 47382 340019 47382 262769 327972 327972 359676 381156 327972 36625 451275 381156

输出
58141644
```
