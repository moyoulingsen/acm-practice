# ABC467 B - Keep the Change

## 网址

https://atcoder.jp/contests/abc467/tasks/abc467_b

## 题解

每次购物时，商品价格是 `A_i`，支付金额是 `B_i`。如果选择收下找零，就不会损失钱；如果选择不收找零，就会损失：

```text
B_i - A_i
```

因此只需要遍历所有购物记录，把 `S_i = keep` 的 `B_i - A_i` 加起来。

时间复杂度：`O(N)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        long long A, B;
        string S;
        cin >> A >> B >> S;

        if (S == "keep") {
            ans += B - A;
        }
    }

    cout << ans << '\n';
    return 0;
}
```

## 样例验证

代码逐条累加没有收下的找零金额，和题目中“相比每次都收下找零的损失”一致。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
