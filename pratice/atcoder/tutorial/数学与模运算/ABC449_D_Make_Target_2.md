# ABC449 D - Make Target 2

## 网址

https://atcoder.jp/contests/abc449/tasks/abc449_d

## 题解

把点分成两类，避免重复统计。

第一类：`|x| > |y|`，此时最大值是 `|x|`，只枚举偶数 `x`，统计满足 `-|x| < y < |x|` 且在矩形内的 `y` 数量。

第二类：`|x| <= |y|`，此时最大值是 `|y|`，只枚举偶数 `y`，统计满足 `-|y| <= x <= |y|` 且在矩形内的 `x` 数量。

两类互不重叠，相加即可。

时间复杂度：`O((R-L+1)+(U-D+1))`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll L, R, D, U;
    cin >> L >> R >> D >> U;

    ll ans = 0;

    for (ll x = L; x <= R; x++) {
        if (x % 2 != 0) continue;

        ll ax = llabs(x);
        ll low = max(D, -ax + 1);
        ll high = min(U, ax - 1);
        if (low <= high) ans += high - low + 1;
    }

    for (ll y = D; y <= U; y++) {
        if (y % 2 != 0) continue;

        ll ay = llabs(y);
        ll low = max(L, -ay);
        ll high = min(R, ay);
        if (low <= high) ans += high - low + 1;
    }

    cout << ans << '\n';
    return 0;
}
```

## 样例验证

代码按 `max(|x|,|y|)` 的来源拆成互斥两类统计。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
