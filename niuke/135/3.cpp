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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            arr[i] = a;
        }

        if (n >= 4 || n == 1)
        {
            cout << "YES" << '\n';
        }

        if (n == 3)
        {
            if (arr[0] == 1 && arr[1] == 2 && arr[2] == 3)
            {
                cout << "YES\n";
            }
            else
            {
                if (arr[0] == 3 && arr[1] == 2 && arr[2] == 1){cout << "YES\n";}
                else cout << "NO\n";
            }
        }

        if (n == 2)
        {
            if (arr[0] == 1 && arr[1] == 2)
            {
                cout << "YES\n";
            }
            else
                cout << "NO\n";
        }
    }

    return 0;
}
