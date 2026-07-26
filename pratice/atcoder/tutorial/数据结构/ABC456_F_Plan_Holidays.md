# ABC456 F - Plan Holidays

## 网址

https://atcoder.jp/contests/abc456/tasks/abc456_f

## 题解

付费选出的假日之间如果间隔至多 2，就可以通过免费操作填满中间空缺。

问题可转化为：在某个长度为 `K` 的区间内选择一些付费点，使相邻付费点之间不会出现连续两个未选点，并且最终能覆盖整个区间。

官方 DP 可表示为 min-plus 矩阵：

```text
dp0[i] = dp1[i-1]
dp1[i] = min(dp0[i-1], dp1[i-1]) + A_i
```

其中 `dp0/dp1` 表示当前位置不选/选的最小代价。用线段树维护区间转移矩阵，枚举长度为 `K` 的滑动窗口即可。

时间复杂度：`O(N log N)` 每组测试。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = (1LL << 62);

ll add_inf(ll a, ll b) {
    if (a >= INF || b >= INF) return INF;
    if (a > INF - b) return INF;
    return a + b;
}

struct Mat {
    ll a[2][2];
};

Mat identity() {
    return Mat{{{0, INF}, {INF, 0}}};
}

Mat mul(const Mat &A, const Mat &B) {
    Mat C;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C.a[i][j] = INF;
            for (int k = 0; k < 2; k++) {
                C.a[i][j] = min(C.a[i][j], add_inf(A.a[i][k], B.a[k][j]));
            }
        }
    }
    return C;
}

Mat op(const Mat &left, const Mat &right) {
    return mul(right, left);
}

struct SegTree {
    int n;
    vector<Mat> seg;

    SegTree(const vector<ll> &A) {
        int sz = (int)A.size();
        n = 1;
        while (n < sz) n <<= 1;
        seg.assign(2 * n, identity());

        for (int i = 0; i < sz; i++) {
            ll x = A[i];
            seg[n + i] = Mat{{{INF, 0}, {x, x}}};
        }

        for (int i = n - 1; i >= 1; i--) seg[i] = op(seg[2 * i], seg[2 * i + 1]);
    }

    Mat prod(int l, int r) {
        Mat left = identity();
        Mat right = identity();

        l += n;
        r += n;

        while (l < r) {
            if (l & 1) left = op(left, seg[l++]);
            if (r & 1) right = op(seg[--r], right);
            l >>= 1;
            r >>= 1;
        }

        return op(left, right);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<ll> A(N);
        for (int i = 0; i < N; i++) cin >> A[i];

        SegTree seg(A);
        ll ans = INF;

        for (int l = 0; l + K <= N; l++) {
            Mat P = seg.prod(l, l + K);

            ll dp0 = 0;
            ll dp1 = (l == 0 ? INF : A[l - 1]);

            ll selected = min(add_inf(P.a[1][0], dp0), add_inf(P.a[1][1], dp1));
            ans = min(ans, selected);
        }

        cout << ans << '\n';
    }

    return 0;
}
```

## 样例验证

```text
输入
3
5 2
3 1 4 1 5
6 4
24 3 22 39 4 29
15 7
220651272 302798780 874479994 657822311 613294668 479624013 241168404 610547619 762548286 256160531 823041612 951553052 226556081 649525901 153805947

输出
2
29
1902064780
```
