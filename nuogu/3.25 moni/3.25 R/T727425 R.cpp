#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    map<int, int> m;

    int cnt[5] = {0};
    for (int i = 0; i < 16; i++)
    { ///////////甚至直接全输入也没有问题
        int a;
        cin >> a;
        cnt[a]++;
    }
    ////////////////////////////////数组底层是o（1）
    //////////////////////////////////不像map是o(logn)

    for (int i = 0; i < 5; i++)
    {
        if (cnt[i] == 3)
        {
            cout << i;
            return 0;
        } ////////////////////这样直接程序结束也没有问题
        /////////////////////最好找到了就跳出来
    }

    return 0;
}

/*
看到“小值域计数”就立刻想到数组，而不是 map。
*/