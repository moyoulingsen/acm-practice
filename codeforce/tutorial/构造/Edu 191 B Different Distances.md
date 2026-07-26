# Edu 191 B - Different Distances

**题目链接**：<https://codeforces.com/problemset/problem/2233/B>

**题型**：构造

**难度**：900

---

## 题意压缩

需要构造一个长度为 `4n` 的数组，每个数 `1..n` 出现四次，并满足同一个数相邻两次出现的三个距离两两不同。

---

## 关键观察

两个数可以用一个固定块一起构造：

```text
b a a b a b b a
```

对 `a` 来说，出现位置间距是 `1,2,4`；对 `b` 来说，出现位置间距是 `3,2,1`，都两两不同。

所以偶数个数字可以两两成组。

如果 `n` 是奇数，需要先用 `1,2,3` 的特殊块：

```text
3 3 2 1 1 2 1 2 2 3 1 3
```

然后剩下的数字继续两两成组。

---

## 思路步骤

1. 若 `n` 为奇数，先输出 `1,2,3` 的特殊构造。
2. 剩余数字每两个一组，按固定块输出。
3. 若 `n` 为偶数，全部按固定块输出。

---

## 复杂度

`O(n)`。

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vector<int> ans;

        auto addPair = [&](int a, int b) {
            ans.push_back(b);
            ans.push_back(a);
            ans.push_back(a);
            ans.push_back(b);
            ans.push_back(a);
            ans.push_back(b);
            ans.push_back(b);
            ans.push_back(a);
        };

        if (n % 2 == 1) {
            vector<int> base = {3, 3, 2, 1, 1, 2, 1, 2, 2, 3, 1, 3};
            ans.insert(ans.end(), base.begin(), base.end());
            for (int x = 4; x <= n; x += 2) addPair(x, x + 1);
        } else {
            for (int x = 1; x <= n; x += 2) addPair(x, x + 1);
        }

        for (int i = 0; i < (int)ans.size(); ++i) {
            cout << ans[i] << " \n"[i + 1 == (int)ans.size()];
        }
    }

    return 0;
}
```

---

## 一句话总结

偶数两两用固定块构造，奇数先用三元特殊块再两两构造。
