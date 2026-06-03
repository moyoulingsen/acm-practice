#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double s, a, b;
    cin >> s >> a >> b;

    double T = s * (3 * b + a) / (b * (b + 3 * a));
    cout << fixed << setprecision(6) << T << endl;

    return 0;
}