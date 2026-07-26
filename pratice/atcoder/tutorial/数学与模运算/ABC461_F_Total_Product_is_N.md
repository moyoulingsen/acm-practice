# ABC461 F - Total Product is N

## 网址

https://atcoder.jp/contests/abc461/tasks/abc461_f

## 题解

给定 `N`，考虑所有非空正整数序列 `A`，满足：

- 序列中元素两两不同；
- 所有元素乘积为 `N`。

一个序列的得分是所有元素之和。要求所有合法序列的得分总和，模 `998244353`。

因为乘积为 `N`，每个元素都必须是 `N` 的约数。先枚举 `N` 的所有约数。`N <= 10^10` 时约数个数最多约 `2304`，而合法集合大小也很小，因为 `14! > 10^10`，所以长度开到 `14` 足够。

先统计无序集合，最后乘上排列数。定义：

```text
cnt[len][p] = 选 len 个不同约数，乘积为 p 的集合数量
sum[len][p] = 上述集合中元素和的总和
```

其中 `p` 只会是 `N` 的约数，离散化到下标。

枚举每个约数 `x`，倒序枚举 `len`，若当前乘积 `p` 满足 `p*x` 仍是 `N` 的约数，则：

```text
cnt[len+1][p*x] += cnt[len][p]
sum[len+1][p*x] += sum[len][p] + cnt[len][p] * x
```

DP 得到的是集合。一个大小为 `len` 的集合可以排列成 `len!` 个序列，且每个排列的得分相同。因此答案为：

```text
sum_{len>=1} sum[len][N] * len!
```

时间复杂度：`O(14 * D^2)`，`D` 为约数个数。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 998244353;
const int LIM = 14;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;

    ll tmp = N;
    vector<pair<ll, int>> fac;
    for (ll p = 2; p * p <= tmp; p++) {
        if (tmp % p == 0) {
            int e = 0;
            while (tmp % p == 0) {
                tmp /= p;
                e++;
            }
            fac.push_back({p, e});
        }
    }
    if (tmp > 1) fac.push_back({tmp, 1});

    vector<ll> divs;
    function<void(int, ll)> dfs = [&](int idx, ll cur) {
        if (idx == (int)fac.size()) {
            divs.push_back(cur);
            return;
        }

        auto [p, e] = fac[idx];
        ll val = 1;
        for (int i = 0; i <= e; i++) {
            dfs(idx + 1, cur * val);
            val *= p;
        }
    };
    dfs(0, 1);
    sort(divs.begin(), divs.end());

    int D = (int)divs.size();
    unordered_map<ll, int> id;
    id.reserve(D * 2);
    for (int i = 0; i < D; i++) id[divs[i]] = i;

    vector<vector<ll>> cnt(LIM + 1, vector<ll>(D));
    vector<vector<ll>> sum(LIM + 1, vector<ll>(D));
    cnt[0][id[1]] = 1;

    for (ll x : divs) {
        ll xm = x % MOD;
        for (int len = LIM - 1; len >= 0; len--) {
            for (int i = 0; i < D; i++) {
                if (cnt[len][i] == 0 && sum[len][i] == 0) continue;

                ll p = divs[i];
                if (p > N / x) continue;
                ll np = p * x;
                if (N % np != 0) continue;

                int j = id[np];
                cnt[len + 1][j] = (cnt[len + 1][j] + cnt[len][i]) % MOD;
                sum[len + 1][j] = (sum[len + 1][j] + sum[len][i] + cnt[len][i] * xm) % MOD;
            }
        }
    }

    vector<ll> fact(LIM + 1, 1);
    for (int i = 1; i <= LIM; i++) fact[i] = fact[i - 1] * i % MOD;

    ll ans = 0;
    int target = id[N];
    for (int len = 1; len <= LIM; len++) {
        ans = (ans + sum[len][target] * fact[len]) % MOD;
    }

    cout << ans << '\n';
    return 0;
}
```

## 样例验证

代码先统计互异约数集合，再乘以排列数转成序列贡献。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
