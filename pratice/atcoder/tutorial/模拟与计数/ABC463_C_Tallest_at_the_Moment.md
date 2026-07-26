# ABC463 C - Tallest at the Moment

## 网址

https://atcoder.jp/contests/abc463/tasks/abc463_c

## 题解

询问时刻是 `T + 1/2`，离开时刻为 `L_i` 的人此时还在房间中，当且仅当：

```text
L_i > T
```

题目保证 `L_i` 按非降序给出，所以对每次询问，用二分找到第一个 `L_i > T` 的位置 `idx`。答案就是后缀区间 `[idx, N)` 中身高 `H_i` 的最大值。

预处理后缀最大值：

```text
suf[i] = max(H_i, H_{i+1}, ..., H_{N-1})
```

这样每个询问只需要一次 `upper_bound`。

时间复杂度：`O(N + Q log N)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> H(N), L(N);
    for (int i = 0; i < N; i++) cin >> H[i] >> L[i];

    vector<long long> suf(N + 1, 0);
    for (int i = N - 1; i >= 0; i--) {
        suf[i] = max(suf[i + 1], H[i]);
    }

    int Q;
    cin >> Q;
    while (Q--) {
        long long T;
        cin >> T;
        int idx = upper_bound(L.begin(), L.end(), T) - L.begin();
        cout << suf[idx] << '\n';
    }

    return 0;
}
```

## 样例验证

代码把每次询问转化成后缀最大值查询。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
