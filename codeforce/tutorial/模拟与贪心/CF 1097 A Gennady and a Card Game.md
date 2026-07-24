# CF 1097 A - Gennady and a Card Game

**题目链接**：<https://codeforces.com/problemset/problem/1097/A>

**题型**：模拟 / 字符串匹配

**难度体感**：A 题，核心是只检查“点数或花色是否相同”。

---

## 题意压缩

给一张桌面上的牌，再给手里的 5 张牌。

每张牌由两个字符组成：

- 第一个字符：点数；
- 第二个字符：花色。

如果手里存在一张牌，和桌面牌的**点数相同**或**花色相同**，就可以打出，输出 `YES`，否则输出 `NO`。

---

## 关键观察

不需要判断整张牌完全相同。

只要满足下面任意一个条件：

- `card[0] == table[0]`
- `card[1] == table[1]`

就可以。

---

## 思路步骤

1. 读入桌面牌 `s`。
2. 循环读入 5 张手牌。
3. 如果任意一张手牌点数或花色和 `s` 相同，标记成功。
4. 输出 `YES/NO`。

---

## 易错点

- 不要只判断完整字符串相等；
- 不要忘记手牌固定是 5 张。

---

## 复杂度

\[
O(5)
\]

---

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string table;
    cin >> table;

    bool ok = false;
    for (int i = 0; i < 5; ++i) {
        string card;
        cin >> card;
        if (card[0] == table[0] || card[1] == table[1]) ok = true;
    }

    cout << (ok ? "YES" : "NO") << '\n';
    return 0;
}
```

---

## 一句话总结

这题就是：**只要手牌和桌面牌有一个位置相同，就能出牌。**
