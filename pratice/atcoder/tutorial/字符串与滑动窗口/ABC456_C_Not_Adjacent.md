# ABC456 C - Not Adjacent

## 网址

https://atcoder.jp/contests/abc456/tasks/abc456_c

## 题解

合法子串要求相邻字符都不同，因此一个合法子串不能跨过任何一处 `S[i] == S[i+1]`。

把字符串按相邻相等的位置切成若干个极大段，每段内部相邻字符都不同。长度为 `len` 的段内所有子串都合法，贡献：

```text
len * (len + 1) / 2
```

时间复杂度：`O(|S|)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    const long long MOD = 998244353;
    string S;
    cin >> S;

    long long ans = 0;
    int start = 0;
    int n = (int)S.size();

    for (int i = 0; i < n; i++) {
        if (i + 1 == n || S[i] == S[i + 1]) {
            long long len = i - start + 1;
            ans += len * (len + 1) / 2;
            start = i + 1;
        }
    }

    cout << ans % MOD << '\n';
    return 0;
}
```

## 样例验证

```text
输入
abbc

输出
6
```
