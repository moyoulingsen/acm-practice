# ABC464 F - Random Vault Heist

## 网址

https://atcoder.jp/contests/abc464/tasks/abc464_f

## 题解

随机生成一个保险箱打开顺序，从前往后打开，直到当前获得金额第一次达到或超过 `X`，求最终获得金额的期望。

设总金额为 `total`。考虑停止前已经打开的集合 `S`，若：

```text
sum(S) < X
```

则下一次一定还会打开一个保险箱。若 `|S|=k`，随机排列的前 `k` 个集合恰好为 `S` 的概率是：

```text
1 / C(N,k)
```

在剩余 `N-k` 个保险箱中，下一个箱子的期望金额为：

```text
(total - sum(S)) / (N-k)
```

因此答案为：

```text
sum_{S, sum(S)<X} (total-sum(S)) / ((N-|S|) * C(N,|S|))
```

`N<=40`，用 meet-in-the-middle。把数组分成两半，分别枚举所有子集和并按子集大小分组。对左半一个子集和 `x`，右半需要 `y < X-x`。右半每组排序并做前缀和，就能用双指针统计数量和子集和总和。

时间复杂度：`O(2^(N/2) log 2^(N/2) + N*2^(N/2))`。

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

void enumerate_subsets(const vector<ll> &a, vector<vector<ll>> &res) {
    int n = (int)a.size();
    for (int mask = 0; mask < (1 << n); mask++) {
        ll sum = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) {
                sum += a[i];
                cnt++;
            }
        }
        res[cnt].push_back(sum);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll X;
    cin >> N >> X;

    vector<ll> A(N);
    ll total = 0;
    for (ll &v : A) {
        cin >> v;
        total += v;
    }

    int n1 = N / 2;
    int n2 = N - n1;

    vector<ll> Larr(A.begin(), A.begin() + n1);
    vector<ll> Rarr(A.begin() + n1, A.end());

    vector<vector<ll>> L(n1 + 1), R(n2 + 1);
    enumerate_subsets(Larr, L);
    enumerate_subsets(Rarr, R);

    vector<vector<ll>> pref(n2 + 1);
    for (int j = 0; j <= n2; j++) {
        sort(R[j].begin(), R[j].end());
        pref[j].assign(R[j].size() + 1, 0);
        for (int i = 0; i < (int)R[j].size(); i++) {
            pref[j][i + 1] = (pref[j][i] + R[j][i] % MOD) % MOD;
        }
    }

    vector<ll> fact(N + 1), ifact(N + 1);
    fact[0] = 1;
    for (int i = 1; i <= N; i++) fact[i] = fact[i - 1] * i % MOD;
    ifact[N] = mod_pow(fact[N], MOD - 2);
    for (int i = N; i >= 1; i--) ifact[i - 1] = ifact[i] * i % MOD;

    auto C = [&](int n, int k) {
        return fact[n] * ifact[k] % MOD * ifact[n - k] % MOD;
    };

    vector<ll> coef(N);
    for (int k = 0; k < N; k++) {
        coef[k] = mod_pow((N - k) * C(N, k) % MOD, MOD - 2);
    }

    ll ans = 0;
    ll totalMod = total % MOD;

    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            int k = i + j;
            if (k >= N) continue;

            for (ll x : L[i]) {
                int cnt = lower_bound(R[j].begin(), R[j].end(), X - x) - R[j].begin();
                if (cnt == 0) continue;

                ll cntMod = cnt % MOD;
                ll sumS = ((x % MOD) * cntMod + pref[j][cnt]) % MOD;
                ll term = (totalMod * cntMod % MOD - sumS + MOD) % MOD;
                ans = (ans + term * coef[k]) % MOD;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
```

## 样例验证

代码枚举两半子集和，并按 `sum(S)<X` 累加期望公式。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
