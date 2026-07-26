# ABC453 C - Sneaking Glances

## 网址

https://atcoder.jp/contests/abc453/tasks/abc453_c

## 题解

每次移动可以选择正方向或负方向，`N <= 20`，因此可以枚举所有 `2^N` 种方向序列。

为了避免小数，把所有坐标和距离乘以 2。初始坐标 `0.5` 变成 `1`，第 `i` 次移动距离变成 `2L_i`。

一次移动前后坐标符号相反时，说明经过了 `0`。

时间复杂度：`O(N 2^N)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int sign(ll x) {
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}

int main() {
    int N;
    cin >> N;

    vector<ll> L(N);
    for (auto &x : L) {
        cin >> x;
        x *= 2;
    }

    int ans = 0;
    for (int mask = 0; mask < (1 << N); mask++) {
        ll pos = 1;
        int cnt = 0;

        for (int i = 0; i < N; i++) {
            ll nxt = pos;
            if ((mask >> i) & 1) nxt += L[i];
            else nxt -= L[i];

            if (sign(pos) * sign(nxt) < 0) cnt++;
            pos = nxt;
        }

        ans = max(ans, cnt);
    }

    cout << ans << '\n';
    return 0;
}
```

## 样例验证

```text
输入
5
2 5 2 2 1

输出
4
```

```text
输入
5
100 1 2 3 4

输出
1
```

```text
输入
20
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

输出
20
```
