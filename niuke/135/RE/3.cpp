#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n+5);

        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            arr[i] = a;
        }

        if (n == 1 || n >= 4)
        {
            cout << "YES" << '\n';
        }
        else
        {
            if (n == 2 && arr[0] == 1 && arr[1] == 2 || n == 3 && arr[1] == 2)
                cout << "YES" << '\n';
            else
                cout << "NO\n";
        }
    }

    return 0;
}