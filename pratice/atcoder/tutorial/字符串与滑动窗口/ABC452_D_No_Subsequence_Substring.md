# ABC452 D - No-Subsequence Substring

## 网址

https://atcoder.jp/contests/abc452/tasks/abc452_d

## 题解

对每个左端点 `l`，求从 `l` 开始最短扩展到哪个右端点 `r`，才能让 `T` 成为 `S[l..r]` 的子序列。

如果最短右端点是 `r`，那么：

- `S[l..l]` 到 `S[l..r-1]` 都不包含 `T` 作为子序列；
- `S[l..r]` 及更长子串都包含。

贡献为 `r-l`。如果从 `l` 开始无法匹配完整 `T`，贡献为 `n-l`。

预处理 `nxt[i][c]` 表示从位置 `i` 开始字符 `c` 下一次出现的位置。然后对每个 `l` 按 `T` 贪心跳转。

时间复杂度：`O(26|S| + |S||T|)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S, T;
    cin >> S >> T;

    int n = (int)S.size();
    const int INF = n;

    vector<array<int, 26>> nxt(n + 2);
    for (int c = 0; c < 26; c++) {
        nxt[n][c] = INF;
        nxt[n + 1][c] = INF;
    }

    for (int i = n - 1; i >= 0; i--) {
        nxt[i] = nxt[i + 1];
        nxt[i][S[i] - 'a'] = i;
    }

    long long ans = 0;

    for (int l = 0; l < n; l++) {
        int pos = l;
        bool found = true;

        for (char ch : T) {
            int p = nxt[pos][ch - 'a'];
            if (p == INF) {
                found = false;
                break;
            }
            pos = p + 1;
        }

        if (!found) ans += n - l;
        else ans += (pos - 1) - l;
    }

    cout << ans << '\n';
    return 0;
}
```

## 样例验证

```text
输入
abrakadabra
aba

输出
51
```

```text
输入
aaaaa
a

输出
0
```

```text
输入
rdddrdtdcdrrdcredctdordoeecrotet
dcre

输出
263
```
