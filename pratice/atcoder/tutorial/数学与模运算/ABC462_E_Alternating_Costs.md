# ABC462 E - Alternating Costs

## 网址

https://atcoder.jp/contests/abc462/tasks/abc462_e

## 题解

每次移动到相邻格，费用随步数奇偶交替：奇数步横向费用为 `A`、纵向费用为 `B`；偶数步横向费用为 `B`、纵向费用为 `A`。要求从 `(0,0)` 到 `(X,Y)` 的最小费用。

方向正负不影响费用，先取：

```text
x = |X|, y = |Y|
```

先考虑 `x+y` 为偶数的情况。定义 `calc(A,B,x,y)` 表示偶数步可达时的最小费用。由于偶数总步数中奇数步和偶数步数量相等，可以同时交换 `A,B`，也可以交换 `x,y`，令：

```text
A <= B, x <= y
```

此时最优只会出现在两个端点：

1. 直接用较便宜的方向安排到 `2y` 步，费用 `2*A*y`；
2. 用最短步数 `x+y`，其中多出来的纵向差额会产生 `(B-A)` 的额外费用，费用：

```text
A*(x+y) + (B-A)*(y-x)/2
```

所以：

```text
calc = min(2*A*y, A*(x+y) + (B-A)*(y-x)/2)
```

若 `x+y` 为奇数，最后一步一定是奇数步。枚举最后一步：

- 从 `(x-1,y)` 横向走到 `(x,y)`，加 `A`；
- 从 `(x,y-1)` 纵向走到 `(x,y)`，加 `B`。

于是答案是：

```text
min(calc(A,B,x-1,y)+A, calc(A,B,x,y-1)+B)
```

时间复杂度：每组 `O(1)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll calc(ll A, ll B, ll x, ll y) {
    if (A > B) swap(A, B);
    if (x > y) swap(x, y);

    ll v1 = 2 * A * y;
    ll v2 = A * (x + y) + (B - A) * (y - x) / 2;
    return min(v1, v2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        ll A, B, X, Y;
        cin >> A >> B >> X >> Y;

        ll x = llabs(X);
        ll y = llabs(Y);

        ll ans;
        if ((x + y) % 2 == 0) {
            ans = calc(A, B, x, y);
        } else {
            ans = min(calc(A, B, x - 1, y) + A,
                      calc(A, B, x, y - 1) + B);
        }

        cout << ans << '\n';
    }

    return 0;
}
```

## 样例验证

代码直接实现官方闭式公式和奇偶转移。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
