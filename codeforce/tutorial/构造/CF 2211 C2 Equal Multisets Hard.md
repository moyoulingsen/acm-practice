# CF 2211 C2 - Equal Multisets (Hard Version)

**题目链接**：<https://codeforces.com/problemset/problem/2211/C2>

**对应题单**：Codeforces Round 1088 C2

**题型**：构造 / 同余类 / 计数

**难度**：1800（蓝）

---

## 题意压缩

Hard 版本中，`a` 不再保证是排列。仍然给定部分数组 `b`，未知位置为 `-1`，判断能否补全使所有长度为 `k` 的窗口满足题目限制。

---

## 关键观察

长度为 `k` 的窗口不断平移时，下标会按 `i mod k` 分成若干条链。

对某个同余类：

- 如果这一类里的 `a` 不是全相等，那么这一类的位置没有整体替换自由度，所有已知 `b[i]` 都必须等于对应的 `a[i]`；
- 如果这一类里的 `a` 全相等，那么这一类在 `b` 中只能选择一个统一的值，所有已知值必须相同。

最后还要保证前 `k` 个位置的多重集合能够匹配，因为每个同余类会贡献一个代表值。

---

## 思路步骤

1. 统计 `a[0..k-1]` 的值出现次数。
2. 对每个同余类 `r`：
   - 检查 `a[r], a[r+k], ...` 是否全相等；
   - 统计这一类里已经给出的 `b` 值；
   - 非全等类：已知 `b[i]` 必须逐点等于 `a[i]`，代表值固定为 `a[r]`；
   - 全等类：已知 `b[i]` 必须全部相同，若已知则代表值固定为这个值，否则保留为自由类。
3. 对所有固定代表值，从前 `k` 的多重集合里扣掉。
4. 若没有出现负数，则剩余值可以分给自由类。

---

## 易错点

- 不能只检查每个位置，还要检查前 `k` 个代表值的多重集合。
- 全等同余类如果出现多个不同的已知 `b` 值，必定无解。
- 非全等同余类的已知 `b` 是逐点固定，不是只固定一个值。

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
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;

        map<int, int> need;
        for (int i = 0; i < k; ++i) need[a[i]]++;

        bool ok = true;
        int freeClass = 0;
        vector<int> fixed;

        for (int r = 0; r < k; ++r) {
            bool same = true;
            for (int i = r + k; i < n; i += k) {
                if (a[i] != a[r]) same = false;
            }

            int known = -1;
            for (int i = r; i < n; i += k) {
                if (b[i] == -1) continue;
                if (known == -1) known = b[i];
                else if (known != b[i]) ok = false;
            }

            if (!same) {
                for (int i = r; i < n; i += k) {
                    if (b[i] != -1 && b[i] != a[i]) ok = false;
                }
                fixed.push_back(a[r]);
            } else if (known != -1) {
                fixed.push_back(known);
            } else {
                freeClass++;
            }
        }

        for (int x : fixed) {
            if (--need[x] < 0) ok = false;
        }

        int left = 0;
        for (auto [x, c] : need) left += c;
        if (left != freeClass) ok = false;

        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}
```

---

## 一句话总结

Hard 版的核心是按 `mod k` 拆链：非全等链逐点固定，全等链贡献一个代表值，最后用前 `k` 位做多重集合匹配。
