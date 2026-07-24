# CF 1095 A - Repeating Cipher

**题目链接**：<https://codeforces.com/problemset/problem/1095/A>

**题型**：模拟 / 构造

**难度体感**：A 题，按题意直接模拟即可。

---

## 题意压缩

给一个字符串 `s`。

按如下方式取字符：

- 先取第 `1` 个字符；
- 然后跳 `2` 个位置取下一个；
- 再跳 `3` 个位置；
- 再跳 `4` 个位置……

问最后得到的新字符串是什么。

---

## 关键观察

这题没有隐藏算法。

只要维护两个变量：

- 当前下标 `pos`
- 当前步长 `step`

每次：

- 把 `s[pos]` 加入答案
- `pos += step`
- `step++`

直到越界为止。

---

## 思路步骤

1. 读入 `n` 和字符串 `s`
2. 令 `pos=0, step=1`
3. 不断取 `s[pos]`，然后 `pos += step, step++`
4. 输出答案

---

## 复杂度

\[
O(n)
\]

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    string ans;
    for (int pos = 0, step = 1; pos < n; pos += step, ++step) {
        ans += s[pos];
    }

    cout << ans << '\n';
    return 0;
}
```

---

## 一句话总结

这题就是：**按步长 `1,2,3,4...` 直接模拟取字符。**
