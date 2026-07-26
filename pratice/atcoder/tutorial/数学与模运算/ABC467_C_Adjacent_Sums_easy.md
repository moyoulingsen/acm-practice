# ABC467 C - Adjacent Sums (easy)

## 网址

https://atcoder.jp/contests/abc467/tasks/abc467_c

## 题解

一次操作可以把某个 `A_i` 加 `1`。目标是让最终数组满足：

```text
(A_i + A_{i+1}) mod M = B_i
```

本题是 easy 版，`M = 2`。最终只需要关心每个数的奇偶性。

设最终的余数数组为 `C`，则：

```text
C_i + C_{i+1} ≡ B_i (mod 2)
```

只要确定 `C_1`，后面的所有 `C_i` 都会被唯一确定：

```text
C_{i+1} ≡ B_i - C_i (mod 2)
```

`C_1` 只有 `0` 和 `1` 两种情况，分别模拟即可。对于每个位置，如果 `A_i mod 2` 和目标 `C_i` 不同，就需要加 `1` 次；否则不需要操作。

时间复杂度：`O(N)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> A(N), B(N - 1);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i + 1 < N; i++) cin >> B[i];

    long long ans = (1LL << 60);

    for (int first = 0; first < 2; first++) {
        long long cost = 0;
        int cur = first;

        for (int i = 0; i < N; i++) {
            if (A[i] % 2 != cur) cost++;
            if (i + 1 < N) cur = (B[i] - cur + 2) % 2;
        }

        ans = min(ans, cost);
    }

    cout << ans << '\n';
    return 0;
}
```

## 样例验证

代码枚举第一个位置的目标奇偶性，然后由相邻和条件唯一推出整段目标奇偶性。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
