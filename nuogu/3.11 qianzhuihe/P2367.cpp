/*语文考试结束了，成绩还是一如既往地有问题。

题目描述
语文老师总是写错成绩，所以当她修改成绩的时候，总是累得不行。她总是要一遍遍地给某些同学增加分数，又要注意最低分是多少。你能帮帮她吗？

输入格式
第一行有两个整数 n，p，代表学生数与增加分数的次数。

第二行有 n 个数，a
1
​
 ∼a
n
​
 ，代表各个学生的初始成绩。

接下来 p 行，每行有三个数，x，y，z，代表给第 x 个到第 y 个学生每人增加 z 分。

输出格式
输出仅一行，代表更改分数后，全班的最低分。

输入输出样例
输入 #1复制

3 2
1 1 1
1 2 1
2 3 1
输出 #1复制

2*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p;
    cin >> n >> p;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<int> d(n + 2);
    a[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        d[i] = a[i] - a[i - 1];
    }

    while (p--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        d[x] += z;
        d[y + 1] -= z;
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] = a[i - 1] + d[i];
    } // 这里不提出来，相当于没有提啊
    auto it = min_element(a.begin() + 1, a.end());
    cout << *it;

    return 0;
}