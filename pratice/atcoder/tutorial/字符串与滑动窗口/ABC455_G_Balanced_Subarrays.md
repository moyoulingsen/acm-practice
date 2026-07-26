# ABC455 G - Balanced Subarrays

## 网址

https://atcoder.jp/contests/abc455/tasks/abc455_g

## 题解

本题统计 balanced 子数组。一个子数组 balanced 当且仅当其中每种出现过的整数出现次数都相同。

每个查询 `B_k` 要输出：

1. 每个出现的整数都恰好出现 `B_k` 次的 balanced 子数组数量；
2. 恰好出现 `B_k` 种不同整数的 balanced 子数组数量。

官方做法使用随机哈希，误判概率极低。

### 第一类：每个数出现恰好 `p` 次

滑动窗口维护右端 `r` 时的最小左端 `L`，使窗口内任意数出现次数不超过 `p`。

给每个值按出现顺序循环分配 `p` 个哈希值，且这 `p` 个哈希值之和为 `0`。在窗口内出现次数不超过 `p` 的前提下，子数组哈希和为 `0` 等价于每个值出现 `0` 或 `p` 次。

用前缀哈希和 + 频率表统计。

### 第二类：恰好出现 `q` 种数

用两个滑动窗口维护“至多 `q` 种”和“至多 `q-1` 种”，得到当前右端对应的合法左端区间。

给每种值一个随机哈希 `h[x]`。若当前集合哈希为 `H`，前缀哈希为 `S_i`，则 balanced 条件可写成：

```text
q * S_r - H * r = q * S_l - H * l
```

维护合法左端区间内该值的频率即可。

时间复杂度：`O(KN)`，其中 `K <= 10`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int MOD1 = 1000000007;
const int MOD2 = 1000000009;

struct H {
    int x, y;
    bool operator==(const H &o) const { return x == o.x && y == o.y; }
    bool operator!=(const H &o) const { return !(*this == o); }
};

struct HHasher {
    static ull splitmix64(ull x) {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }

    size_t operator()(const H &h) const {
        ull v = (ull(h.x) << 32) ^ ull(h.y);
        return splitmix64(v);
    }
};

H add_h(H a, H b) {
    int x = a.x + b.x;
    if (x >= MOD1) x -= MOD1;
    int y = a.y + b.y;
    if (y >= MOD2) y -= MOD2;
    return {x, y};
}

H sub_h(H a, H b) {
    int x = a.x - b.x;
    if (x < 0) x += MOD1;
    int y = a.y - b.y;
    if (y < 0) y += MOD2;
    return {x, y};
}

H mul_h(H a, ll k) {
    return {int(1LL * a.x * (k % MOD1) % MOD1), int(1LL * a.y * (k % MOD2) % MOD2)};
}

ull rng_state = 1234567891234567ULL;

ull next_rand() {
    rng_state += 0x9e3779b97f4a7c15ULL;
    ull z = rng_state;
    z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9ULL;
    z = (z ^ (z >> 27)) * 0x94d049bb133111ebULL;
    return z ^ (z >> 31);
}

H random_h() {
    return {int(next_rand() % (MOD1 - 1) + 1), int(next_rand() % (MOD2 - 1) + 1)};
}

ll count_each_p(int N, const vector<int> &A, const vector<vector<int>> &pos, int p) {
    vector<H> val(N, {0, 0});

    for (int v = 1; v <= N; v++) {
        int g = (int)pos[v].size();
        if (g == 0) continue;

        if (p == 1) {
            for (int idx : pos[v]) val[idx] = {0, 0};
        } else if (g >= p) {
            vector<H> cyc(p);
            H sum{0, 0};

            for (int i = 0; i < p - 1; i++) {
                cyc[i] = random_h();
                sum = add_h(sum, cyc[i]);
            }

            cyc[p - 1] = sub_h({0, 0}, sum);

            for (int i = 0; i < g; i++) val[pos[v][i]] = cyc[i % p];
        } else {
            for (int idx : pos[v]) val[idx] = random_h();
        }
    }

    vector<H> pref(N + 1, {0, 0});
    for (int i = 0; i < N; i++) pref[i + 1] = add_h(pref[i], val[i]);

    unordered_map<H, ll, HHasher> freq;
    freq.reserve(2 * N + 10);

    vector<int> cnt(N + 1);
    int left = 0;
    ll ans = 0;

    freq[pref[0]] = 1;

    auto erase_one = [&](H key) {
        auto it = freq.find(key);
        if (--it->second == 0) freq.erase(it);
    };

    for (int r = 0; r < N; r++) {
        int v = A[r];
        cnt[v]++;

        while (cnt[v] > p) {
            erase_one(pref[left]);
            cnt[A[left]]--;
            left++;
        }

        auto it = freq.find(pref[r + 1]);
        if (it != freq.end()) ans += it->second;

        freq[pref[r + 1]]++;
    }

    return ans;
}

ll count_kinds_q(int N, const vector<int> &A, const vector<H> &value_hash, int q) {
    vector<H> pref(N + 1, {0, 0});
    for (int i = 0; i < N; i++) pref[i + 1] = add_h(pref[i], value_hash[A[i]]);

    vector<int> cnt_q(N + 1), cnt_qm(N + 1);
    int left_q = 0, left_qm = 0;
    int distinct_q = 0, distinct_qm = 0;
    H set_hash{0, 0};

    unordered_map<H, ll, HHasher> freq;
    freq.reserve(2 * N + 10);

    bool active = false;
    H current_hash{0, 0};
    int cur_l = 0, cur_u = 0;
    ll ans = 0;

    auto key_of = [&](int i, H h) -> H {
        return sub_h(mul_h(pref[i], q), mul_h(h, i));
    };

    auto erase_one = [&](H key) {
        auto it = freq.find(key);
        if (--it->second == 0) freq.erase(it);
    };

    for (int R = 1; R <= N; R++) {
        int v = A[R - 1];

        if (cnt_q[v]++ == 0) {
            distinct_q++;
            set_hash = add_h(set_hash, value_hash[v]);
        }

        while (distinct_q > q) {
            int u = A[left_q++];
            if (--cnt_q[u] == 0) {
                distinct_q--;
                set_hash = sub_h(set_hash, value_hash[u]);
            }
        }

        if (cnt_qm[v]++ == 0) distinct_qm++;
        while (distinct_qm > q - 1) {
            int u = A[left_qm++];
            if (--cnt_qm[u] == 0) distinct_qm--;
        }

        int low = left_q;
        int high = left_qm;

        if (distinct_q < q || low >= high) {
            active = false;
            freq.clear();
            continue;
        }

        H h = set_hash;

        if (!active || h != current_hash || low > cur_u) {
            freq.clear();
            active = true;
            current_hash = h;
            cur_l = low;
            cur_u = low;
        }

        while (cur_l < low) {
            erase_one(key_of(cur_l, current_hash));
            cur_l++;
        }

        if (cur_u < low) {
            freq.clear();
            cur_l = cur_u = low;
        }

        while (cur_u < high) {
            freq[key_of(cur_u, current_hash)]++;
            cur_u++;
        }

        H target = key_of(R, current_hash);
        auto it = freq.find(target);
        if (it != freq.end()) ans += it->second;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N);
        vector<vector<int>> pos(N + 1);

        for (int i = 0; i < N; i++) {
            cin >> A[i];
            pos[A[i]].push_back(i);
        }

        vector<int> B(K);
        for (int i = 0; i < K; i++) cin >> B[i];

        vector<H> value_hash(N + 1);
        for (int v = 1; v <= N; v++) value_hash[v] = random_h();

        for (int b : B) {
            ll c1 = count_each_p(N, A, pos, b);
            ll c2 = count_kinds_q(N, A, value_hash, b);
            cout << c1 << ' ' << c2 << '\n';
        }
    }

    return 0;
}
```

## 样例验证

```text
输入
3
4 2
1 2 1 2
2 1
1 1
1
1
7 7
1 5 5 1 5 1 2
1 2 3 4 5 6 7

输出
1 4
7 4
1 1
13 8
3 8
1 1
0 0
0 0
0 0
0 0
```

说明：本题代码使用随机哈希，是 Monte Carlo 解法，误判概率极低。
