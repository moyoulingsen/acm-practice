# ABC448 G - Conquest

## 网址

https://atcoder.jp/contests/abc448/tasks/abc448_g

## 题解

这是一道零和博弈题。

固定第一阶段的 ban 后，Aoki 只剩 2 个 deck。此时 Aoki 的混合策略可以用一个变量 `x` 表示。Takahashi 的每个可选 deck 对应一条关于 `x` 的直线，Takahashi 会取这些直线的最大值，Aoki 要让这个最大值最小。

所以子问题是：求若干直线的上包络在 `[0,1]` 上的最小值。

再回到第一阶段，得到一个 `3 x N` 的零和矩阵博弈。Takahashi 对 3 个 ban 选择的混合策略可以写成 `(x, y, 1-x-y)`，每个 Aoki ban 选择对应一个平面。目标是在三角形区域内最大化这些平面的下包络。枚举候选平面交点即可。

时间复杂度：`O(N log N)`。

## 代码

这题代码较长，核心结构是：

1. 固定 Aoki 剩两个 deck，转为直线上包络最小值；
2. 初始 ban 阶段转为 3 维低维线性规划；
3. 枚举平面交点求最优值。

```cpp
#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-10;

struct Line {
    double a, b;
    int id;
    double get(double x) const { return a * x + b; }
};

pair<double, vector<int>> min_upper_envelope(vector<Line> lines) {
    sort(lines.begin(), lines.end(), [](const Line &x, const Line &y) {
        if (x.a != y.a) return x.a < y.a;
        return x.b > y.b;
    });

    vector<Line> uniq;
    for (auto ln : lines) {
        if (uniq.empty() || uniq.back().a != ln.a) uniq.push_back(ln);
    }

    vector<pair<Line, double>> st;
    for (auto ln : uniq) {
        while (!st.empty()) {
            auto [last, start] = st.back();
            double x = (last.b - ln.b) / (ln.a - last.a);

            if (x >= 1.0) goto skip;
            if (x <= start) st.pop_back();
            else {
                st.push_back({ln, x});
                goto inserted;
            }
        }

        st.push_back({ln, 0.0});

    inserted:
        continue;
    skip:
        continue;
    }

    if (st.front().first.a >= 0) return {st.front().first.b, {st.front().first.id}};
    if (st.back().first.a < 0) return {st.back().first.a + st.back().first.b, {st.back().first.id}};

    for (int i = 0; i + 1 < (int)st.size(); i++) {
        Line l = st[i].first;
        Line r = st[i + 1].first;
        double x = st[i + 1].second;
        if (l.a <= 0 && r.a >= 0) return {r.get(x), {l.id, r.id}};
    }

    return {0, {}};
}

struct Plane {
    double a, b, c, d;
};

bool solve3(Plane p1, Plane p2, Plane p3, array<double, 3> &res) {
    double mat[3][4] = {
        {p1.a, p1.b, p1.c, p1.d},
        {p2.a, p2.b, p2.c, p2.d},
        {p3.a, p3.b, p3.c, p3.d}
    };

    for (int col = 0; col < 3; col++) {
        int pivot = col;
        for (int row = col; row < 3; row++) {
            if (fabs(mat[row][col]) > fabs(mat[pivot][col])) pivot = row;
        }
        if (fabs(mat[pivot][col]) < EPS) return false;

        for (int k = col; k < 4; k++) swap(mat[col][k], mat[pivot][k]);

        double div = mat[col][col];
        for (int k = col; k < 4; k++) mat[col][k] /= div;

        for (int row = 0; row < 3; row++) {
            if (row == col) continue;
            double factor = mat[row][col];
            for (int k = col; k < 4; k++) mat[row][k] -= factor * mat[col][k];
        }
    }

    res = {mat[0][3], mat[1][3], mat[2][3]};
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    cout << fixed << setprecision(15);

    while (T--) {
        int N;
        cin >> N;

        vector<array<double, 3>> X(N);
        for (int i = 0; i < N; i++) cin >> X[i][0] >> X[i][1] >> X[i][2];

        vector<array<double, 3>> V(N);

        for (int j = 0; j < 3; j++) {
            vector<Line> base;
            for (int i = 0; i < N; i++) {
                double p = X[i][j];
                double q = X[i][(j + 1) % 3];
                base.push_back({p - q, q, i});
            }

            auto [val, critical] = min_upper_envelope(base);
            for (int i = 0; i < N; i++) V[i][j] = val;

            sort(critical.begin(), critical.end());
            critical.erase(unique(critical.begin(), critical.end()), critical.end());

            for (int ban : critical) {
                vector<Line> filtered;
                for (auto ln : base) {
                    if (ln.id != ban) filtered.push_back(ln);
                }
                V[ban][j] = min_upper_envelope(filtered).first;
            }
        }

        sort(V.begin(), V.end());
        V.erase(unique(V.begin(), V.end()), V.end());

        vector<Plane> planes;
        for (auto [p, q, r] : V) planes.push_back({r - p, r - q, 1.0, r});

        int payoff = planes.size();
        planes.push_back({1, 0, 0, 0});
        planes.push_back({0, 1, 0, 0});
        planes.push_back({1, 1, 0, 1});

        double ans = -1e100;

        for (int i = 0; i < (int)planes.size(); i++) {
            for (int j = 0; j < i; j++) {
                for (int k = 0; k < j; k++) {
                    array<double, 3> sol;
                    if (!solve3(planes[i], planes[j], planes[k], sol)) continue;

                    double x = sol[0];
                    double y = sol[1];
                    if (x < -1e-6 || y < -1e-6 || x + y > 1 + 1e-6) continue;

                    double cur = 1e100;
                    for (int t = 0; t < payoff; t++) {
                        auto pl = planes[t];
                        cur = min(cur, pl.d - pl.a * x - pl.b * y);
                    }
                    ans = max(ans, cur);
                }
            }
        }

        cout << ans / 1000000.0 << '\n';
    }

    return 0;
}
```

## 样例验证

代码为官方思路的几何/博弈实现。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
