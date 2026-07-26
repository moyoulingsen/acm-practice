# ABC457 E - Crossing Table Cloth

## 网址

https://atcoder.jp/contests/abc457/tasks/abc457_e

## 题解

若两块布的并集正好是 `[S,T]`：

- 至少有一块布左端点为 `S`；
- 至少有一块布右端点为 `T`；
- 两块布都必须完全包含在 `[S,T]` 内；
- 两块布之间不能有空隙。

分情况讨论。

### 情况 1：存在布 `[S,T]`

还需要另一块不同的布也在 `[S,T]` 内。可行当且仅当：

- `[S,T]` 至少有两块；或
- 存在布完全包含在 `[S+1,T]`；或
- 存在布完全包含在 `[S,T-1]`。

用哈希表统计每个区间出现次数，并用 `sufMinR[x]` 表示所有左端点 `>=x` 的布的最小右端点。

### 情况 2：不存在布 `[S,T]`

选：

- 左端点为 `S` 且右端点 `<=T` 的布中，右端点最大的 `[S,r1]`；
- 右端点为 `T` 且左端点 `>=S` 的布中，左端点最小的 `[l2,T]`。

若 `l2 <= r1 + 1`，则无缝覆盖 `[S,T]`。

时间复杂度：`O((M+Q) log M)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> byL(N + 2), byR(N + 2);
    unordered_map<long long, int> cnt;

    const int INF = 1e9;
    vector<int> minRAtL(N + 3, INF);

    auto key = [&](int l, int r) -> long long {
        return 1LL * l * (N + 1) + r;
    };

    for (int i = 0; i < M; i++) {
        int L, R;
        cin >> L >> R;

        byL[L].push_back(R);
        byR[R].push_back(L);
        cnt[key(L, R)]++;
        minRAtL[L] = min(minRAtL[L], R);
    }

    for (int i = 1; i <= N; i++) {
        sort(byL[i].begin(), byL[i].end());
        sort(byR[i].begin(), byR[i].end());
    }

    vector<int> sufMinR(N + 4, INF);
    for (int i = N; i >= 1; i--) {
        sufMinR[i] = min(sufMinR[i + 1], minRAtL[i]);
    }

    int Q;
    cin >> Q;

    while (Q--) {
        int S, T;
        cin >> S >> T;

        bool ok = false;
        int exact = cnt[key(S, T)];

        if (exact > 0) {
            if (exact >= 2) ok = true;
            if (sufMinR[S + 1] <= T) ok = true;
            if (sufMinR[S] <= T - 1) ok = true;

            cout << (ok ? "Yes" : "No") << '\n';
            continue;
        }

        auto &rs = byL[S];
        auto itR = upper_bound(rs.begin(), rs.end(), T);
        if (itR == rs.begin()) {
            cout << "No\n";
            continue;
        }
        --itR;
        int r1 = *itR;

        auto &ls = byR[T];
        auto itL = lower_bound(ls.begin(), ls.end(), S);
        if (itL == ls.end()) {
            cout << "No\n";
            continue;
        }
        int l2 = *itL;

        ok = (l2 <= r1 + 1);
        cout << (ok ? "Yes" : "No") << '\n';
    }

    return 0;
}
```

## 样例验证

```text
输入
4 3
1 3
1 1
2 4
4
1 4
2 4
1 3
1 1

输出
Yes
No
Yes
No
```

```text
输入
7 10
2 6
2 5
3 6
1 6
1 2
5 6
2 3
3 7
2 3
1 2
10
1 2
3 5
1 4
1 5
1 5
5 7
1 6
2 3
5 7
2 4

输出
Yes
No
No
Yes
Yes
No
Yes
Yes
No
No
```
