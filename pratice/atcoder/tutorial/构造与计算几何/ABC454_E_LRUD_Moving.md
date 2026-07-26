# ABC454 E - LRUD Moving

## 网址

https://atcoder.jp/contests/abc454/tasks/abc454_e

## 题解

给定 `N x N` 网格，从 `(1,1)` 出发走到 `(N,N)`，除指定禁用格 `(A,B)` 外，每个格子恰好访问一次。

先看必要条件：路径每走一步，棋盘黑白颜色交替。

- 如果 `N` 为奇数，`(1,1)` 与 `(N,N)` 同色，但路径长度会导致颜色数量不匹配，所以无解；
- 如果 `N` 为偶数，必须删掉一个白格，也就是 `A+B` 必须为奇数。

因此充要条件是：

```text
N 为偶数 且 A+B 为奇数
```

构造使用官方的剥层方法：先按上下两行蛇形剥掉，再按左右两列剥掉，最后化为 `2x2` 基础情形。

时间复杂度：`O(N^2)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, A, B;
        cin >> N >> A >> B;

        if (N % 2 == 1 || (A + B) % 2 == 0) {
            cout << "No\n";
            continue;
        }

        --A;
        --B;

        vector<string> pre, suf;

        for (int t = 0; t < N / 2 - 1; t++) {
            string s;
            s += string(N - 1, 'R');
            s += 'D';
            s += string(N - 1, 'L');
            s += 'D';

            if (A >= 2) {
                pre.push_back(s);
                A -= 2;
            } else {
                reverse(s.begin(), s.end());
                suf.push_back(s);
            }
        }

        for (int t = 0; t < N / 2 - 1; t++) {
            string s = "DRUR";

            if (B >= 2) {
                pre.push_back(s);
                B -= 2;
            } else {
                reverse(s.begin(), s.end());
                suf.push_back(s);
            }
        }

        if (A == 0 && B == 1) pre.push_back("DR");
        else pre.push_back("RD");

        string ans;
        for (auto &s : pre) ans += s;
        for (int i = (int)suf.size() - 1; i >= 0; i--) ans += suf[i];

        cout << "Yes\n";
        cout << ans << '\n';
    }

    return 0;
}
```

## 样例验证

```text
输入
3
2 1 2
3 2 2
4 3 2

输出例
Yes
DR
No
Yes
RRRDLLLDDRRURD
```

说明：本题输出路径不唯一，只要合法即可。
