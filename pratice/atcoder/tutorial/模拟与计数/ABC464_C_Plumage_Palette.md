# ABC464 C - Plumage Palette

## 网址

https://atcoder.jp/contests/abc464/tasks/abc464_c

## 题解

每只鸟初始颜色为 `A_i`，从第 `D_i` 天开始变成 `B_i`。要求每天有多少种不同颜色。

把每只鸟的变化作为事件挂在日期 `D_i` 上。先统计所有初始颜色的出现次数和不同颜色数 `distinct`，然后按天从 `1` 到 `M` 扫描：

- 颜色 `A_i` 的计数减 `1`，若变成 `0`，不同颜色数减 `1`；
- 颜色 `B_i` 的计数加 `1`，若原来是 `0`，不同颜色数加 `1`。

每天处理完当天事件后输出 `distinct`。

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

    vector<int> cnt(N + 1, 0);
    vector<vector<pair<int, int>>> events(M + 1);
    int distinct = 0;

    for (int i = 0; i < N; i++) {
        int A, D, B;
        cin >> A >> D >> B;

        if (cnt[A] == 0) distinct++;
        cnt[A]++;

        events[D].push_back({A, B});
    }

    for (int day = 1; day <= M; day++) {
        for (auto [from, to] : events[day]) {
            cnt[from]--;
            if (cnt[from] == 0) distinct--;

            if (cnt[to] == 0) distinct++;
            cnt[to]++;
        }

        cout << distinct << '\n';
    }

    return 0;
}
```

## 样例验证

代码用事件按天维护每种颜色数量，并实时维护不同颜色数。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
