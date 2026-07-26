# CF 2222 B - Artistic Balance Tree

**题目链接**：<https://codeforces.com/problemset/problem/2222/B>

**题型**：贪心 / 优先队列 / 奇偶分类

---

## 题意压缩

数组位置按奇偶分成两类。操作只能影响同奇偶位置之间的选择，要求在若干指定位置相关操作后，让最终保留下来的权值和尽量小。

---

## 关键观察

中心反转只会让元素在相同奇偶位置之间移动，所以奇数位和偶数位互不影响。

对每种奇偶性：

- 第一次需要选择该奇偶位置时，必须标记一个元素；
- 为了让最终剩余和最小，应优先拿走最大值；
- 之后如果剩余最大值仍非负，就继续拿走；如果最大值为负，再拿走反而会让答案变大。

---

## 思路步骤

1. 按位置奇偶把权值分别放入两个大根堆。
2. 维护每种奇偶是否已经被选择过。
3. 对每次询问位置 `x`，只处理 `x` 的奇偶堆。
4. 若该堆顶非负，或该奇偶从未选过，则弹出堆顶并从总和中减去。
5. 输出最终总和。

---

## 易错点

- 奇偶按位置，不是按值；
- 每种奇偶第一次出现时，即使最大值是负数也要选一个；
- 之后负数不要再选。

---

## 复杂度

`O((n + m) log n)` 每组数据。

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
        int n, m;
        cin >> n >> m;

        long long sum = 0;
        priority_queue<long long> pq[2];

        for (int i = 1; i <= n; ++i) {
            long long x;
            cin >> x;
            sum += x;
            pq[i & 1].push(x);
        }

        bool used[2] = {false, false};

        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            int p = x & 1;

            if (!pq[p].empty() && (!used[p] || pq[p].top() >= 0)) {
                sum -= pq[p].top();
                pq[p].pop();
                used[p] = true;
            }
        }

        cout << sum << '\n';
    }
    return 0;
}
```

---

## 一句话总结

操作不改变位置奇偶，所以分奇偶用大根堆贪心拿走最该拿的值。
