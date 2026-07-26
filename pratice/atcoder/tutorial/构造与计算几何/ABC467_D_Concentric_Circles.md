# ABC467 D - Concentric Circles

## 网址

https://atcoder.jp/contests/abc467/tasks/abc467_d

## 题解

要判断是否存在同心的两个圆，使得 `P, Q` 在第一个圆上，`R, S` 在第二个圆上。

设公共圆心为 `O = (x, y)`。`P, Q` 到圆心距离相等，等价于：

```text
OP^2 = OQ^2
```

展开后得到一条直线，也就是线段 `PQ` 的垂直平分线：

```text
2(Qx - Px)x + 2(Qy - Py)y = Qx^2 + Qy^2 - Px^2 - Py^2
```

同理，`R, S` 也会得到一条垂直平分线。问题就变成：这两条直线是否存在公共点。

两条直线如果不平行，一定有交点；如果平行，则只有它们是同一条直线时才有公共点。

由于坐标乘法可能比较大，用 `__int128` 做中间计算更稳妥。

时间复杂度：每组数据 `O(1)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using i128 = __int128_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        ll Px, Py, Qx, Qy, Rx, Ry, Sx, Sy;
        cin >> Px >> Py >> Qx >> Qy >> Rx >> Ry >> Sx >> Sy;

        i128 a1 = 2LL * (Qx - Px);
        i128 b1 = 2LL * (Qy - Py);
        i128 c1 = (i128)Qx * Qx + (i128)Qy * Qy - (i128)Px * Px - (i128)Py * Py;

        i128 a2 = 2LL * (Sx - Rx);
        i128 b2 = 2LL * (Sy - Ry);
        i128 c2 = (i128)Sx * Sx + (i128)Sy * Sy - (i128)Rx * Rx - (i128)Ry * Ry;

        i128 det = a1 * b2 - a2 * b1;
        bool ok = det != 0 || (a1 * c2 == a2 * c1 && b1 * c2 == b2 * c1);

        cout << (ok ? "Yes" : "No") << '\n';
    }

    return 0;
}
```

## 样例验证

代码把“同圆心”转化为两条垂直平分线是否相交，覆盖了两个圆重合的情况。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
