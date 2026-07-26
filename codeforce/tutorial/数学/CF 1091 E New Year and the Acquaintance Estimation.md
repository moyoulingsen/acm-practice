# CF 1091 E - New Year and the Acquaintance Estimation

**题目链接**：<https://codeforces.com/problemset/problem/1091/E>

**题型**：图论 / 数学 / Erdős-Gallai 定理

---

## 题意压缩

给出 `n` 个点的度数，求 Bob 的所有可能度数 `x`，使加入 Bob 后的度数序列可构成简单无向图。

---

## 关键观察

可图化用 Erdős-Gallai 定理判断；同时总度数必须为偶数，所以 `x` 的奇偶性固定。可行值在同奇偶下连续。

---

## 思路步骤

1. 原度数降序排序，并预处理前缀和。
2. 因为 `sum + x` 必须为偶数，只考虑固定奇偶性的 `x`。
3. 写 `check(x)`，在线性时间内把 `x` 合并进降序序列并检查 Erdős-Gallai。
4. 可行 `x` 在同奇偶下连续，用二分找左右端点。
5. 输出区间内所有同奇偶值。

---

## 复杂度

\[
O(n \log n)
\]

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int TOO_SMALL = -1;
const int OK = 0;
const int TOO_BIG = 1;

int n;
vector<int> a;
ll base_sum;

int check(int x) {
    vector<int> cnt(n + 1, 0);
    for (int v : a) cnt[v]++;
    cnt[x]++;

    ll left = 0;
    ll right = 0;
    int less = 0;
    int ptr = 0;

    for (int k = 0; k <= n; ++k) {
        int v;
        bool took_x = false;

        if (ptr == k && (ptr == n || a[ptr] < x)) {
            v = x;
            took_x = true;
        } else {
            v = a[ptr++];
        }

        left += v;
        cnt[v]--;

        right -= min(v, k);
        if (v < k) less--;
        less += cnt[k];

        int remaining = n - k;
        int greater_than_k = remaining - less;
        right += greater_than_k;

        ll rhs = 1LL * (k + 1) * k + right;
        if (left > rhs) return took_x ? TOO_BIG : TOO_SMALL;
    }

    return OK;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    a.resize(n);

    base_sum = 0;
    for (int &x : a) {
        cin >> x;
        base_sum += x;
    }

    sort(a.begin(), a.end(), greater<int>());

    int parity = base_sum & 1;
    int max_t = (n - parity) / 2;

    int L = -1;
    int lo = 0, hi = max_t;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int x = 2 * mid + parity;
        if (check(x) == TOO_SMALL) lo = mid + 1;
        else L = mid, hi = mid - 1;
    }

    if (L == -1) {
        cout << -1 << '\n';
        return 0;
    }

    int R = -1;
    lo = L, hi = max_t;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int x = 2 * mid + parity;
        if (check(x) == TOO_BIG) hi = mid - 1;
        else R = mid, lo = mid + 1;
    }

    if (R == -1 || L > R) {
        cout << -1 << '\n';
        return 0;
    }

    for (int t = L; t <= R; ++t) {
        if (t > L) cout << ' ';
        cout << 2 * t + parity;
    }
    cout << '\n';
    return 0;
}
```

---

## 一句话总结

补 Bob 的度数后，本质就是度数序列可图化判定。
