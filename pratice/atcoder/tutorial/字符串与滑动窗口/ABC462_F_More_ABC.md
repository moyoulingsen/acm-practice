# ABC462 F - More ABC

## 网址

https://atcoder.jp/contests/abc462/tasks/abc462_f

## 题解

给定字符串 `S` 和整数 `K`，一次操作可以把一个字符替换成任意大写字母。设 `cnt(S)` 为子串 `ABC` 的出现次数，要求最少操作数使最终字符串的 `ABC` 数量恰好增加 `K`，不可行输出 `-1`。

官方做法把“恰好增加 `K`”转成“至少增加 `K`”来做 DP。原因是如果某个方案让 `ABC` 数量增加超过 `K`，把修改逐个撤销回原串时，增加量会一步步回到 `0`，过程中一定会经过 `K`，且修改次数不会更多。

下标按 `1` 开始，令：

- `z[i] = 1` 表示原串中有一个 `ABC` 以位置 `i` 结尾；
- `y[i]` 表示把 `S[i-2..i]` 改成 `ABC` 的最少修改次数；
- `x[i] = z[i-2] + z[i-1] + z[i]`，表示原串中与区间 `[i-2,i]` 发生重叠的原有 `ABC` 数量。

定义：

```text
dp[i][j] = 只考虑前 i 个字符，使 ABC 数量相比原串前缀至少多 j 个的最少修改次数
```

只需要保存 `0 <= j <= K`。

转移分两种：

1. 修改后不让 `ABC` 以 `i` 结尾。若原串本来有一个 `ABC` 以 `i` 结尾，则这个原有贡献在当前分支中消失，所以前 `i-1` 位要至少多 `j + z[i]` 个：

```text
dp[i][j] <- dp[i-1][j+z[i]]
```

当 `j+z[i] > K` 时直接跳过，不能把它截断成 `K`。

2. 强制 `S[i-2..i]` 变成 `ABC`。这会新增一个结尾为 `i` 的 `ABC`，同时覆盖掉原串中结尾在 `i-2..i` 的原有 `ABC`，净增量为 `1 - x[i]`：

```text
dp[i][j] <- dp[i-3][j-1+x[i]] + y[i]
```

时间复杂度：`O(NK)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    const int INF = 1e9;
    while (T--) {
        string S;
        int K;
        cin >> S >> K;

        int N = (int)S.size();
        vector<int> z(N + 1), x(N + 1), y(N + 1);

        for (int i = 3; i <= N; i++) {
            y[i] = (S[i - 3] != 'A') + (S[i - 2] != 'B') + (S[i - 1] != 'C');
            z[i] = (S[i - 3] == 'A' && S[i - 2] == 'B' && S[i - 1] == 'C');
        }

        for (int i = 3; i <= N; i++) {
            for (int e = max(3, i - 2); e <= i; e++) {
                x[i] += z[e];
            }
        }

        vector<vector<int>> dp(N + 1, vector<int>(K + 1, INF));
        for (int i = 0; i <= N; i++) dp[i][0] = 0;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= K; j++) {
                if (j + z[i] <= K) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j + z[i]]);
                }

                if (i >= 3) {
                    int need = j - 1 + x[i];
                    if (0 <= need && need <= K) {
                        dp[i][j] = min(dp[i][j], dp[i - 3][need] + y[i]);
                    }
                }
            }
        }

        cout << (dp[N][K] >= INF ? -1 : dp[N][K]) << '\n';
    }

    return 0;
}
```

## 样例验证

代码实现官方前缀 DP，并且在 `j+z[i] > K` 时跳过转移，避免错误截断。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
