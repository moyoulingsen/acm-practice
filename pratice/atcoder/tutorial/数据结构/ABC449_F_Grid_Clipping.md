# ABC449 F - Grid Clipping

## 网址

https://atcoder.jp/contests/abc449/tasks/abc449_f

## 题解

总共有 `(H-h+1)*(W-w+1)` 个 `h x w` 子矩形。

反过来统计包含至少一个黑格的子矩形。一个黑格 `(R,C)` 会影响的子矩形左上角 `(r,c)` 满足：

```text
R-h+1 <= r <= R
C-w+1 <= c <= C
```

再和合法左上角范围取交集。于是每个黑格对应左上角平面上的一个矩形，问题变成求这些矩形并集的格点数。

用扫描线 + 坐标压缩 + 线段树维护当前被覆盖的列长度。

时间复杂度：`O(N log N)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Event {
    ll x, y1, y2;
    int delta;

    bool operator<(const Event &other) const {
        return x < other.x;
    }
};

struct SegTree {
    int n;
    vector<int> cover;
    vector<ll> len;
    vector<ll> ys;

    SegTree(vector<ll> coords) : ys(coords) {
        n = ys.size() - 1;
        cover.assign(4 * max(1, n), 0);
        len.assign(4 * max(1, n), 0);
    }

    void pull(int p, int l, int r) {
        if (cover[p] > 0) {
            len[p] = ys[r] - ys[l];
        } else if (r - l == 1) {
            len[p] = 0;
        } else {
            len[p] = len[p * 2] + len[p * 2 + 1];
        }
    }

    void add(int ql, int qr, int val, int p, int l, int r) {
        if (qr <= l || r <= ql) return;
        if (ql <= l && r <= qr) {
            cover[p] += val;
            pull(p, l, r);
            return;
        }

        int m = (l + r) / 2;
        add(ql, qr, val, p * 2, l, m);
        add(ql, qr, val, p * 2 + 1, m, r);
        pull(p, l, r);
    }

    void add(ll y1, ll y2, int val) {
        int l = lower_bound(ys.begin(), ys.end(), y1) - ys.begin();
        int r = lower_bound(ys.begin(), ys.end(), y2) - ys.begin();
        if (l < r) add(l, r, val, 1, 0, n);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll H, W, h, w;
    int N;
    cin >> H >> W >> h >> w >> N;

    ll maxR = H - h + 1;
    ll maxC = W - w + 1;
    ll total = maxR * maxC;

    vector<Event> events;
    vector<ll> ys;

    for (int i = 0; i < N; i++) {
        ll R, C;
        cin >> R >> C;

        ll r1 = max(1LL, R - h + 1);
        ll r2 = min(R, maxR);
        ll c1 = max(1LL, C - w + 1);
        ll c2 = min(C, maxC);

        if (r1 <= r2 && c1 <= c2) {
            events.push_back({r1, c1, c2 + 1, 1});
            events.push_back({r2 + 1, c1, c2 + 1, -1});
            ys.push_back(c1);
            ys.push_back(c2 + 1);
        }
    }

    if (events.empty()) {
        cout << total << '\n';
        return 0;
    }

    sort(events.begin(), events.end());
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    SegTree seg(ys);
    ll covered = 0;
    ll prevX = events[0].x;

    for (int i = 0; i < (int)events.size();) {
        ll x = events[i].x;
        covered += seg.len[1] * (x - prevX);

        while (i < (int)events.size() && events[i].x == x) {
            seg.add(events[i].y1, events[i].y2, events[i].delta);
            i++;
        }

        prevX = x;
    }

    cout << total - covered << '\n';
    return 0;
}
```

## 样例验证

代码按黑格影响的左上角矩形做并集面积统计。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
