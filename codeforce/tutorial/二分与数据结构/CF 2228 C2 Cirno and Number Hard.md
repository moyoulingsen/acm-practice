# CF 2228 C2 - Cirno and Number (Hard Version)

**题目链接**：<https://codeforces.com/problemset/problem/2228/C2>

**题型**：数位贪心 / 构造

---

## 题意压缩

给定数字 `a` 和允许数字集合，找只由允许数字组成的非负整数 `b`，最小化 `|a-b|`。

Hard 版 `a` 很大，不能暴力枚举。

---

## 关键观察

只需要分别找：

- 不小于 `a` 的最小合法数 `hi`；
- 不大于 `a` 的最大合法数 `lo`。

答案就是：

```text
min(hi - a, a - lo)
```

这两个数可以用数位贪心构造：从高位到低位尽量相等，遇到不能相等的位置就改成更大或更小的允许数字，后面填最小或最大允许数字。

---

## 思路步骤

1. 排序允许数字。
2. 构造同长度的 `lo` 和 `hi`。
3. 若同长度构造失败，`lo` 可尝试更短长度最大数，`hi` 可尝试更长长度最小数。
4. 取最小差值。

---

## 易错点

- 多位数不能有前导零；
- 数字 `0` 本身可以单独存在；
- 回退到前一位时，后缀要填最大或最小允许数字。

---

## 复杂度

每组数据 `O(位数 * 10)`。

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = (ll)4e18;

vector<int> d;

ll val(const vector<int> &v) {
    ll x = 0;
    for (int c : v) x = x * 10 + c;
    return x;
}

bool valid_first(int x, int len) {
    return len == 1 || x != 0;
}

ll max_len(int len) {
    vector<int> v(len);
    int first = -1;
    for (int i = (int)d.size() - 1; i >= 0; --i) {
        if (valid_first(d[i], len)) {
            first = d[i];
            break;
        }
    }
    if (first == -1) return -1;
    v[0] = first;
    for (int i = 1; i < len; ++i) v[i] = d.back();
    return val(v);
}

ll min_len(int len) {
    vector<int> v(len);
    int first = -1;
    for (int x : d) {
        if (valid_first(x, len)) {
            first = x;
            break;
        }
    }
    if (first == -1) return INF;
    v[0] = first;
    for (int i = 1; i < len; ++i) v[i] = d.front();
    return val(v);
}

ll lower_same(const string &s) {
    int len = s.size();
    vector<int> v(len);
    for (int i = 0; i < len; ++i) {
        int cur = s[i] - '0';
        bool same = false;
        for (int x : d) if (x == cur && valid_first(x, len)) same = true;
        if (same) {
            v[i] = cur;
            continue;
        }

        int small = -1;
        for (int x : d) if (x < cur && valid_first(x, len)) small = x;
        if (small != -1) {
            v[i] = small;
            for (int j = i + 1; j < len; ++j) v[j] = d.back();
            return val(v);
        }

        for (int j = i - 1; j >= 0; --j) {
            small = -1;
            for (int x : d) if (x < v[j] && valid_first(x, len)) small = x;
            if (small != -1) {
                v[j] = small;
                for (int k = j + 1; k < len; ++k) v[k] = d.back();
                return val(v);
            }
        }
        return -1;
    }
    return val(v);
}

ll upper_same(const string &s) {
    int len = s.size();
    vector<int> v(len);
    for (int i = 0; i < len; ++i) {
        int cur = s[i] - '0';
        bool same = false;
        for (int x : d) if (x == cur && valid_first(x, len)) same = true;
        if (same) {
            v[i] = cur;
            continue;
        }

        int big = 10;
        for (int x : d) if (x > cur && valid_first(x, len)) big = min(big, x);
        if (big != 10) {
            v[i] = big;
            for (int j = i + 1; j < len; ++j) v[j] = d.front();
            return val(v);
        }

        for (int j = i - 1; j >= 0; --j) {
            big = 10;
            for (int x : d) if (x > v[j] && valid_first(x, len)) big = min(big, x);
            if (big != 10) {
                v[j] = big;
                for (int k = j + 1; k < len; ++k) v[k] = d.front();
                return val(v);
            }
        }
        return INF;
    }
    return val(v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        ll a;
        int n;
        cin >> a >> n;

        d.resize(n);
        for (int &x : d) cin >> x;
        sort(d.begin(), d.end());

        string s = to_string(a);
        int len = s.size();

        ll lo = lower_same(s);
        for (int l = 1; l < len; ++l) lo = max(lo, max_len(l));

        ll hi = upper_same(s);
        hi = min(hi, min_len(len + 1));

        ll ans = INF;
        if (lo != -1) ans = min(ans, a - lo);
        if (hi != INF) ans = min(ans, hi - a);
        cout << ans << '\n';
    }
    return 0;
}
```

---

## 一句话总结

分别构造离 `a` 最近的合法下界和上界，再取较小差值。
