# ABC452 G - 221 Substring

## 网址

https://atcoder.jp/contests/abc452/tasks/abc452_g

## 题解

称一个正整数序列是 221 序列，当且仅当它的每一段连续相同值的 run 都满足：

```text
run 的长度 = run 的值
```

先对 `A` 做 run-length encoding，得到若干段 `(value, length)`。

一个合法 221 子序列在 run 层面满足：

- 首尾 run 可以从原 run 中截取，所以只需要 `value <= length`；
- 中间 run 必须完整取下，所以必须 `value == length`；
- 若 `value > length`，这一段不能贡献合法 run。

把每个 RLE 段转换成新序列 `T`：

- 若 `value > length`，转换成 `0`；
- 若 `value == length`，转换成 `value`；
- 若 `value < length`，转换成 `value, 0, value`。

此时问题等价于：统计 `T` 中不含 `0` 的不同非空连续子数组数量。

对 `T` 建后缀数组和 LCP。令 `zeroFree[i]` 表示从 `T[i]` 开始连续非 0 的最大长度。按后缀数组顺序遍历后缀，当前后缀最多贡献 `zeroFree[sa[i]]` 个合法前缀，其中与前一个后缀 LCP 重叠的部分已经统计过，因此新增：

```text
max(0, zeroFree[sa[i]] - lcp_with_previous)
```

时间复杂度：`O(N)` 到 `O(N log N)`，取决于后缀数组实现。下面代码使用 AtCoder Library 的 `suffix_array` / `lcp_array`。

## 代码

```cpp
#include <bits/stdc++.h>
#include <atcoder/string>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<pair<int, int>> runs;
    for (int i = 0; i < N;) {
        int j = i;
        while (j < N && A[j] == A[i]) j++;
        runs.push_back({A[i], j - i});
        i = j;
    }

    vector<int> T;
    T.reserve(runs.size() * 3);

    for (auto [v, len] : runs) {
        if (v > len) {
            T.push_back(0);
        } else if (v == len) {
            T.push_back(v);
        } else {
            T.push_back(v);
            T.push_back(0);
            T.push_back(v);
        }
    }

    int m = (int)T.size();
    if (m == 0) {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> zeroFree(m + 1);
    for (int i = m - 1; i >= 0; i--) {
        zeroFree[i] = (T[i] == 0 ? 0 : zeroFree[i + 1] + 1);
    }

    vector<int> sa = atcoder::suffix_array(T, 10);
    vector<int> lcp = atcoder::lcp_array(T, sa);

    ll ans = 0;
    for (int i = 0; i < m; i++) {
        int overlap = (i == 0 ? 0 : lcp[i - 1]);
        int can = zeroFree[sa[i]];
        ans += max(0, can - overlap);
    }

    cout << ans << '\n';
    return 0;
}
```

## 样例验证

```text
输入
23
2 2 3 3 3 1 1 1 3 3 3 1 2 2 2 1 9 1 4 4 4 4 4

输出
14
```

```text
输入
2
6 7

输出
0
```

说明：该代码依赖 AtCoder Library 的 `<atcoder/string>`，AtCoder 评测环境支持；当前本地环境未确认安装 ACL，因此本地样例验证可能跳过本题。
