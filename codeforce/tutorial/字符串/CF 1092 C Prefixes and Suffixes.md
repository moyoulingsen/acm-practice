# CF 1092 C - Prefixes and Suffixes

**题目链接**：<https://codeforces.com/problemset/problem/1092/C>

**题型**：字符串 / 构造

---

## 题意压缩

给出某个长度为 `n` 字符串的所有非完整前缀和后缀，要求标出每个串是前缀还是后缀。

---

## 关键观察

两个长度为 `n-1` 的串分别是最长前缀和最长后缀，因此原串只有两个候选。

---

## 思路步骤

1. 找两个长度 `n-1` 的串。
2. 拼出两个候选原串。
3. 对每个候选按长度匹配一前一后。
4. 输出合法标记。

---

## 复杂度

`O(n^2)`。

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

bool pref(const string &s, const string &p) {
    return s.substr(0, p.size()) == p;
}

bool suff(const string &s, const string &p) {
    return s.substr(s.size() - p.size()) == p;
}

string solve(const string &s, const vector<string> &v) {
    int m = v.size();
    string ans(m, '?');
    vector<int> used(m);
    vector<int> ord(m);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {
        return v[i].size() > v[j].size();
    });

    for (int id : ord) {
        if (used[id]) continue;
        if (!pref(s, v[id])) return "";
        used[id] = 1;
        ans[id] = 'P';
        bool ok = false;
        for (int j = 0; j < m; ++j) {
            if (!used[j] && v[j].size() == v[id].size() && suff(s, v[j])) {
                used[j] = 1;
                ans[j] = 'S';
                ok = true;
                break;
            }
        }
        if (!ok) return "";
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> v(2 * n - 2), big;
    for (string &s : v) {
        cin >> s;
        if ((int)s.size() == n - 1) big.push_back(s);
    }

    string a = big[0] + big[1].back();
    string b = big[1] + big[0].back();
    string ans = solve(a, v);
    if (ans.empty()) ans = solve(b, v);
    cout << ans << '\n';
    return 0;
}
```

---

## 一句话总结

最长两个片段决定两个原串候选，试出来即可。
