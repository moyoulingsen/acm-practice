# ABC452 C - Fishbones

## 网址

https://atcoder.jp/contests/abc452/tasks/abc452_c

## 题解

如果脊骨选择字符串 `S_j`，首先它的长度必须等于 `N`。

第 `i` 根肋骨要求存在某个给定字符串 `X` 满足：

- `|X| = A_i`
- `X[B_i] = S_j[i]`

因此可以预处理：

```text
ok[len][pos][char]
```

表示是否存在长度为 `len`，且第 `pos` 个字符为 `char` 的给定字符串。因为长度和位置都不超过 10，字符只有 26 种，这个表很小。

之后对每个候选脊骨字符串逐个位置检查即可。

时间复杂度：`O(总字符串长度 + M N)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N + 1), B(N + 1);
    for (int i = 1; i <= N; i++) cin >> A[i] >> B[i];

    int M;
    cin >> M;

    vector<string> S(M);
    bool ok[11][11][26] = {};

    for (int j = 0; j < M; j++) {
        cin >> S[j];
        int len = (int)S[j].size();
        for (int pos = 1; pos <= len; pos++) {
            ok[len][pos][S[j][pos - 1] - 'a'] = true;
        }
    }

    for (const string &spine : S) {
        if ((int)spine.size() != N) {
            cout << "No\n";
            continue;
        }

        bool possible = true;
        for (int i = 1; i <= N; i++) {
            int c = spine[i - 1] - 'a';
            if (!ok[A[i]][B[i]][c]) {
                possible = false;
                break;
            }
        }

        cout << (possible ? "Yes" : "No") << '\n';
    }

    return 0;
}
```

## 样例验证

```text
输入
5
5 3
5 2
4 1
5 1
3 2
8
retro
chris
itchy
tuna
crab
rock
cod
ash

输出
Yes
Yes
No
No
No
No
No
No
```

```text
输入
5
5 1
5 2
5 3
5 4
5 5
8
retro
chris
itchy
tuna
crab
rock
cod
ash

输出
Yes
Yes
Yes
No
No
No
No
No
```
