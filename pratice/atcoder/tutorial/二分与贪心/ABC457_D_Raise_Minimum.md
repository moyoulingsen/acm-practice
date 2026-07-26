# ABC457 D - Raise Minimum

## 网址

https://atcoder.jp/contests/abc457/tasks/abc457_d

## 题解

二分答案 `X`，判断是否能让所有 `A_i >= X`。

对于第 `i` 个元素：

- 若 `A_i >= X`，不需要操作；
- 否则每次操作能增加 `i`，所需次数为：

```text
ceil((X - A_i) / i)
```

把所有元素所需次数求和，若不超过 `K`，则 `X` 可行。

二分上界可以取 `A_1 + K + 1`，因为第一个元素每次只能加 `1`。

时间复杂度：`O(N log(A_1+K))`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using i128 = __int128_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int64 K;
    cin >> N >> K;

    vector<int64> A(N + 1);
    for (int i = 1; i <= N; i++) cin >> A[i];

    auto ok = [&](int64 x) -> bool {
        i128 need = 0;
        for (int i = 1; i <= N; i++) {
            if (A[i] < x) {
                need += (x - A[i] + i - 1) / i;
                if (need > K) return false;
            }
        }
        return need <= K;
    };

    int64 low = 1;
    int64 high = A[1] + K + 1;

    while (high - low > 1) {
        int64 mid = low + (high - low) / 2;
        if (ok(mid)) low = mid;
        else high = mid;
    }

    cout << low << '\n';
    return 0;
}
```

## 样例验证

```text
输入
3 3
1 2 3

输出
3
```

```text
输入
4 5
10 1 10 1

输出
7
```

```text
输入
20 457
8 9 10 9 8 8 4 6 8 1 5 10 2 8 2 6 8 1 6 6

输出
132
```
