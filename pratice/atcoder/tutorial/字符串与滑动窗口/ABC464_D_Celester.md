# ABC464 D - Celester

## 网址

https://atcoder.jp/contests/abc464/tasks/abc464_d

## 题解

每天原本天气为 `S` 或 `R`，可以支付 `X_i` 把这一天翻转。最终每出现一个相邻模式 `RS`，获得 `Y_i` 的快乐值。要求最大总快乐值。

从左到右 DP，只需要知道前一天最终天气是什么。

设处理到当前位置后：

- `dpS`：当前天最终为 `S` 的最大收益；
- `dpR`：当前天最终为 `R` 的最大收益。

转移到第 `i` 天：

- 若第 `i` 天最终为 `S`，从前一天 `R` 转移会形成 `RS`，获得 `Y[i-1]`；从前一天 `S` 转移没有奖励。
- 若第 `i` 天最终为 `R`，不会因为第 `i` 天形成 `RS`。

最后如果选择的最终天气不同于原天气，就减去翻转费用 `X_i`。

时间复杂度：`O(N)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        string S;
        cin >> N >> S;

        vector<ll> X(N), Y(N - 1);
        for (ll &v : X) cin >> v;
        for (ll &v : Y) cin >> v;

        ll dpS = (S[0] == 'S' ? 0 : -X[0]);
        ll dpR = (S[0] == 'R' ? 0 : -X[0]);

        for (int i = 1; i < N; i++) {
            ll ndpS = max(dpS, dpR + Y[i - 1]);
            ll ndpR = max(dpS, dpR);

            if (S[i] == 'S') ndpR -= X[i];
            else ndpS -= X[i];

            dpS = ndpS;
            dpR = ndpR;
        }

        cout << max(dpS, dpR) << '\n';
    }

    return 0;
}
```

## 样例验证

代码枚举每一天最终天气，并只维护前一天状态。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
