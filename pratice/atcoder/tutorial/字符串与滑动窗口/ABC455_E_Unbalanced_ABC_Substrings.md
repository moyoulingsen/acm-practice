# ABC455 E - Unbalanced ABC Substrings

## 网址

https://atcoder.jp/contests/abc455/tasks/abc455_e

## 题解

要求统计非空子串中，`A, B, C` 三种字符出现次数两两不同的数量。

总子串数为：

```text
N * (N + 1) / 2
```

不合法是至少有一组相等：

```text
A = B 或 A = C 或 B = C
```

用容斥：

```text
答案 = 总数 - f(A=B) - f(A=C) - f(B=C) + 2 * f(A=B=C)
```

用前缀计数：

- 子串满足 `A=B` 等价于两个前缀的 `countA-countB` 相等；
- 子串满足 `A=B=C` 等价于两个前缀的 `(countA-countB, countA-countC)` 相等。

统计相同前缀状态的配对数即可。

时间复杂度：`O(N)` 期望。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string S;
    cin >> N >> S;

    int offset = N;
    int base = 2 * N + 1;

    vector<ll> cntAB(base), cntAC(base), cntBC(base);
    unordered_map<long long, ll> cntABC;
    cntABC.reserve(2 * N + 10);

    auto encode = [&](int x, int y) -> long long {
        return 1LL * (x + offset) * base + (y + offset);
    };

    int a = 0, b = 0, c = 0;
    ll fAB = 0, fAC = 0, fBC = 0, fABC = 0;

    cntAB[offset] = 1;
    cntAC[offset] = 1;
    cntBC[offset] = 1;
    cntABC[encode(0, 0)] = 1;

    for (char ch : S) {
        if (ch == 'A') a++;
        else if (ch == 'B') b++;
        else c++;

        int ab = a - b;
        int ac = a - c;
        int bc = b - c;

        fAB += cntAB[ab + offset]++;
        fAC += cntAC[ac + offset]++;
        fBC += cntBC[bc + offset]++;

        long long key = encode(ab, ac);
        fABC += cntABC[key]++;
    }

    ll total = 1LL * N * (N + 1) / 2;
    ll ans = total - fAB - fAC - fBC + 2 * fABC;

    cout << ans << '\n';
    return 0;
}
```

## 样例验证

```text
输入
6
AABBCC

输出
4
```

```text
输入
6
ABCABC

输出
0
```

```text
输入
10
ACABCAABAB

输出
17
```
