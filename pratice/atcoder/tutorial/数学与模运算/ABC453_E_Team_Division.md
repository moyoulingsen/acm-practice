# ABC453 E - Team Division

## 网址

https://atcoder.jp/contests/abc453/tasks/abc453_e

## 题解

枚举队伍 `A` 的人数 `a=1..N-1`，队伍 `B` 人数为 `b=N-a`。对每个选手，按他是否能进入人数为 `a` 的队、是否能进入人数为 `b` 的队分类：

- `both`：两个队都能进；
- `onlyA`：只能进 `A`；
- `onlyB`：只能进 `B`；
- `none`：哪个队都不能进。

若 `none>0`、`onlyA>a` 或 `onlyB>b`，本 `a` 无贡献。否则必须把所有 `onlyA` 放入 `A`，所有 `onlyB` 放入 `B`，再从 `both` 中选 `a-onlyA` 人进入 `A`，贡献：

```text
C(both, a-onlyA)
```

随着 `a` 从小到大变化，每个选手的分类只会在少数边界变化。把这些变化点做成事件，扫描 `a` 时更新分类计数即可。

时间复杂度：`O(N log MOD)`，主要来自组合数预处理的逆元。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 998244353;

ll modpow(ll a, ll e) {
    ll r = 1;
    while (e) {
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

    vector<int> L(N), R(N);
    vector<vector<int>> events(N + 2);

    for (int i = 0; i < N; i++) {
        cin >> L[i] >> R[i];

        auto add_event = [&](int x) {
            if (1 <= x && x <= N - 1) events[x].push_back(i);
        };

        add_event(L[i]);
        add_event(R[i] + 1);
        add_event(N - R[i]);
        add_event(N - L[i] + 1);
    }

    vector<ll> fact(N + 1), ifact(N + 1);
    fact[0] = 1;
    for (int i = 1; i <= N; i++) fact[i] = fact[i - 1] * i % MOD;
    ifact[N] = modpow(fact[N], MOD - 2);
    for (int i = N; i >= 1; i--) ifact[i - 1] = ifact[i] * i % MOD;

    auto C = [&](int n, int k) -> ll {
        if (k < 0 || k > n) return 0;
        return fact[n] * ifact[k] % MOD * ifact[n - k] % MOD;
    };

    vector<int> canA(N), canB(N);
    int cnt[2][2] = {};
    cnt[0][0] = N;

    ll ans = 0;

    for (int a = 1; a <= N - 1; a++) {
        for (int idx : events[a]) {
            cnt[canA[idx]][canB[idx]]--;

            canA[idx] = (L[idx] <= a && a <= R[idx]);
            int b = N - a;
            canB[idx] = (L[idx] <= b && b <= R[idx]);

            cnt[canA[idx]][canB[idx]]++;
        }

        int none = cnt[0][0];
        int onlyA = cnt[1][0];
        int onlyB = cnt[0][1];
        int both = cnt[1][1];
        int b = N - a;

        if (none == 0 && onlyA <= a && onlyB <= b) {
            ans += C(both, a - onlyA);
            ans %= MOD;
        }
    }

    cout << ans << '\n';
    return 0;
}
```

## 样例验证

```text
输入
3
1 1
1 2
2 2

输出
2
```

```text
输入
6
1 5
1 5
2 5
1 3
3 5
2 5

输出
30
```
