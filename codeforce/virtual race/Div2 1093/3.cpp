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

    int s = n + m * 2;
    int sum = 2 * s + 1;

    for (int i = 1; i * i <= sum; i++)
    {
        if (sum % i == 0)
        {
            int x = i;
            int y = sum / i;

            int nx = (x - 1) / 2;
            int ny = (y - 1) / 2;

            if (x - 1 > 0 && (x - 1) % 2 == 0 && y - 1 > 0 && (y - 1) % 2 == 0)
            {
                if (m <= min(nx * (ny + 1), ny * (nx + 1)))
                {

                    cout << nx << " " << ny << endl;
                    return;
                }
            }
        }
    }
    cout << "-1" << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}