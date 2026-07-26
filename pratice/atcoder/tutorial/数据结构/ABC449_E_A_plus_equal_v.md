# ABC449 E - A += v

## 网址

https://atcoder.jp/contests/abc449/tasks/abc449_e

## 题解

先统计每个值 `v` 的出现次数 `cnt[v]`，然后按 `(cnt[v], v)` 排序，得到值的顺序 `P`。

操作过程可以按“层”批量看：先把出现次数最少的一批数补到下一层；当考虑前 `k` 个数时，追加顺序会反复出现 `P_1...P_k` 按数值排序后的序列。

预处理 `len[k]` 表示处理完前 `k` 层后数组长度。查询 `X`：

- 如果 `X <= N`，直接输出原数组；
- 否则二分找到 `X` 属于哪一层；
- 再求前 `k` 个值里第 `t` 小的数。

最后一步把查询按 `k` 升序离线，用 Fenwick Tree 维护已经加入的值，并查第 `t` 小。

时间复杂度：`O((M+Q) log M)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Fenwick {
    int n;
    vector<int> bit;

    Fenwick(int n) : n(n), bit(n + 1) {}

    void add(int idx, int val) {
        for (idx++; idx <= n; idx += idx & -idx) bit[idx] += val;
    }

    int kth(int k) const {
        int idx = 0;
        int step = 1;
        while ((step << 1) <= n) step <<= 1;

        for (; step > 0; step >>= 1) {
            int nxt = idx + step;
            if (nxt <= n && bit[nxt] < k) {
                idx = nxt;
                k -= bit[nxt];
            }
        }

        return idx;
    }
};

struct Query {
    int k;
    ll pos;
    int id;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    vector<ll> cnt(M);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        --A[i];
        cnt[A[i]]++;
    }

    vector<pair<ll, int>> ord;
    for (int v = 0; v < M; v++) ord.push_back({cnt[v], v});
    sort(ord.begin(), ord.end());

    const ll INF = (ll)4e18;
    vector<ll> len(M + 1);
    len[0] = N;

    for (int i = 0; i + 1 < M; i++) {
        ll diff = ord[i + 1].first - ord[i].first;
        len[i + 1] = min(INF, len[i] + 1LL * (i + 1) * diff);
    }
    len[M] = INF;

    int Q;
    cin >> Q;

    vector<int> ans(Q, -1);
    vector<Query> queries;

    for (int qi = 0; qi < Q; qi++) {
        ll X;
        cin >> X;

        if (X <= N) {
            ans[qi] = A[X - 1] + 1;
            continue;
        }

        int ng = 0;
        int ok = M;
        while (ok - ng > 1) {
            int mid = (ng + ok) / 2;
            if (len[mid] >= X) ok = mid;
            else ng = mid;
        }

        ll offset = X - len[ng] - 1;
        offset %= ok;
        queries.push_back({ok, offset, qi});
    }

    sort(queries.begin(), queries.end(), [](const Query &a, const Query &b) {
        return a.k < b.k;
    });

    Fenwick fw(M);
    int ptr = 0;

    for (auto q : queries) {
        while (ptr < q.k) {
            fw.add(ord[ptr].second, 1);
            ptr++;
        }
        ans[q.id] = fw.kth((int)q.pos + 1) + 1;
    }

    for (int x : ans) cout << x << '\n';
    return 0;
}
```

## 样例验证

代码为离线 Fenwick 第 k 小查询实现。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
