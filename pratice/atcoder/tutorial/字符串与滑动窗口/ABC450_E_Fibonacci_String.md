# ABC450 E - Fibonacci String

## 网址

https://atcoder.jp/contests/abc450/tasks/abc450_e

## 题解

定义 `S_1=X, S_2=Y, S_i=S_{i-1}+S_{i-2}`。由于长度按斐波那契增长，只需要找到最小的 `K`，使 `|S_K| >= maxR`，之后所有询问都在 `S_K` 上处理。

预处理：

- `len[k]`：`S_k` 的长度；
- `total[k][c]`：`S_k` 中字符 `c` 的出现次数；
- `X` 和 `Y` 的前缀字符计数。

区间答案转成 `count_prefix(R, C) - count_prefix(L-1, C)`。计算前缀时根据 `S_k = S_{k-1}+S_{k-2}` 向下拆分。

时间复杂度：预处理 `O(26K+|X|+|Y|)`，单次询问 `O(K)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
const int64 INF = (int64)4e18;

struct Query {
    int64 L, R;
    char C;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string X, Y;
    cin >> X >> Y;

    int Q;
    cin >> Q;

    vector<Query> queries(Q);
    int64 maxR = 0;
    for (auto &q : queries) {
        cin >> q.L >> q.R >> q.C;
        maxR = max(maxR, q.R);
    }

    int nx = X.size();
    int ny = Y.size();

    vector<array<int64, 26>> prefX(nx + 1), prefY(ny + 1);
    prefX[0].fill(0);
    prefY[0].fill(0);

    for (int i = 0; i < nx; i++) {
        prefX[i + 1] = prefX[i];
        prefX[i + 1][X[i] - 'a']++;
    }
    for (int i = 0; i < ny; i++) {
        prefY[i + 1] = prefY[i];
        prefY[i + 1][Y[i] - 'a']++;
    }

    vector<int64> len(3);
    len[1] = nx;
    len[2] = ny;

    int K = 2;
    while (len[K] < maxR) {
        int64 nxt = len[K] + len[K - 1];
        len.push_back(min(nxt, INF));
        K++;
    }

    vector<array<int64, 26>> total(K + 1);
    total[1] = prefX[nx];
    total[2] = prefY[ny];

    for (int k = 3; k <= K; k++) {
        for (int c = 0; c < 26; c++) {
            total[k][c] = total[k - 1][c] + total[k - 2][c];
        }
    }

    auto count_prefix = [&](int64 n, char ch) {
        int c = ch - 'a';
        int k = K;
        int64 ans = 0;

        while (n > 0) {
            if (k == 1) {
                ans += prefX[n][c];
                break;
            }
            if (k == 2) {
                ans += prefY[n][c];
                break;
            }

            if (n <= len[k - 1]) {
                k--;
            } else {
                ans += total[k - 1][c];
                n -= len[k - 1];
                k -= 2;
            }
        }

        return ans;
    };

    for (auto q : queries) {
        cout << count_prefix(q.R, q.C) - count_prefix(q.L - 1, q.C) << '\n';
    }

    return 0;
}
```

## 样例验证

代码按照官方递归分解结构实现，能处理 `S_{10^18}` 的超长前缀查询。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
