# ABC454 F - Make it Palindrome 2

## 网址

https://atcoder.jp/contests/abc454/tasks/abc454_f

## 题解

只关心对称位置的差值：

```text
B_i = (A_i - A_{N+1-i}) mod M
```

目标是让所有 `B_i = 0`。

对原数组左半边操作等价于让某段 `B` 加 `1`；对右半边操作等价于让某段 `B` 减 `1`。

给 `B` 加首尾零哨兵，做循环意义下的差分：

```text
C_i = (B_i - B_{i-1}) mod M
```

一次区间操作等价于对 `C` 中一个位置 `+1`，另一个位置 `-1`。官方推导得到：排序 `C` 后，答案是最小的：

```text
|C| - sum(C)/M
```

个元素之和。

时间复杂度：`O(N log N)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        long long M;
        cin >> N >> M;

        vector<long long> A(N);
        for (int i = 0; i < N; i++) cin >> A[i];

        int H = N / 2;
        vector<long long> B(H + 2);

        for (int i = 0; i < H; i++) {
            long long x = (A[i] - A[N - 1 - i]) % M;
            if (x < 0) x += M;
            B[i + 1] = x;
        }

        vector<long long> C;
        C.reserve(H + 1);

        for (int i = 1; i <= H + 1; i++) {
            long long x = (B[i] - B[i - 1]) % M;
            if (x < 0) x += M;
            C.push_back(x);
        }

        sort(C.begin(), C.end());

        long long sum = 0;
        for (long long x : C) sum += x;

        int take = (int)C.size() - (int)(sum / M);

        long long ans = 0;
        for (int i = 0; i < take; i++) ans += C[i];

        cout << ans << '\n';
    }

    return 0;
}
```

## 样例验证

```text
输入
3
4 5
0 3 1 2
1 20260418
454
7 12
3 1 4 1 5 9 2

输出
3
0
5
```
