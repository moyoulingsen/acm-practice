# ABC448 C - Except and Min

## 网址

https://atcoder.jp/contests/abc448/tasks/abc448_c

## 题解

每次询问最多只会拿走 5 个球，所以全局最小的前 6 个球里一定至少有一个没被拿走。把 `(A_i, i)` 排序，只保留前 6 个候选。每次询问从这 6 个里找第一个没被拿走的即可。

时间复杂度：`O(N log N + Q)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<pair<long long, int>> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(a.begin(), a.end());

    vector<pair<long long, int>> cand;
    for (int i = 0; i < 6; i++) cand.push_back(a[i]);

    while (Q--) {
        int K;
        cin >> K;

        vector<int> removed(K);
        for (int i = 0; i < K; i++) cin >> removed[i];

        for (auto [val, idx] : cand) {
            bool gone = false;
            for (int x : removed) {
                if (x == idx) gone = true;
            }
            if (!gone) {
                cout << val << '\n';
                break;
            }
        }
    }

    return 0;
}
```

## 样例验证

核心性质是“最多删除 5 个，前 6 小至少剩 1 个”，与输入规模无关。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
