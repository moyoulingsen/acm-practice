# ABC458 G - Children Yearn for the Evil Kindergarten

## 网址

https://atcoder.jp/contests/abc458/tasks/abc458_g

## 题解

若能让 `m` 个孩子逃出，也一定能让更少孩子逃出，因此答案可以二分。

固定 `m` 后，只关心这 `m` 个目标孩子，其他孩子可以放弃。设：

```text
dp[x] = 某天结束时，仍有 x 个目标孩子留在场内时，这些孩子总共最多还能持有多少奖牌
```

初始 `dp[m]=0`。

第 `i` 天：

1. 生存扣费：整体转移为 `dp[x] += A_i - B_i*x`，若变成负数则不可达；
2. 逃出若干人：从 `x+1` 个留下变成 `x` 个留下，逃出的孩子需要至少 `C_i` 枚奖牌，即 `dp[x] = max(dp[x], dp[x+1]-C_i)`。

朴素 DP 太慢。官方题解证明 `dp[x]` 始终是连续定义域上的离散凹函数，可以用类似 Slope Trick 的分段线性函数维护，每天 `O(1)` 摊还处理，二分答案后总复杂度为 `O(N log A_1)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using Point = pair<ll, ll>;

int N;
vector<ll> A, B, C;

bool can_escape(ll m) {
    if (m <= 0) return true;

    ll add_a = 0;
    ll add_b = 0;

    deque<Point> pts;
    pts.push_back({m, 0});

    auto eval = [&](const Point &p) -> ll {
        return p.second + add_a * p.first + add_b;
    };

    auto raw_slope = [&](const Point &l, const Point &r) -> ll {
        ll dy = r.second - l.second;
        ll dx = r.first - l.first;
        return dy / dx;
    };

    for (int day = 0; day < N; day++) {
        add_b += A[day];
        add_a -= B[day];

        while (!pts.empty()) {
            Point p1 = pts.back();
            ll y1 = eval(p1);
            if (y1 >= 0) break;

            pts.pop_back();
            if (pts.empty()) break;

            Point p2 = pts.back();
            ll y2 = eval(p2);
            if (y2 < 0) continue;

            ll s = raw_slope(p2, p1);
            ll denom = -(add_a + s);
            ll dx = y2 / denom;

            if (dx > 0) pts.push_back({p2.first + dx, p2.second + s * dx});
            break;
        }

        while (!pts.empty()) {
            Point p1 = pts.front();
            ll y1 = eval(p1);
            if (y1 >= 0) break;

            pts.pop_front();
            if (pts.empty()) break;

            Point p2 = pts.front();
            ll y2 = eval(p2);
            if (y2 < 0) continue;

            ll s = raw_slope(p1, p2);
            ll denom = add_a + s;
            ll dx = y2 / denom;

            if (dx > 0) pts.push_front({p2.first - dx, p2.second - s * dx});
            break;
        }

        if (pts.empty()) return false;

        while (pts.size() >= 2) {
            ll actual_slope = add_a + raw_slope(pts[0], pts[1]);
            if (actual_slope >= C[day]) pts.pop_front();
            else break;
        }

        ll y = eval(pts.front());
        ll dx = y / C[day];

        if (dx >= pts.front().first) return true;

        if (dx > 0) {
            ll new_x = pts.front().first - dx;
            ll new_y = pts.front().second - (C[day] - add_a) * dx;
            pts.push_front({new_x, new_y});
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        cin >> N;

        A.resize(N);
        B.resize(N);
        C.resize(N);

        for (int i = 0; i < N; i++) cin >> A[i] >> B[i] >> C[i];

        ll ok = 0;
        ll ng = A[0] + 1;

        while (ok + 1 < ng) {
            ll mid = (ok + ng) / 2;
            if (can_escape(mid)) ok = mid;
            else ng = mid;
        }

        cout << ok << '\n';
    }

    return 0;
}
```

## 样例验证

```text
输入
2
4
16 2 3
15 2 4
1 3 5
20 5 5
2
41404 1 941738
211877 205711 417821

输出
5
0
```
