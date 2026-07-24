#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve()
{

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

// D1. Unique Values (Easy version)
// time limit per test2 seconds
// memory limit per test256 megabytes
// The difference between the easy version and hard version is the maximum number of queries allowed. In this version, it is 66.

// There is a secret array a
//  of length 2n+1
// , whose elements are integers from 1
//  to n
// . Each value appears exactly twice, except for one value, which appears exactly three times.

// Your goal is to find the three positions of the value that appears three times.

// To do this, you may ask the following query at most 66 times:

// Choose an integer k
//  and an array s
//  of k
//  distinct indices between 1
//  and 2n+1
// .
// You will receive the number of different values among as1,as2,…,ask
//  that appear exactly once, or, in other words, the count of values that are not repeated.
// For example, if the values as1,…,ask
//  are {2,1,2,3,2,3,6,7}
// , the answer to the query will be 3, as 1, 6, 7 are the only values that appear exactly once. 3 appears 2 times and 2 appears 3 times, which is more than once, so they are not counted.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t
//  (1≤t≤500
// ). The description of the test cases follows.

// The first line of each test case contains a single integer n
//  (2≤n≤1000
// ).

// The array a
//  is fixed for the test case and does not change during the interaction. In other words, the interactor is not adaptive.

// It is guaranteed that the sum of n
//  over all test cases does not exceed 2⋅104
// .

// Interaction
// For each test case, first read a single integer n
// .

// You may ask up to 66
//  queries in each test case.

// To ask a query, print a line in the format:

// ? k
//  s1
//  s2
//  …
//  sk
//  (si≠sj
//  for i≠j
// , 1≤si≤2⋅n+1
// )
// As a response to the query, you will receive the number of different values among as1,as2,…,ask
//  that appear exactly once, or in other words, the count of values that are not repeated.

// If your program makes more than 66
//  queries for one test case, or makes an invalid query, then the response to the query will be −1
// . After receiving such a response, your program should immediately terminate to receive the verdict Wrong Answer. Otherwise, it may receive any other verdict.

// When you determine the answer for the current test case, print

// ! x
//  y
//  z
// where x,y,z
//  are the distinct three indices of the value that appears three times in a
// . You can print indices in any order.

// Note that this output does not count towards the query limit of 66
// .

// After that, proceed to the next test case or terminate your program if there are no more test cases.

// After printing each query, do not forget to output the end of line and flush* the output. Otherwise, you will get the Idleness limit exceeded verdict.

// If, at any interaction step, you read −1
//  instead of valid data, your solution must exit immediately. This means that your solution will receive Wrong Answer because of an invalid query or any other mistake. Failing to exit can result in an arbitrary verdict because your solution will continue to read from a closed stream.

// Note that the interactor is not adaptive, which means that a
//  is unchanged throughout the interaction.

// Hacks

// To make a hack, use the following format.

// The first line should contain a single integer t
//  (1≤t≤500)
// , the number of test cases.

// The first line of each test case should contain n
//  (2≤n≤1000)
// .

// The second line of each test case should contain an array of length 2⋅n+1
// , the array a
// , which should fulfill the constraints of the problem.

// The sum of n
//  over all test cases should not exceed 2⋅104
// .

// Example
// InputCopy
// 1
// 2

// 0

// 2

// 2

// 0

// 1
// OutputCopy

// ? 2 1 2

// ? 2 1 4

// ? 2 1 5

// ? 5 1 2 3 4 5

// ? 4 1 2 3 4

// ! 1 2 3
// Note
// The secret array is a=[1,1,1,2,2]
// .

// In the first query, we ask for the number of values that appear exactly once in [a1,a2]=[1,1]
// , since value 1 is repeated, the answer is 0.

// In the second query, we ask for the number of values that appear exactly once in [a1,a4]=[1,2]
// , since values 1 and 2 appear exactly once, the answer is 2.

// In the fourth query, we ask for the number of values that appear exactly once in [a1,a2,a3,a4,a5]=[1,1,1,2,2]
// , since values 1 and 2 are repeated, the answer is 0.

// At the end, we print that the indices of the value repeated three times are 1, 2 and 3.









// 中文翻译

// 有一个秘密数组 a，长度是 2n+1，其中每个元素的值都在 1..n 之间。

// 这个数组满足：

// 有且只有一个值出现了 3 次
// 其他每个值都出现了 2 次
// 你的任务是找出那个“出现 3 次的值”所在的 三个位置。

// 你最多可以询问 66 次，每次询问方法如下：

// 你选择一个整数 k
// 再选择 k 个互不相同的下标 s1, s2, ..., sk
// 交互器会返回：在 a[s1], a[s2], ..., a[sk] 这些数中，恰好出现一次 的不同数值有多少个
// 举个例子：

// 如果你选出来的值是：

// {2,1,2,3,2,3,6,7}
// 那么答案是 3，因为：

// 1 只出现了 1 次
// 6 只出现了 1 次
// 7 只出现了 1 次
// 而：

// 3 出现了 2 次，不算
// 2 出现了 3 次，也不算
// 你的目标是在不超过 66 次询问的前提下，输出那个出现三次的值对应的三个位置。