# ABC459 E - Select from Subtrees

## 网址

https://atcoder.jp/contests/abc459/tasks/abc459_e

## 题解

树上每个点 `i` 有若干糖果，松鼠 `i` 要从以 `i` 为根的子树中选择 `D_i` 个可区分糖果，且所有松鼠选择的糖果不能重复。要求方案数。

按后序处理树。设：

- `S_i`：子树 `i` 中糖果总数；
- `T_i`：子树 `i` 中所有松鼠需要选择的糖果总数。

当处理到点 `i` 时，它的所有后代已经选择了 `T_i - D_i` 个糖果，所以此时子树 `i` 中还剩：

```text
S_i - (T_i - D_i) = S_i - T_i + D_i
```

个可选糖果。松鼠 `i` 从中选择 `D_i` 个，方案数为：

```text
C(S_i - T_i + D_i, D_i)
```

最终答案是所有点贡献的乘积。如果某一步可选数量不足，则答案为 `0`。

由于 `D_i` 总和受限，可以用：

```text
C(n,k) = n(n-1)...(n-k+1) / k!
```

在 `O(k)` 时间计算，其中 `n` 可能很大，`k=D_i`。

时间复杂度：`O(N + sum D_i)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 998244353;

ll mod_pow(ll a, ll e) {
    ll r = 1;
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

    vector<vector<int>> g(N);
    for (int i = 1; i < N; i++) {
        int p;
        cin >> p;
        --p;
        g[p].push_back(i);
    }

    vector<ll> C(N);
    for (int i = 0; i < N; i++) cin >> C[i];

    vector<int> D(N);
    int maxD = 0;
    for (int i = 0; i < N; i++) {
        cin >> D[i];
        maxD = max(maxD, D[i]);
    }

    vector<ll> fact(maxD + 1), ifact(maxD + 1);
    fact[0] = 1;
    for (int i = 1; i <= maxD; i++) fact[i] = fact[i - 1] * i % MOD;

    ifact[maxD] = mod_pow(fact[maxD], MOD - 2);
    for (int i = maxD; i >= 1; i--) ifact[i - 1] = ifact[i] * i % MOD;

    auto comb = [&](ll n, int k) {
        if (n < k) return 0LL;
        ll res = 1;
        for (int i = 0; i < k; i++) res = res * ((n - i) % MOD) % MOD;
        return res * ifact[k] % MOD;
    };

    vector<int> order = {0};
    for (int i = 0; i < (int)order.size(); i++) {
        int v = order[i];
        for (int to : g[v]) order.push_back(to);
    }
    reverse(order.begin(), order.end());

    vector<ll> rem(N);
    ll ans = 1;

    for (int v : order) {
        ll available = C[v];
        for (int to : g[v]) available += rem[to];

        ans = ans * comb(available, D[v]) % MOD;
        rem[v] = available - D[v];
    }

    cout << ans << '\n';
    return 0;
}
```

## 样例验证

代码按后序统计每个子树中后代选完后剩余糖果数量，并乘上组合数。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
