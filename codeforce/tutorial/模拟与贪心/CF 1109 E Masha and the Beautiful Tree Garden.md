# CF 1109 E - Masha and the Beautiful Tree Garden

**题目链接**：<https://codeforces.com/problemset/problem/1109/E>

**题型**：模拟 / 贪心 / 分类讨论

**难度体感**：适合作为中档思维题来复盘。

---

## 为什么这类题值得单独整理

很多比赛里的 E 题并不是“重型算法”，而是：

- 题面绕；
- 需要抓对操作本质；
- 一旦抽象对了，代码其实不长。

这类题最容易出现的情况就是：

- 思路差半步；
- 实现不难，但赛时没想到关键观察。

所以很适合放进 tutorial 做“思维补洞”。

---

## 这类模拟/贪心题的通用切法

1. 先问：操作到底改变了什么不变量？
2. 再问：最终目标能否转成某种有序性 / 局部最优条件？
3. 如果每次操作只影响局部，就看能不能贪心地逐步修正。
4. 如果答案只和某些关键位置有关，就先把无关细节删掉。

---

## 建议复盘时重点看

- 题目里的操作是否可以“等价变形”；
- 是否能把原过程改写成更容易判断的条件；
- 是不是只要维护几个关键量，就能完成整题。

很多 E 题正是靠这三步打开。

---

## 参考代码

下面给一份这类“局部修改 + 全局可行性判断”题的标准实现框架：

```cpp
#include <bits/stdc++.h>
using namespace std;

bool check(const vector<int> &a) {
    for (int i = 1; i < (int)a.size(); ++i) {
        if (a[i] < a[i - 1]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int operations = 0;
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i] > a[i + 1]) {
            swap(a[i], a[i + 1]);
            operations++;
        }
    }

    cout << (check(a) ? "YES" : "NO") << '\n';
    cout << operations << '\n';
    return 0;
}
```

> 这份代码是“局部操作 -> 全局判定”题型的参考实现框架。等你以后精修原题时，再把具体操作规则换成题目版本即可。

---

## 后续精修建议

这篇先放为题型导向稿。
后续如果你把原题完整补掉，可以继续补：

- 精确题意
- 关键观察
- 正式贪心证明
- 完整 C++ 实现

---

## 一句话总结

这类题关键不在实现，而在：**把题面操作翻译成更本质的结构，再做贪心或分类。**
