# ABC460 E - x + y ≡ x + y

## 网址

https://atcoder.jp/contests/abc460/tasks/abc460_e

## 题解

要求统计 `1 <= x, y <= N`，满足：

```text
concat(x, y) ≡ x + y (mod M)
```

固定 `y` 的十进制位数为 `d`，则：

```text
concat(x, y) = x * 10^d + y
```

代入同余式：

```text
x * 10^d + y ≡ x + y (mod M)
(10^d - 1) * x ≡ 0 (mod M)
```

可以发现条件和 `y` 的具体数值无关，只和 `y` 的位数有关。

令：

```text
g = gcd(10^d - 1, M)
```

则 `x` 必须是 `M/g` 的倍数，所以合法 `x` 个数为：

```text
floor(N / (M/g))
```

再乘上不超过 `N` 的 `d` 位正整数个数即可。`N <= 10^18`，枚举 `d=1..19`。

答案对 `998244353` 取模。

时间复杂度：每组 `O(19 log M)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<ll> pow10(20, 1);
    for (int i = 1; i < 20; i++) pow10[i] = pow10[i - 1] * 10;

    int T;
    cin >> T;
    while (T--) {
        ll N, M;
        cin >> N >> M;

        ll ans = 0;
        for (int d = 1; d < 20; d++) {
            ll L = pow10[d - 1];
            ll R = min(N + 1, pow10[d]);
            if (L >= R) break;

            ll yCount = R - L;
            ll g = gcd(pow10[d] - 1, M);
            ll unit = M / g;
            ll xCount = N / unit;

            ans = (ans + (yCount % MOD) * (xCount % MOD)) % MOD;
        }

        cout << ans << '\n';
    }

    return 0;
}
```

## 样例验证

代码按 `y` 的位数分组，利用同余化简后直接计数。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
