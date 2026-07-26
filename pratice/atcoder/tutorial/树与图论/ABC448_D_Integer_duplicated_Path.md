# ABC448 D - Integer-duplicated Path

## 网址

https://atcoder.jp/contests/abc448/tasks/abc448_d

## 题解

以 `1` 为根 DFS。维护当前根到当前点路径上每个值出现了多少次，以及当前路径上有多少种值出现次数至少为 2。

进入一个点时：

- 如果这个值原来出现过 1 次，那么加入后就产生了一种重复值；
- 更新当前点答案；
- 继续 DFS 子树。

离开这个点时，把它对频率的影响撤销。因为 `A_i` 可能很大，先做坐标压缩。

时间复杂度：`O(N log N)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Event {
    int v;
    int p;
    int type;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> A(N);
    for (auto &x : A) cin >> x;

    vector<long long> vals = A;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    vector<int> id(N);
    for (int i = 0; i < N; i++) {
        id[i] = lower_bound(vals.begin(), vals.end(), A[i]) - vals.begin();
    }

    vector<vector<int>> g(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> freq(vals.size());
    vector<int> ans(N);
    int duplicated = 0;

    vector<Event> st;
    st.push_back({0, -1, 0});

    while (!st.empty()) {
        auto [v, p, type] = st.back();
        st.pop_back();

        int x = id[v];

        if (type == 0) {
            if (freq[x] == 1) duplicated++;
            freq[x]++;
            ans[v] = duplicated > 0;

            st.push_back({v, p, 1});
            for (int to : g[v]) {
                if (to != p) st.push_back({to, v, 0});
            }
        } else {
            freq[x]--;
            if (freq[x] == 1) duplicated--;
        }
    }

    for (int x : ans) cout << (x ? "Yes" : "No") << '\n';
    return 0;
}
```

## 样例验证

代码使用迭代 DFS，避免链状树递归爆栈，并按进入/退出事件维护路径频率。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
