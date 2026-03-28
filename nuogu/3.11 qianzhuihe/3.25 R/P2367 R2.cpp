//前缀和本质是拆分与还原
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p;
    cin >> n >> p;

    vector<int> d(n + 2);////////////       原来这里要防止后面最后一个不用减的时候越界
                                   //        n+1,因为前缀和本来就要以1开始好理解
                                   //        n+2，是防止越界
    int prev = 0, x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        d[i] = x- prev;
        prev = x; 
    }///////////////有一点动态空间的味道

    while (p--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        d[x] += z;
        d[y + 1] -= z;/////////////          原来这里要防止后面最后一个不用减的时候越界
    }

int mmin = d[1];
int cur = 0;
    for (int i = 1; i <= n; i++)
    { 
        // prev = d[i]+prev;
        cur+=d[i];
        mmin = min(mmin,cur);
    } 
    
 cout<< mmin;   

    return 0;
}