#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    rep(i, 0, n)
            cin >>
        arr[i];
    vector<int> dis(m);
    rep(i, 0, m)
            cin >>
        dis[i];

    // rep(i, 0, m)
    // {
    //     int tar = dis[i];
    //     int l = -1;
    //     int r = n;
    //     int find = 0;

    //     while (l + 1 != r)
    //     {
    //         int mid = (l + r) / 2;
    //         if (arr[mid] < tar)
    //             l = mid;
    //         if (arr[mid] > tar)
    //             r = mid;
    //         else
    //         {
    //             cout << mid + 1 << " ";
    //             find = 1;
    //             break;
    //         }
    //     }
    //     if (!find)
    //         cout << -1 << " ";
    // }这里面的二分全是错误理解，必须想清楚收敛的方向。以及答案需要的是条件
    rep(i, 0, m)
    {
        int tar = dis[i];
        int l = -1;
        int r = n;

        while (l + 1 < r)
        {
            int mid = (l + r) / 2;
            if (arr[mid] < tar)
                l = mid;
            else
                r = mid;
        }
        if (arr[r] == tar)
            cout << r + 1 << " ";

        else
            cout << -1 << " ";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}

//////////////////////////想清楚分界点找l，r取什么，再想if里面怎么收敛

// 输入 
// n
// n 个不超过 
// 10
// 9
// 10 
// 9
//   的单调不减的（就是后面的数字不小于前面的数字）非负整数 
// a
// 1
// ,
// a
// 2
// ,
// …
// ,
// a
// n
// a 
// 1
// ​
//  ,a 
// 2
// ​
//  ,…,a 
// n
// ​
//  ，然后进行 
// m
// m 次询问。对于每次询问，给出一个整数 
// q
// q，要求输出这个数字在序列中第一次出现的编号，如果没有找到的话输出 
// −
// 1
// −1 。

// Input
// 第一行 
// 2
// 2 个整数 
// n
// n 和 
// m
// m，表示数字个数和询问次数。

// 第二行 
// n
// n 个整数，表示这些待查询的数字。

// 第三行 
// m
// m 个整数，表示询问这些数字的编号，从 
// 1
// 1 开始编号。

// Output
// 输出一行，
// m
// m 个整数，以空格隔开，表示答案。

// Sample 1
// Input复制	Output复制
// 11 3
// 1 3 3 3 5 7 9 11 13 15 15
// 1 3 6
// 1 2 -1 
// Hint
// 数据保证，
// 1
// ≤
// n
// ≤
// 10
// 6
// 1≤n≤10 
// 6
//  ，
// 0
// ≤
// a
// i
// ,
// q
// ≤
// 10
// 9
// 0≤a 
// i
// ​
//  ,q≤10 
// 9
//  ，
// 1
// ≤
// m
// ≤
// 10
// 5
// 1≤m≤10 
// 5
 

// 本题输入输出量较大，请使用较快的 IO 方式。