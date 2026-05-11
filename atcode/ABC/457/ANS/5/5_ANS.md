**题解翻译（E - Crossing Table Cloth）**

我们将 \(S_q\) 和 \(T_q\) 简写为 \(S\) 和 \(T\)。

因为两块布必须恰好覆盖区间 \([S, T]\)，所以至少需要一块左端点为 \(S\) 的布，以及一块右端点为 \(T\) 的布。

**[1] 如果存在一块恰好覆盖 \([S, T]\) 的布**
可以回答 Yes 的情况总是属于以下三种之一：
- 存在两块或更多恰好覆盖 \([S, T]\) 的布。
- 存在一块布完全包含于 \([S+1, T]\) 中。
- 存在一块布完全包含于 \([S, T-1]\) 中。

第一种情况可以通过在哈希表中统计每块布的出现次数来判断。
第二种情况可以预处理一个数组，记录“左端点大于等于 \(i\) 的布中的最小右端点”。第三种情况同理。

**[2] 如果不存在恰好覆盖 \([S, T]\) 的布**
所选的两块布中，必须有一块左端点为 \(S\)，另一块右端点为 \(T\)。
对于左端点为 \(S\) 的那块布，我们总是可以贪心地选择其中**右端点最大且不超过 \(T\)** 的那一块。同样地，对于右端点为 \(T\) 的那块布，我们选择其中**左端点最小且不小于 \(S\)** 的那一块。
这两块布都可以通过二分查找在预处理的数组中找出（为每个左端点/右端点维护一个对应另一端点的有序数组）。
找到这两块布后，检查它们的并集是否恰好覆盖 \([S, T]\) 即可。

适当实现上述算法即可解决本题。时间复杂度为 \(O(N + (M+Q)\log M)\)。

---

**C++ 代码**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> by_l(N + 1), by_r(N + 1);
    map<pair<int,int>, int> cnt;
    const int INF = 1e9;
    vector<int> min_r_at_l(N + 1, INF);

    for (int i = 0; i < M; ++i) {
        int L, R;
        cin >> L >> R;
        by_l[L].push_back(R);
        by_r[R].push_back(L);
        cnt[{L, R}]++;
        if (R < min_r_at_l[L]) {
            min_r_at_l[L] = R;
        }
    }

    for (int i = 1; i <= N; ++i) {
        sort(by_l[i].begin(), by_l[i].end());
        sort(by_r[i].begin(), by_r[i].end());
    }

    // suf_min_r[i] = 左端点 >= i 的布的最小右端点
    vector<int> suf_min_r(N + 3, INF);
    for (int i = N; i >= 1; --i) {
        suf_min_r[i] = min(suf_min_r[i + 1], min_r_at_l[i]);
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int S, T;
        cin >> S >> T;
        bool ok = false;

        if (cnt[{S, T}] > 0) {
            // 情况1：存在恰好 [S, T] 的布
            ok |= (cnt[{S, T}] >= 2);
            ok |= (suf_min_r[S + 1] <= T);
            ok |= (suf_min_r[S] <= T - 1);
            cout << (ok ? "Yes" : "No") << '\n';
            continue;
        }

        // 情况2：不存在恰好覆盖的布
        const auto &rs = by_l[S];
        const auto &ls = by_r[T];

        // 右端点 <= T 的最大值
        auto it_r = upper_bound(rs.begin(), rs.end(), T);
        int pos_r = (it_r == rs.begin()) ? -1 : (it_r - rs.begin() - 1);

        // 左端点 >= S 的最小值
        auto it_l = lower_bound(ls.begin(), ls.end(), S);
        int pos_l = it_l - ls.begin();

        if (pos_r >= 0 && pos_l < (int)ls.size()) {
            int r1 = rs[pos_r];
            int l2 = ls[pos_l];
            if (l2 <= r1 + 1) {
                ok = true;
            }
        }

        cout << (ok ? "Yes" : "No") << '\n';
    }

    return 0;
}
```