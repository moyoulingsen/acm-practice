# CF 1093 C - Mishka and the Last Exam

**题目链接**：<https://codeforces.com/problemset/problem/1093/C>

**题型**：构造 / 贪心

**难度体感**：C 题很经典，训练“两端构造”的感觉。

---

## 题意压缩

有一个长度为 `n` 的非降数组 `a`，但你不知道它本身；
你只知道长度为 `n/2` 的数组 `b`，其中：

\[
b_i = a_i + a_{n-i+1}
\]

要求构造一个合法的非降数组 `a`。

---

## 关键观察

因为 `a` 要非降，所以：

- 左半部分尽量小；
- 右半部分由 `b_i - a_i` 决定。

更具体地说：

- `a[i]` 越小越好，这样更容易保持左边非降；
- 同时 `a[n-i+1] = b[i] - a[i]`，它也必须保持不下降。

所以我们可以从两端往中间构造：

- 左边维护一个当前最小可取值 `L`
- 右边维护一个当前最大可取值 `R`

对于每个 `b[i]`：

- 令左边尽量取 `L`
- 右边取 `b[i]-L`
- 如果这样会超过右边允许上界，就反过来调整

更直接的标准写法是：

- `a[i] = max(a[i-1], b[i] - a[n-i+2])`
- `a[n-i+1] = b[i] - a[i]`

---

## 更好记的构造方式

从左到右处理 `b[i]`。

设当前已经确定：

- 左边上一项 `a[i-1]`
- 右边上一项 `a[n-i+2]`

为了保持非降：

- 左边当前项不能小于 `a[i-1]`
- 右边当前项不能大于 `a[n-i+2]`

所以若 `b[i] - a[i-1] <= a[n-i+2]`，就让左边尽量小：

- `a[i] = a[i-1]`
- `a[n-i+1] = b[i] - a[i]`

否则就让右边卡上界：

- `a[n-i+1] = a[n-i+2]`
- `a[i] = b[i] - a[n-i+1]`

---

## 思路步骤

1. 读入 `n` 和 `b`
2. 维护答案数组 `a`
3. 初始化两端边界
4. 从 `i=1` 到 `n/2` 逐步构造
5. 输出 `a`

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
    cin >> n;
    vector<long long> b(n / 2 + 1), a(n + 1, 0);
    for (int i = 1; i <= n / 2; ++i) cin >> b[i];

    a[1] = 0;
    a[n] = b[1];

    for (int i = 2; i <= n / 2; ++i) {
        long long leftPrev = a[i - 1];
        long long rightPrev = a[n - i + 2];
        if (b[i] - leftPrev <= rightPrev) {
            a[i] = leftPrev;
            a[n - i + 1] = b[i] - a[i];
        } else {
            a[n - i + 1] = rightPrev;
            a[i] = b[i] - a[n - i + 1];
        }
    }

    for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
    cout << '\n';
    return 0;
}
```

---

## 一句话总结

这题本质是：**左边尽量小、右边尽量大，在保持整体非降的前提下从两端贪心构造。**
