# ABC464 G - Celester 2

## 网址

https://atcoder.jp/contests/abc464/tasks/abc464_g

## 题解

对每个 `k=0..N`，求最多翻转 `k` 个字符后，字符串中相邻子串 `RS` 的最大数量。

先加哨兵：

```text
t = 'S' + S + 'R'
```

当前 `RS` 数量等于 `t` 中相邻字符不同的位置数量的一半。若某个相邻位置两边相同，称为坏边。一次翻转原串中的一个字符，会同时翻转相邻两条边的“是否不同”状态。

因此想让答案增加 `1`，本质上要把两条坏边配对并消掉；若坏边位置为 `i<j`，代价为 `j-i` 次翻转。问题变成：在一条线上不断选择相邻坏边间隔进行配对，求每增加一次答案的最小累计代价。

官方贪心：维护坏边之间的间隔，用小根堆每次取当前最小间隔。取走某个间隔后，它左右相邻间隔会被合并，新间隔为：

```text
left + right - chosen
```

用双向链表维护仍存在的间隔，用优先队列维护最小值。得到“恰好增加若干次”的最小代价后，对预算 `k` 做前缀最大即可。

时间复杂度：`O(N log N)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        string S;
        cin >> N >> S;

        string t = "S" + S + "R";

        vector<int> bad;
        int diff = 0;
        for (int i = 0; i <= N; i++) {
            if (t[i] == t[i + 1]) bad.push_back(i);
            else diff++;
        }

        int cur = diff / 2;
        int target = N / 2;

        vector<int> ans(N + 1, 0);
        ans[0] = cur;

        const ll INF = (ll)4e18;
        vector<ll> d;
        d.push_back(INF);
        d.push_back(INF);
        for (int i = 1; i < (int)bad.size(); i++) {
            d.push_back(bad[i] - bad[i - 1]);
        }
        d.push_back(INF);
        d.push_back(INF);

        int M = (int)d.size();
        vector<int> L(M), R(M);
        vector<char> alive(M, true);
        for (int i = 0; i < M; i++) {
            L[i] = i - 1;
            R[i] = i + 1;
        }

        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        for (int i = 0; i < M; i++) pq.push({d[i], i});

        ll cost = 0;
        while (cur < target) {
            auto [x, id] = pq.top();
            pq.pop();

            if (!alive[id] || d[id] != x) continue;

            cost += x;
            cur++;
            if (cost <= N) ans[cost] = cur;

            int l = L[id];
            int r = R[id];

            d[id] = d[l] + d[r] - d[id];
            pq.push({d[id], id});

            alive[l] = false;
            R[L[l]] = R[l];
            L[R[l]] = L[l];

            alive[r] = false;
            R[L[r]] = R[r];
            L[R[r]] = L[r];
        }

        for (int k = 1; k <= N; k++) ans[k] = max(ans[k], ans[k - 1]);

        for (int k = 0; k <= N; k++) {
            if (k) cout << ' ';
            cout << ans[k];
        }
        cout << '\n';
    }

    return 0;
}
```

## 样例验证

代码将翻转字符转化为配对坏边，并用优先队列贪心生成每次增加答案的最小代价。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
