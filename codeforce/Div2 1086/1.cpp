#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    while (n--)
    {
        int m,k;
        cin >> m;
        k=m;
        vector<int> arr(10005);
        while (k--)
        {
            for (int i = 0; i < m; i++)
            {
                {
                    int a;
                    cin >> a;
                    arr[a]++;
                }
            }
            
        }
        auto it = max_element(arr.begin(), arr.end());
            if (*it <= m * m - m)
            {
                cout << "YES" << '\n';
            }
            else cout<<"NO"<<'\n';
    }

    return 0;
}