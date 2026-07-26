# ABC463 F - Senshuraku

## 网址

https://atcoder.jp/contests/abc463/tasks/abc463_f

## 题解

有 `2N` 名选手，第 `i` 场比赛在选手 `2i-1` 和 `2i` 之间进行。每场比赛两人各以 `1/2` 概率获胜。赛前第 `i` 名选手已有 `A_i` 胜，赛后从最终胜场数最多的选手中等概率选冠军，要求每个选手成为冠军的概率。

令：

```text
W = max A_i
```

每个选手最多再赢一场，所以最终冠军胜场只可能是 `W` 或 `W+1`。当前胜场 `<= W-2` 的选手，即使赢一场也到不了 `W`，不可能主动成为冠军候选。

把每场比赛按双方当前胜场类型分成六类：

| 类别 | 双方类型 |
|------|----------|
| `0` | `(W, W)` |
| `1` | `(W, W-1)` |
| `2` | `(W, low)` |
| `3` | `(W-1, W-1)` |
| `4` | `(W-1, low)` |
| `5` | `(low, low)` |

### 冠军胜场为 `W+1`

只有当前为 `W` 的选手赢下最后一场，才会成为 `W+1` 候选。

- `0` 类：必然产生 `1` 个 `W+1` 候选，两个选手各有 `1/2` 概率成为这个候选；
- `1,2` 类：其中的 `W` 选手以 `1/2` 概率成为候选；
- 其他类不产生 `W+1` 候选。

设固定候选数为 `cnt[0]`，可选候选比赛数为 `cnt[1]+cnt[2]`，枚举最终候选总数 `k`，贡献乘上 `1/k`。

### 冠军胜场为 `W`

如果存在 `0` 类比赛，则一定有人达到 `W+1`，这种情况不可能。

否则：

- `1` 类必须让 `W` 选手输，此时双方都成为 `W` 候选；
- `2` 类必须让 `W` 选手输，此时原 `W` 选手仍是 `W` 候选；
- `3` 类必然产生一个 `W` 候选；
- `4` 类中 `W-1` 选手以 `1/2` 概率成为候选。

同样枚举候选总数，并乘上 `1/k`。

由于同一类型中的选手贡献相同，先算出每个类型里“当前胜场较大者”和“当前胜场较小者”的贡献，再按原顺序输出。

时间复杂度：`O(N)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 998244353;
const ll INV2 = (MOD + 1) / 2;

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

    vector<pair<int, int>> match(N);
    int W = 0;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        match[i] = {a, b};
        W = max(W, max(a, b));
    }

    int M = 2 * N;
    vector<ll> fact(M + 1), ifact(M + 1), inv(M + 1);
    fact[0] = 1;
    for (int i = 1; i <= M; i++) fact[i] = fact[i - 1] * i % MOD;

    ifact[M] = mod_pow(fact[M], MOD - 2);
    for (int i = M; i >= 1; i--) ifact[i - 1] = ifact[i] * i % MOD;
    for (int i = 1; i <= M; i++) inv[i] = fact[i - 1] * ifact[i] % MOD;

    auto C = [&](int n, int r) -> ll {
        if (n < 0 || r < 0 || r > n) return 0;
        return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
    };

    auto type = [&](int a, int b) {
        if (a > b) swap(a, b);
        if (b == W) {
            if (a == W) return 0;
            if (a + 1 == W) return 1;
            return 2;
        }
        if (b + 1 == W) {
            if (a + 1 == W) return 3;
            return 4;
        }
        return 5;
    };

    array<int, 6> cnt{};
    vector<int> tp(N);
    for (int i = 0; i < N; i++) {
        tp[i] = type(match[i].first, match[i].second);
        cnt[tp[i]]++;
    }

    array<array<ll, 2>, 6> prob{};
    auto add = [&](ll &x, ll y) {
        x += y;
        if (x >= MOD) x -= MOD;
    };

    {
        int base = cnt[0];
        int optional = cnt[1] + cnt[2];
        ll coef = mod_pow(INV2, optional);

        if (base > 0) {
            for (int k = base; k <= base + optional; k++) {
                ll p = C(optional, k - base) * coef % MOD * inv[k] % MOD;
                add(prob[0][0], p * INV2 % MOD);
                add(prob[0][1], p * INV2 % MOD);
            }
        }

        for (int k = base + 1; k <= base + optional; k++) {
            ll p = C(optional - 1, k - base - 1) * coef % MOD * inv[k] % MOD;
            add(prob[1][0], p);
            add(prob[2][0], p);
        }
    }

    if (cnt[0] == 0) {
        int base = 2 * cnt[1] + cnt[2] + cnt[3];
        int optional = cnt[4];
        ll coef = mod_pow(INV2, cnt[1] + cnt[2] + cnt[4]);

        if (base > 0) {
            for (int k = base; k <= base + optional; k++) {
                ll p = C(optional, k - base) * coef % MOD * inv[k] % MOD;
                add(prob[1][0], p);
                add(prob[1][1], p);
                add(prob[2][0], p);
                add(prob[3][0], p * INV2 % MOD);
                add(prob[3][1], p * INV2 % MOD);
            }
        }

        for (int k = base + 1; k <= base + optional; k++) {
            ll p = C(optional - 1, k - base - 1) * coef % MOD * inv[k] % MOD;
            add(prob[4][0], p);
        }
    }

    for (int i = 0; i < N; i++) {
        auto [a, b] = match[i];
        int t = tp[i];
        ll larger = prob[t][0];
        ll smaller = prob[t][1];

        if (a < b) cout << smaller << ' ' << larger;
        else cout << larger << ' ' << smaller;

        if (i + 1 < N) cout << ' ';
    }
    cout << '\n';
    return 0;
}
```

## 样例验证

代码按官方分类讨论 `W+1` 与 `W` 两种冠军胜场，并用组合数枚举候选人数。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
