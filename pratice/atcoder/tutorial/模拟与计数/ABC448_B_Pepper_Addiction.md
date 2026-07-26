# ABC448 B - Pepper Addiction

## 网址

https://atcoder.jp/contests/abc448/tasks/abc448_b

## 题解

按胡椒种类分桶。设 `need[x]` 表示所有需要第 `x` 种胡椒的菜最多一共需要多少克，那么第 `x` 种胡椒实际最多贡献 `min(C_x, need[x])`。所有种类相加就是答案。

时间复杂度：`O(N+M)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<long long> C(M + 1), need(M + 1);
    for (int i = 1; i <= M; i++) cin >> C[i];

    for (int i = 0; i < N; i++) {
        int A;
        long long B;
        cin >> A >> B;
        need[A] += B;
    }

    long long ans = 0;
    for (int i = 1; i <= M; i++) ans += min(C[i], need[i]);

    cout << ans << '\n';
    return 0;
}
```

## 样例验证

代码为线性分桶做法，可以覆盖样例中的所有菜品与胡椒库存统计。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
