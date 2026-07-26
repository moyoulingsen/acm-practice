# ABC459 C - Drop Blocks

## 网址

https://atcoder.jp/contests/abc459/tasks/abc459_c

## 题解

设第 `i` 个位置的真实高度为 `h[i]`。每次如果所有位置高度都至少为 `1`，就会整体下降 `1`。直接整体更新太慢，可以用全局偏移量维护。

令 `g` 表示已经整体下降的次数，维护：

```text
a[i] = h[i] + g
```

则真实高度为：

```text
h[i] = a[i] - g
```

操作 `1 x`：给第 `x` 个位置加一块，相当于 `a[x]++`。如果更新后没有位置满足 `a[i] == g`，说明所有真实高度都至少为 `1`，于是整体下降一次，即 `g++`。

操作 `2 y`：询问真实高度至少为 `y` 的位置数：

```text
a[i] - g >= y  <=>  a[i] >= g + y
```

因此需要动态维护所有 `a[i]` 的频率，并支持查询大于等于某个值的数量。由于 `a[i]` 每次只会加一，总最大值不超过 `Q`，用 Fenwick 树即可。

时间复杂度：`O(Q log Q)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<int> bit;

    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void add(int idx, int val) {
        idx++;
        for (; idx <= n; idx += idx & -idx) bit[idx] += val;
    }

    int sum_prefix(int idx) const {
        if (idx < 0) return 0;
        if (idx >= n) idx = n - 1;
        idx++;

        int res = 0;
        for (; idx > 0; idx -= idx & -idx) res += bit[idx];
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    int maxV = Q + 2;
    vector<int> a(N, 0), cnt(maxV + 1, 0);
    Fenwick fw(maxV + 1);

    cnt[0] = N;
    fw.add(0, N);

    int g = 0;

    while (Q--) {
        int type, v;
        cin >> type >> v;

        if (type == 1) {
            int x = v - 1;
            int old = a[x];
            int now = old + 1;
            a[x] = now;

            cnt[old]--;
            cnt[now]++;
            fw.add(old, -1);
            fw.add(now, 1);

            if (cnt[g] == 0) g++;
        } else {
            int target = g + v;
            if (target > maxV) {
                cout << 0 << '\n';
            } else {
                cout << N - fw.sum_prefix(target - 1) << '\n';
            }
        }
    }

    return 0;
}
```

## 样例验证

代码用全局偏移表示整体下降次数，并用 Fenwick 树维护压缩高度频率。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
