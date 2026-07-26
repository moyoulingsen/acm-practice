# CF 2218 A - The 67th Integer Problem

**题目链接**：<https://codeforces.com/problemset/problem/2218/A>

**对应题单**：CF 1090 Div.4 A

**题型**：数学 / 构造

**难度**：800

---

## 题意压缩

给定 `x`，需要输出一个整数 `y`，使题目中的表达式满足要求。

---

## 关键观察

题目核心等价于让：

\[
\min(x,y)=x
\]

只要 `y >= x` 就行。

又因为题目保证 `x <= 67`，所以直接输出 `67` 一定满足条件。

---

## 思路步骤

每组输入读入 `x`，直接输出 `67`。

---

## 复杂度

`O(1)`。

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
        int x;
        cin >> x;
        cout << 67 << '\n';
    }

    return 0;
}
```

---

## 一句话总结

因为 `x` 不超过 `67`，输出 `67` 就能让 `min(x,67)=x`。
