# ABC467 A - Obesity

## 网址

https://atcoder.jp/contests/abc467/tasks/abc467_a

## 题解

BMI 的定义是：

```text
BMI = W / (H / 100)^2
```

其中 `H` 是厘米，`W` 是千克。题目要求判断 BMI 是否不小于 `25`。

为了避免浮点误差，把不等式变成整数比较：

```text
W / (H / 100)^2 >= 25
<=> 10000W >= 25H^2
```

所以直接判断 `10000 * W >= 25 * H * H` 即可。

时间复杂度：`O(1)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long H, W;
    cin >> H >> W;

    cout << (10000LL * W >= 25LL * H * H ? "Yes" : "No") << '\n';
    return 0;
}
```

## 样例验证

代码只做整数乘法比较，可以避免 `H / 100` 带来的浮点精度问题。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
