# CF 1096 G - Drowning

**真实题号**：CF 2227 G

**题目链接**：<https://codeforces.com/problemset/problem/2227/G>

**题型**：前缀和 / 树状数组 / 交错和

**难度体感**：2000，关键是找到操作不变量。

---

## 题意压缩

要统计满足条件的子数组数量。

经过题目中的操作，一个子数组最终能被缩成一个正数，就算合法。

---

## 关键观察 1：长度必须是奇数

每次操作都会让长度减少 `2`。

所以最后能缩成一个元素的子数组，初始长度必须是奇数。

---

## 关键观察 2：交错和不变

对区间 `[l,r]` 定义交错和：

\[
a_l-a_{l+1}+a_{l+2}-a_{l+3}+\cdots
\]

题目操作不会改变这个交错和。

最后只剩下一个数时，这个数就是原区间的交错和。

因此合法条件等价于：

- 区间长度为奇数；
- 区间交错和大于 `0`。

---

## 用前缀交错和转化

定义：

\[
pref_i=a_1-a_2+a_3-a_4+\cdots+(-1)^{i-1}a_i
\]

对区间 `[l,r]`：

- 如果 `l` 是奇数，交错和为 `pref[r]-pref[l-1]`，需要 `pref[r] > pref[l-1]`；
- 如果 `l` 是偶数，交错和方向相反，需要 `pref[r] < pref[l-1]`。

区间长度为奇数等价于 `l` 和 `r` 奇偶相同，也等价于 `l-1` 和 `r` 奇偶不同。

扫描右端点 `r` 时：

- 若 `r` 是奇数，对应 `l` 也是奇数，所以 `l-1` 是偶数，要数历史偶数下标中 `pref < pref[r]`；
- 若 `r` 是偶数，对应 `l` 也是偶数，所以 `l-1` 是奇数，要数历史奇数下标中 `pref > pref[r]`。

---

## 数据结构

把所有 `pref` 离散化。

用两个树状数组分别维护：

- 偶数下标的历史 `pref`；
- 奇数下标的历史 `pref`。

每扫到一个 `r`，先统计答案，再把 `pref[r]` 加进对应奇偶的树状数组。

---

## 复杂度

\[
O(n\log n)
\]

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Fenwick {
    int n;
    vector<int> bit;

    Fenwick(int n = 0) { init(n); }

    void init(int n_) {
        n = n_;
        bit.assign(n + 1, 0);
    }

    void add(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) bit[idx] += val;
    }

    int sum(int idx) const {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx) res += bit[idx];
        return res;
    }

    int range_sum(int l, int r) const {
        if (l > r) return 0;
        return sum(r) - sum(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vector<ll> pref(n + 1, 0), values;
        values.push_back(0);

        for (int i = 1; i <= n; ++i) {
            ll x;
            cin >> x;
            pref[i] = pref[i - 1] + (i & 1 ? x : -x);
            values.push_back(pref[i]);
        }

        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());

        auto id = [&](ll x) {
            return int(lower_bound(values.begin(), values.end(), x) - values.begin()) + 1;
        };

        int m = values.size();
        Fenwick even(m), odd(m);
        even.add(id(pref[0]), 1);

        long long ans = 0;
        for (int r = 1; r <= n; ++r) {
            int pos = id(pref[r]);
            if (r & 1) {
                ans += even.sum(pos - 1);
                odd.add(pos, 1);
            } else {
                ans += odd.range_sum(pos + 1, m);
                even.add(pos, 1);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
```

---

## 一句话总结

这题就是：**合法区间等价于“奇数长度 + 交错和为正”，然后用树状数组统计前缀交错和大小关系。**
