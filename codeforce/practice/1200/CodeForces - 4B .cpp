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
    vector<pair<int, int>> arr(n);
    int mmax = 0;
    int mmin = 0;

    rep(i, 0, n)
    {
        cin >> arr[i].first >> arr[i].second;
        mmin += arr[i].first;
        mmax += arr[i].second;

        
    }

    if (m > mmax || m < mmin)
    {
        cout << "NO" << endl;
        return;
    }

    int rest = m - mmin;
    vector<int> ans(n);
    rep(i, 0, n)
    {
        ans[i] = min(rest, arr[i].second - arr[i].first) + arr[i].first;
        rest = rest - ans[i] + arr[i].first;
    }

    cout << "YES" << endl;

    rep(i, 0, n)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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

// Tomorrow Peter has a Biology exam. He does not like this subject much, but d days ago he learnt that he would have to take this exam. Peter's strict parents made him prepare for the exam immediately, for this purpose he has to study not less than minTimei and not more than maxTimei hours per each i-th day. Moreover, they warned Peter that a day before the exam they would check how he has followed their instructions.

// So, today is the day when Peter's parents ask him to show the timetable of his preparatory studies. But the boy has counted only the sum of hours sumTime spent him on preparation, and now he wants to know if he can show his parents a timetable sсhedule with d numbers, where each number sсhedulei stands for the time in hours spent by Peter each i-th day on biology studies, and satisfying the limitations imposed by his parents, and at the same time the sum total of all schedulei should equal to sumTime.

// Input
// The first input line contains two integer numbers d, sumTime (1 ≤ d ≤ 30, 0 ≤ sumTime ≤ 240) — the amount of days, during which Peter studied, and the total amount of hours, spent on preparation. Each of the following d lines contains two integer numbers minTimei, maxTimei (0 ≤ minTimei ≤ maxTimei ≤ 8), separated by a space — minimum and maximum amount of hours that Peter could spent in the i-th day.

// Output
// In the first line print YES, and in the second line print d numbers (separated by a space), each of the numbers — amount of hours, spent by Peter on preparation in the corresponding day, if he followed his parents' instructions; or print NO in the unique line. If there are many solutions, print any of them.

// Examples
// Input复制	Output复制
// 1 48
// 5 7
// NO
// Input复制	Output复制
// 2 5
// 0 1
// 3 5
// YES
// 1 4