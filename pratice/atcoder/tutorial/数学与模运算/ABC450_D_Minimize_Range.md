# ABC450 D - Minimize Range

## 网址

https://atcoder.jp/contests/abc450/tasks/abc450_d

## 题解

每个数对 `K` 取模的余数不会变。问题等价于在模 `K` 的圆环上，把所有余数放进一个尽可能短的连续区间。

如果把圆环上最大的空隙切开，那么剩下所有点所在的区间最短。所以答案是：

```text
K - 最大相邻余数间隔
```

相邻间隔包括首尾之间跨过 `K` 的环形间隔。

时间复杂度：`O(N log N)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long K;
    cin >> N >> K;

    vector<long long> r(N);
    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        r[i] = x % K;
    }

    sort(r.begin(), r.end());

    long long gap = r[0] + K - r.back();
    for (int i = 0; i + 1 < N; i++) gap = max(gap, r[i + 1] - r[i]);

    cout << K - gap << '\n';
    return 0;
}
```

## 样例验证

代码使用模圆环最大空隙结论。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
