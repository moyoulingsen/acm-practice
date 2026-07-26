# CF 2222 A - A Wonderful Contest

**题目链接**：<https://codeforces.com/problemset/problem/2222/A>

**题型**：数学 / 观察

---

## 题意压缩

每道题有 `a[i]` 个小部分，每个小部分分值为 `100 / a[i]`。问能否凑出从 `0` 到 `100n` 的所有整数分数。

---

## 关键观察

如果要凑出分数 `1`，必须存在某个小部分正好值 `1` 分。

也就是：

```text
100 / a[i] = 1
=> a[i] = 100
```

如果存在 `a[i]=100`，这道题本身可以提供 `0..100` 的任意整数分，其他题只需要取 `0` 或 `100`，即可覆盖全部分数。

---

## 思路步骤

1. 检查是否存在 `a[i] == 100`。
2. 存在输出 `Yes`，否则输出 `No`。

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

        bool ok = false;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (x == 100) ok = true;
        }

        cout << (ok ? "Yes" : "No") << '\n';
    }
    return 0;
}
```

---

## 一句话总结

能不能凑出 1 分决定一切，所以只看有没有 `100` 个小部分的题。
