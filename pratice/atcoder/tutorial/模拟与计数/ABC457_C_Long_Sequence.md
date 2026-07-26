# ABC457 C - Long Sequence

## 网址

https://atcoder.jp/contests/abc457/tasks/abc457_c

## 题解

第 `i` 段对长序列 `B` 的贡献长度为：

```text
L_i * C_i
```

依次扣掉整段长度，找到 `K` 落在哪个 `A_i` 的重复块中。如果落在第 `i` 段，则答案为：

```text
A_i[(K - 1) % L_i]
```

时间复杂度：`O(sum L_i + N)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long K;
    cin >> N >> K;

    vector<vector<long long>> A(N);
    vector<int> L(N);

    for (int i = 0; i < N; i++) {
        cin >> L[i];
        A[i].resize(L[i]);
        for (int j = 0; j < L[i]; j++) cin >> A[i][j];
    }

    vector<long long> C(N);
    for (int i = 0; i < N; i++) cin >> C[i];

    for (int i = 0; i < N; i++) {
        long long block = 1LL * L[i] * C[i];
        if (K <= block) {
            cout << A[i][(K - 1) % L[i]] << '\n';
            return 0;
        }
        K -= block;
    }

    return 0;
}
```

## 样例验证

```text
输入
3 9
3 1 3 2
1 3
2 4 3
1 3 2

输出
4
```

```text
输入
3 1
1 7
1 111
1 5
1 100 10000

输出
7
```

```text
输入
3 3163812
5 1 2 3 4 5
4 9 8 7 6
2 10 11
87043 908415 9814

输出
9
```
