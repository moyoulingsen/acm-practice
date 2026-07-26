# ABC452 F - Interval Inversion Count

## 网址

https://atcoder.jp/contests/abc452/tasks/abc452_f

## 题解

设：

```text
f(x) = 逆序对数 <= x 的区间数量
```

那么答案为：

```text
f(K) - f(K-1)
```

对固定的 `x`，用双指针维护窗口 `[l, r)`，并维护当前窗口逆序对数。

- 加入右端 `P[r]` 时，新增逆序对数量是窗口中大于 `P[r]` 的元素个数；
- 移除左端 `P[l]` 时，减少逆序对数量是窗口中小于 `P[l]` 的元素个数。

用 Fenwick Tree 维护窗口内值的出现次数，即可 `O(log N)` 查询小于/大于某值的数量。

时间复杂度：`O(N log N)`，因为调用两次 `f`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Fenwick {
    int n;
    vector<int> bit;

    Fenwick(int n_) : n(n_), bit(n_ + 1) {}

    void add(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) bit[idx] += val;
    }

    int sumPrefix(int idx) const {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx) res += bit[idx];
        return res;
    }

    int sumRange(int l, int r) const {
        if (l > r) return 0;
        return sumPrefix(r) - sumPrefix(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll K;
    cin >> N >> K;

    vector<int> P(N);
    for (int i = 0; i < N; i++) cin >> P[i];

    auto countAtMost = [&](ll limit) -> ll {
        if (limit < 0) return 0;

        Fenwick fw(N);
        ll inv = 0;
        ll ans = 0;
        int r = 0;

        for (int l = 0; l < N; l++) {
            while (r < N) {
                int greater = fw.sumRange(P[r] + 1, N);
                if (inv + greater > limit) break;

                inv += greater;
                fw.add(P[r], 1);
                r++;
            }

            ans += r - l;

            if (r > l) {
                int smaller = fw.sumRange(1, P[l] - 1);
                inv -= smaller;
                fw.add(P[l], -1);
            } else {
                r = l + 1;
            }
        }

        return ans;
    };

    cout << countAtMost(K) - countAtMost(K - 1) << '\n';
    return 0;
}
```

## 样例验证

```text
输入
7 3
6 3 2 1 7 5 4

输出
5
```

```text
输入
4 1
1 2 3 4

输出
0
```

```text
输入
25 18
14 19 24 8 12 11 6 5 3 13 22 15 17 2 9 4 7 18 10 25 23 16 1 20 21

输出
3
```
