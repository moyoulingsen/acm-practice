# ABC456 D - Not Adjacent 2

## 网址

https://atcoder.jp/contests/abc456/tasks/abc456_d

## 题解

令 `dp[c]` 表示当前处理过的前缀中，以字符 `c` 结尾的合法非空子序列个数。

处理当前字符 `c` 时，新生成的合法子序列可以是：

- 只选当前字符；
- 接在任意一个末尾不是 `c` 的合法子序列后面。

加上原本以 `c` 结尾的子序列，官方转移可简写为：

```text
dp[c] = dp['a'] + dp['b'] + dp['c'] + 1
```

右侧使用更新前的总和。

时间复杂度：`O(|S|)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    const long long MOD = 998244353;
    string S;
    cin >> S;

    vector<long long> dp(3);

    for (char ch : S) {
        int c = ch - 'a';
        long long sum = (dp[0] + dp[1] + dp[2] + 1) % MOD;
        dp[c] = sum;
    }

    cout << (dp[0] + dp[1] + dp[2]) % MOD << '\n';
    return 0;
}
```

## 样例验证

```text
输入
abbc

输出
11
```
