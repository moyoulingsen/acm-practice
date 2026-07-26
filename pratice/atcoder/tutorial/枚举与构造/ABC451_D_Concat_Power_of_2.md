# ABC451 D - Concat Power of 2

## 网址

https://atcoder.jp/contests/abc451/tasks/abc451_d

## 题解

“好整数”是由一个或多个 `2` 的幂按十进制字符串拼接得到的整数。题目保证答案不超过 `10^9`，所以可以直接枚举所有不超过 `10^9` 的好整数，排序后输出第 `N` 个。

按十进制位数做集合 DP：

- `P[len]`：恰好 `len` 位的 `2` 的幂；
- `X[len]`：恰好 `len` 位的好整数；
- `X[0] = {0}`。

转移时枚举最后拼上的 `i` 位 2 的幂 `p`：

```text
y = x * 10^i + p
```

其中 `x in X[len-i]`，`p in P[i]`。

最后收集所有 `<= 10^9` 的结果，排序去重。

时间复杂度取决于枚举出的好整数数量；在 `10^9` 限制内可以通过。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    const long long LIM = 1000000000LL;

    vector<long long> pow10(11, 1);
    for (int i = 1; i <= 10; i++) pow10[i] = pow10[i - 1] * 10;

    vector<vector<long long>> P(11);
    for (long long x = 1; x <= LIM; x *= 2) {
        int len = (int)to_string(x).size();
        if (len <= 10) P[len].push_back(x);
    }

    vector<unordered_set<long long>> X(11);
    X[0].insert(0);

    vector<long long> all;

    for (int len = 1; len <= 10; len++) {
        for (int i = 1; i <= len; i++) {
            for (long long x : X[len - i]) {
                for (long long p : P[i]) {
                    long long y = x * pow10[i] + p;
                    if (y <= LIM) X[len].insert(y);
                }
            }
        }
        for (long long x : X[len]) all.push_back(x);
    }

    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());

    cout << all[N - 1] << '\n';
    return 0;
}
```

## 样例验证

```text
输入
10

输出
21
```

```text
输入
69

输出
328
```

```text
输入
1099898

输出
819264512
```
