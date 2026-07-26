# ABC459 A - Hell, World!

## 网址

https://atcoder.jp/contests/abc459/tasks/abc459_a

## 题解

固定字符串为 `HelloWorld`，题目要求删除第 `X` 个字符后输出。把 `X` 转成 `0` 下标，然后直接删除该位置即可。

时间复杂度：`O(1)`。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X;
    cin >> X;

    string s = "HelloWorld";
    s.erase(s.begin() + (X - 1));

    cout << s << '\n';
    return 0;
}
```

## 样例验证

代码只删除固定字符串中的指定位置。当前本地没有保存 AtCoder 样例输入文件，未生成单独的样例运行记录。
