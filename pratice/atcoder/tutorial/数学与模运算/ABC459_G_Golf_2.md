# ABC459 G - Golf 2

## 网址

https://atcoder.jp/contests/abc459/tasks/abc459_g

## 题解

每步可以走 `(±A, ±B)` 或 `(±B, ±A)`，问到达 `(X,Y)` 的最少步数。

先令 `g=gcd(A,B)`。每一步横纵坐标变化都是 `g` 的倍数，所以若 `X` 或 `Y` 不是 `g` 的倍数，则无解。否则把 `A,B,X,Y` 同除以 `g`。

把操作分成两类：

- 类型 1：`(±A, ±B)`；
- 类型 2：`(±B, ±A)`。

固定两类操作次数的奇偶性 `c1,c2`。若类型 1 的横纵方向符号和分别为 `2x1+c1`、`2y1+c1`，类型 2 的横纵方向符号和分别为 `2x2+c2`、`2y2+c2`，则需要满足：

```text
A*x1 + B*x2 = (X - A*c1 - B*c2) / 2
B*y1 + A*y2 = (Y - B*c1 - A*c2) / 2
```

右侧不是整数时跳过。用扩展欧几里得求 `A*u + B*v = 1`，即可参数化所有解：

```text
x1 = u*nx + B*n
x2 = v*nx - A*n

y1 = v*ny + A*m
y2 = u*ny - B*m
```

对于固定的 `n,m`，需要的步数为：

```text
max(|2x1+c1|, |2y1+c1|) + max(|2x2+c2|, |2y2+c2|)
```

这是关于 `n,m` 的凸分段线性函数。官方结论：整数最优点一定在实数最优点附近，而实数最优点出现在若干折线交点附近。枚举四条折线两两交点，并检查附近常数范围内的整数点即可。

时间复杂度：每组 `O(log(A+B))`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using i128 = __int128_t;

const i64 INF = (1LL << 62);

i64 floor_div(i128 a, i128 b) {
    if (b < 0) {
        a = -a;
        b = -b;
    }
    i128 q = a / b;
    i128 r = a % b;
    if (r < 0) --q;
    return (i64)q;
}

i64 exgcd(i64 a, i64 b, i64 &x, i64 &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    i64 x1, y1;
    i64 g = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

i64 solve_one(i64 A, i64 B, i64 X, i64 Y) {
    i64 g = gcd(A, B);
    if (X % g != 0 || Y % g != 0) return -1;

    A /= g;
    B /= g;
    X /= g;
    Y /= g;

    i64 u, v;
    exgcd(A, B, u, v);

    i64 ans = INF;

    for (i64 c1 = 0; c1 <= 1; c1++) {
        for (i64 c2 = 0; c2 <= 1; c2++) {
            i64 rx = X - A * c1 - B * c2;
            i64 ry = Y - B * c1 - A * c2;
            if (rx % 2 != 0 || ry % 2 != 0) continue;

            i64 nx = rx / 2;
            i64 ny = ry / 2;

            i128 x10 = (i128)u * nx;
            i128 x20 = (i128)v * nx;
            i128 y10 = (i128)v * ny;
            i128 y20 = (i128)u * ny;

            auto eval = [&](i64 n, i64 m) {
                i128 p = 2 * (x10 + (i128)B * n) + c1;
                i128 q = 2 * (y10 + (i128)A * m) + c1;
                i128 r = 2 * (x20 - (i128)A * n) + c2;
                i128 s = 2 * (y20 - (i128)B * m) + c2;

                i128 ap = p >= 0 ? p : -p;
                i128 aq = q >= 0 ? q : -q;
                i128 ar = r >= 0 ? r : -r;
                i128 as = s >= 0 ? s : -s;

                return (i64)(max(ap, aq) + max(ar, as));
            };

            i128 e1 = 2 * x10 + c1;
            i128 e2 = 2 * y10 + c1;
            i128 e3 = 2 * x20 + c2;
            i128 e4 = 2 * y20 + c2;

            struct Line {
                i128 a, b, c;
            };

            array<Line, 4> lines = {{
                { 2 * (i128)B, -2 * (i128)A, e1 - e2},
                { 2 * (i128)B,  2 * (i128)A, e1 + e2},
                {-2 * (i128)A,  2 * (i128)B, e3 - e4},
                {-2 * (i128)A, -2 * (i128)B, e3 + e4}
            }};

            for (int i = 0; i < 4; i++) {
                for (int j = i + 1; j < 4; j++) {
                    i128 det = lines[i].a * lines[j].b - lines[j].a * lines[i].b;
                    if (det == 0) continue;

                    i128 numN = lines[j].c * lines[i].b - lines[i].c * lines[j].b;
                    i128 numM = lines[j].a * lines[i].c - lines[i].a * lines[j].c;

                    i64 n0 = floor_div(numN, det);
                    i64 m0 = floor_div(numM, det);

                    for (i64 dn = -2; dn <= 2; dn++) {
                        for (i64 dm = -2; dm <= 2; dm++) {
                            ans = min(ans, eval(n0 + dn, m0 + dm));
                        }
                    }
                }
            }
        }
    }

    return ans == INF ? -1 : ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        i64 A, B, X, Y;
        cin >> A >> B >> X >> Y;
        cout << solve_one(A, B, X, Y) << '\n';
    }

    return 0;
}
```

## 样例验证

代码枚举两类步数奇偶性，将问题化为二元整数凸优化，并检查官方证明给出的常数候选点。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
