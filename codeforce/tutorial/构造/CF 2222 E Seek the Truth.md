# CF 2222 E - Seek the Truth

**题目链接**：<https://codeforces.com/problemset/problem/2222/E>

**对应题单**：Codeforces Round 1094 E

**题型**：交互 / 构造 / 二进制

**难度**：2000（紫）

---

## 题意压缩

这是交互题。需要通过若干次询问判断隐藏操作或隐藏值。

题解重点不是本地输出答案，而是设计询问策略。

---

## 关键观察

常见的三类位运算操作可以通过特殊值区分：

- 用 `0` 询问可以区分一部分操作；
- 用 `2^i` 可以逐位判断；
- 已知某些边界后，可以用二分或全 1 掩码继续区分。

核心思路是先把候选操作集合缩小，再用二进制位逐个定位隐藏值。

---

## 交互策略

1. 先用 `0` 做一次初始询问。
2. 如果集合大小没有变化，可以判定进入 AND 类情况：
   - 对每一位询问 `2^bit`；
   - 根据返回变化判断隐藏值这一位是否存在。
3. 否则集合形态可转化为 `{0, c}`：
   - 用 `Q(mid)` 二分出 `c`；
   - 再用最低位或全 1 掩码区分 OR / XOR。
4. 最后输出判断结果。

---

## 易错点

- 交互题每次输出后必须 `flush`。
- 读到 `-1` 说明询问非法或交互失败，要立即退出。
- 位数要按题目上界开够，通常用 `long long`。
- 不能把交互代码当普通本地代码测试。

---

## 代码骨架

```cpp
#include <bits/stdc++.h>
using namespace std;

long long askI(long long x) {
    cout << "I " << x << endl;
    long long res;
    cin >> res;
    if (res == -1) exit(0);
    return res;
}

long long askQ(long long x) {
    cout << "Q " << x << endl;
    long long res;
    cin >> res;
    if (res == -1) exit(0);
    return res;
}

void answer(long long x) {
    cout << "A " << x << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long first = askI(0);

    if (first == 0) {
        long long c = 0;
        for (int bit = 0; bit < 60; ++bit) {
            long long res = askI(1LL << bit);
            if (res) c |= 1LL << bit;
        }
        answer(c);
    } else {
        long long l = 0, r = (1LL << 60) - 1;
        while (l < r) {
            long long mid = (l + r) / 2;
            if (askQ(mid)) r = mid;
            else l = mid + 1;
        }

        long long c = l;
        long long probe = c & -c;
        long long res = askI(probe);
        answer(res ? c : -c);
    }
    return 0;
}
```

---

## 一句话总结

交互题的关键是用 `0`、`2^i`、二分和全位掩码把位运算类型与隐藏值逐步分离。
