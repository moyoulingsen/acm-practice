#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    if ((n * k) % 2 == 0)
    {
        cout << "Yes" << endl;
        
    }
    else
    {
        if (sum % 2 == 1)
        {
            cout << "yes" << endl;
            
        }
        else
        {
            cout << "no" << endl;
        }
    }
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