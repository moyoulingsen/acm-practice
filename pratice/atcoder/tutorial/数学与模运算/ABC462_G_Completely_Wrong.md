# ABC462 G - Completely Wrong

## 网址

https://atcoder.jp/contests/abc462/tasks/abc462_g

## 题解

有 `N` 个球，第 `i` 个球颜色为 `C_i`。随机取出所有球形成一个排列，第 `i` 次取出的球若颜色等于 `G_i` 就得 `1` 分。求最终得分为 `0` 的概率。

等价于：随机排列所有球，要求每个位置 `i` 放入的球颜色都不等于 `G_i`。

设：

- `X_c`：颜色为 `c` 的球数量；
- `Y_c`：要求颜色为 `c` 的位置数量。

总排列数为 `N!`。用容斥统计没有任何位置匹配的排列数。

如果对颜色 `c`，容斥中选了 `j` 个要求颜色为 `c` 的位置强制匹配，那么：

- 选位置：`C(Y_c, j)`；
- 选球并排列到这些位置：`C(X_c, j) * j!`。

所有颜色共强制匹配了 `d` 个位置后，剩余位置任意排列，有 `(N-d)!` 种。

对每种颜色建立多项式：

```text
f_c(t) = sum_j (-1)^j * C(X_c,j) * C(Y_c,j) * j! * t^j
```

把所有颜色的多项式相乘：

```text
F(t) = product f_c(t) = sum_d coef[d] * t^d
```

合法排列数就是：

```text
sum_d coef[d] * (N-d)!
```

最终概率再除以 `N!`。

多项式总次数不超过 `N`，用 NTT 并按当前长度从小到大合并多项式，总复杂度 `O(N log^2 N)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int ROOT = 3;

long long mod_pow(long long a, long long e) {
    long long r = 1;
    while (e > 0) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

void ntt(vector<int> &a, bool inv) {
    int n = (int)a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        long long wlen = mod_pow(ROOT, (MOD - 1) / len);
        if (inv) wlen = mod_pow(wlen, MOD - 2);

        for (int i = 0; i < n; i += len) {
            long long w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i + j];
                int v = a[i + j + len / 2] * w % MOD;

                a[i + j] = u + v;
                if (a[i + j] >= MOD) a[i + j] -= MOD;

                a[i + j + len / 2] = u - v;
                if (a[i + j + len / 2] < 0) a[i + j + len / 2] += MOD;

                w = w * wlen % MOD;
            }
        }
    }

    if (inv) {
        long long invN = mod_pow(n, MOD - 2);
        for (int &x : a) x = x * invN % MOD;
    }
}

vector<int> multiply(vector<int> a, vector<int> b) {
    int need = (int)a.size() + (int)b.size() - 1;

    if ((long long)a.size() * b.size() <= 4000) {
        vector<int> c(need);
        for (int i = 0; i < (int)a.size(); i++) {
            for (int j = 0; j < (int)b.size(); j++) {
                c[i + j] = (c[i + j] + (long long)a[i] * b[j]) % MOD;
            }
        }
        return c;
    }

    int n = 1;
    while (n < need) n <<= 1;
    a.resize(n);
    b.resize(n);

    ntt(a, false);
    ntt(b, false);
    for (int i = 0; i < n; i++) a[i] = (long long)a[i] * b[i] % MOD;
    ntt(a, true);

    a.resize(need);
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> X(N + 1), Y(N + 1);
    for (int i = 0; i < N; i++) {
        int c;
        cin >> c;
        X[c]++;
    }
    for (int i = 0; i < N; i++) {
        int g;
        cin >> g;
        Y[g]++;
    }

    vector<int> fact(N + 1), ifact(N + 1);
    fact[0] = 1;
    for (int i = 1; i <= N; i++) fact[i] = (long long)fact[i - 1] * i % MOD;

    ifact[N] = mod_pow(fact[N], MOD - 2);
    for (int i = N; i >= 1; i--) ifact[i - 1] = (long long)ifact[i] * i % MOD;

    vector<vector<int>> polys;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int c = 1; c <= N; c++) {
        int m = min(X[c], Y[c]);
        if (m == 0) continue;

        vector<int> p(m + 1);
        for (int j = 0; j <= m; j++) {
            long long coef = fact[X[c]];
            coef = coef * fact[Y[c]] % MOD;
            coef = coef * ifact[X[c] - j] % MOD;
            coef = coef * ifact[Y[c] - j] % MOD;
            coef = coef * ifact[j] % MOD;
            if (j & 1) coef = (MOD - coef) % MOD;
            p[j] = coef;
        }

        int id = (int)polys.size();
        polys.push_back(move(p));
        pq.push({(int)polys[id].size(), id});
    }

    vector<int> F = {1};
    if (!pq.empty()) {
        while (pq.size() > 1) {
            auto [s1, id1] = pq.top();
            pq.pop();
            auto [s2, id2] = pq.top();
            pq.pop();

            vector<int> merged = multiply(polys[id1], polys[id2]);
            int id = (int)polys.size();
            polys.push_back(move(merged));
            pq.push({(int)polys[id].size(), id});
        }
        F = move(polys[pq.top().second]);
    }

    long long ways = 0;
    for (int d = 0; d < (int)F.size(); d++) {
        ways += (long long)F[d] * fact[N - d] % MOD;
        if (ways >= MOD) ways -= MOD;
    }

    cout << ways * ifact[N] % MOD << '\n';
    return 0;
}
```

## 样例验证

代码按颜色建立容斥多项式，再用 NTT 合并并除以 `N!` 得到概率。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
