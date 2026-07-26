# ABC458 F - Critical Misread

## 网址

https://atcoder.jp/contests/abc458/tasks/abc458_f

## 题解

这是典型的“避免若干禁用子串”的计数问题。

构造 Aho-Corasick 自动机：

- 状态表示当前已生成字符串的最长后缀，该后缀同时是某个禁用串的前缀；
- 若进入某个状态时已经匹配到完整禁用串，则该状态不可用；
- 对每个合法状态和每个字符 `a..z`，转移到下一个合法状态。

由于 `N` 最大到 `10^9`，不能逐位 DP。把自动机转移写成矩阵 `M`：

```text
M[i][j] = 从状态 i 加一个字符后转移到状态 j 的字符种数
```

答案为初始向量 `[1,0,0,...]` 乘以 `M^N` 后所有合法状态计数之和。

自动机节点数不超过 `1 + sum |S_i| <= 101`。

时间复杂度：`O(V^3 log N)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 998244353;

struct Node {
    int nxt[26];
    int link;
    bool out;

    Node() {
        fill(nxt, nxt + 26, -1);
        link = 0;
        out = false;
    }
};

using Matrix = vector<vector<ll>>;

Matrix multiply(const Matrix &A, const Matrix &B) {
    int n = (int)A.size();
    Matrix C(n, vector<ll>(n));

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            if (A[i][k] == 0) continue;
            for (int j = 0; j < n; j++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }

    return C;
}

vector<ll> multiply_vec(const vector<ll> &v, const Matrix &M) {
    int n = (int)v.size();
    vector<ll> res(n);

    for (int i = 0; i < n; i++) {
        if (v[i] == 0) continue;
        for (int j = 0; j < n; j++) {
            res[j] = (res[j] + v[i] * M[i][j]) % MOD;
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    int K;
    cin >> N >> K;

    vector<Node> trie(1);

    auto insert_pattern = [&](const string &s) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (trie[v].nxt[c] == -1) {
                trie[v].nxt[c] = (int)trie.size();
                trie.emplace_back();
            }
            v = trie[v].nxt[c];
        }
        trie[v].out = true;
    };

    for (int i = 0; i < K; i++) {
        string s;
        cin >> s;
        insert_pattern(s);
    }

    queue<int> q;

    for (int c = 0; c < 26; c++) {
        int u = trie[0].nxt[c];
        if (u == -1) {
            trie[0].nxt[c] = 0;
        } else {
            trie[u].link = 0;
            q.push(u);
        }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        trie[v].out = trie[v].out || trie[trie[v].link].out;

        for (int c = 0; c < 26; c++) {
            int u = trie[v].nxt[c];
            if (u == -1) {
                trie[v].nxt[c] = trie[trie[v].link].nxt[c];
            } else {
                trie[u].link = trie[trie[v].link].nxt[c];
                q.push(u);
            }
        }
    }

    int V = (int)trie.size();
    Matrix M(V, vector<ll>(V));

    for (int i = 0; i < V; i++) {
        if (trie[i].out) continue;
        for (int c = 0; c < 26; c++) {
            int j = trie[i].nxt[c];
            if (!trie[j].out) M[i][j] = (M[i][j] + 1) % MOD;
        }
    }

    vector<ll> vec(V);
    vec[0] = 1;

    while (N > 0) {
        if (N & 1) vec = multiply_vec(vec, M);
        M = multiply(M, M);
        N >>= 1;
    }

    ll ans = 0;
    for (ll x : vec) ans = (ans + x) % MOD;

    cout << ans << '\n';
    return 0;
}
```

## 样例验证

```text
输入
3 2
aa
ab

输出
17474
```

```text
输入
1 1
ab

输出
26
```

```text
输入
1000000000 10
contest
tester
error
orange
angel
elegant
antitese
sextuple
pleasure
surely

输出
698570468
```
