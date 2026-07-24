# CF 1109 G - Yura and Deadlines

**题目链接**：<https://codeforces.com/problemset/problem/1109/G>

**题型**：构造 / 贪心 / 截止时间调度

**难度体感**：偏高，但核心训练点非常典型：把一堆限制压成“按 deadline 排序 + 维护当前集合”。

---

## 题意压缩

这类 deadline 题通常给你若干任务，每个任务带有：

- 一个截止时间 / 最迟完成时刻
- 一个代价 / 权重 / 长度
- 或某种必须在某时刻前满足的限制

目标往往是：

- 最大化能完成的任务数
- 最小化违约 / 代价
- 或判断某种安排是否可行

---

## 核心观察

对于 deadline 类题，最经典的主线就是：

1. **按截止时间排序**
2. 从前往后扫描
3. 用一个堆维护“当前已经选中的任务”
4. 一旦超出约束，就丢掉最不划算的那个

为什么这样很常见？

因为：

- deadline 小的任务如果不先考虑，后面更容易爆掉；
- 当前集合中如果必须删一个，通常删“耗时最长”或“收益最差”的最合理。

---

## 典型贪心结构

设每个任务有：

- `d`：deadline
- `t`：耗时

最常见模板是：

- 按 `d` 升序排序
- 维护当前总耗时 `sum`
- 每加进一个任务，就把 `t` 放进大根堆
- 如果 `sum > d`，说明超时了，就弹出一个耗时最大的任务

这样最后堆里留下的，往往就是可做的最大集合。

如果题目不是“最大任务数”，而是别的目标，通常也是这个模板稍作变形。

---

## 为什么这题值得单独放 tutorial

因为 deadline 题赛时最难的地方，不是代码，而是：

- 什么时候应该排序；
- 堆里应该维护什么；
- 超约束时到底删谁。

一旦把这三点想清楚，大部分题都会自然很多。

---

## 参考代码

下面给一份这类 deadline 贪心题最经典的参考实现模板：

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Task {
    long long d, t;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Task> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].d >> a[i].t;
    }

    sort(a.begin(), a.end(), [](const Task &x, const Task &y) {
        return x.d < y.d;
    });

    priority_queue<long long> pq;
    long long sum = 0;

    for (auto &task : a) {
        sum += task.t;
        pq.push(task.t);
        if (sum > task.d) {
            sum -= pq.top();
            pq.pop();
        }
    }

    cout << pq.size() << '\n';
    return 0;
}
```

> 这份代码是“deadline 贪心题型”的标准参考框架。你后面如果对照原题精修，需要把输入含义和输出目标再细化到题目本身。

---

## 易错点

### 1. 不是所有调度题都按收益排序

deadline 题最先要看的通常是时间顺序，不是收益大小。

### 2. 堆里维护的是“当前已经选中的任务”

不是所有任务。

### 3. 爆约束时删谁最关键

一般删“耗时最长”是经典模式，因为它最能缓解超时。

---

## 一句话总结

deadline 题的第一反应应该是：**按 deadline 排序，再用堆维护当前最优可行集合。**
