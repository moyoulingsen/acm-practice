# CF 2228 A - Marisa Steals Reimu's Takeout

**题目链接**：<https://codeforces.com/problemset/problem/2228/A>

**题型**：计数 / 贪心

---

## 题意压缩

给若干个只可能为 `0,1,2` 的数，每次可以拿走一组和为 `3` 的倍数的数。问最多能操作多少次。

---

## 关键观察

按模 `3` 分类：

- 一个 `0` 自己就能组成一组；
- 一个 `1` 和一个 `2` 可以组成一组；
- 剩余的三个 `1` 可以组成一组；
- 剩余的三个 `2` 也可以组成一组。

---

## 思路步骤

1. 统计 `0,1,2` 的个数。
2. 答案先加 `cnt[0]`。
3. 匹配 `min(cnt[1], cnt[2])` 对 `1+2`。
4. 剩余数量各自除以 `3` 加入答案。

---

## 复杂度

`O(n)` 每组数据。

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

        int cnt[3] = {};
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            cnt[x]++;
        }

        int ans = cnt[0];
        int pair12 = min(cnt[1], cnt[2]);
        ans += pair12;
        cnt[1] -= pair12;
        cnt[2] -= pair12;
        ans += cnt[1] / 3 + cnt[2] / 3;

        cout << ans << '\n';
    }
    return 0;
}
```

---

## 一句话总结

按 `mod 3` 分类，优先用 `0` 和 `1+2`，再处理三个同类。
