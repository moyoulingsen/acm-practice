# ABC463 D - Maximize the Gap

## 网址

https://atcoder.jp/contests/abc463/tasks/abc463_d

## 题解

要选出 `K` 个互不重叠的闭区间，并最大化相邻已选区间之间的最小距离。如果两个闭区间端点相接，例如 `[1,5]` 和 `[5,9]`，它们仍然重叠，所以合法的最小间隔至少要满足下一个区间左端点 `L >= lastR + gap`。

固定一个候选答案 `gap`，问题变成：能否选出至少 `K` 个区间，使得每个新选区间和上一个已选区间距离至少为 `gap`。

这个判定可以按右端点从小到大贪心：每次选择第一个满足 `L >= lastR + gap` 的区间。右端点越小，留给后面的空间越大，因此这种贪心最优。

判定具有单调性：如果 `gap` 可行，那么更小的间隔也可行。因此二分最大可行 `gap`。

时间复杂度：`O(N log N + N log 10^9)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<pair<ll, ll>> seg(N);
    for (auto &[L, R] : seg) cin >> L >> R;

    sort(seg.begin(), seg.end(), [](const auto &a, const auto &b) {
        if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    });

    auto can = [&](ll gap) {
        int cnt = 0;
        ll lastR = -(1LL << 60);

        for (auto [L, R] : seg) {
            if (L >= lastR + gap) {
                cnt++;
                lastR = R;
                if (cnt >= K) return true;
            }
        }
        return false;
    };

    if (!can(1)) {
        cout << -1 << '\n';
        return 0;
    }

    ll ok = 1, ng = 1000000001LL;
    while (ng - ok > 1) {
        ll mid = (ok + ng) / 2;
        if (can(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << '\n';
    return 0;
}
```

## 样例验证

代码使用闭区间不相交条件 `L >= lastR + gap`，并在 `gap=1` 不可行时输出 `-1`。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
