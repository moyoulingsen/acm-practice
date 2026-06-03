#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a;
    cin >> b;

    int ans = 1;
    
    stack<int> arr, brr;

    rep(i, 0, n)
    {
        if (a[i] == '(' && b[i] == '(')
        {
            arr.push(1);
            brr.push(1);
        }
        else
        {   
            if (!arr.empty()&&a[i] == ')' && b[i] == '(' && arr.top() == 1)
            {
                arr.pop();
                brr.push(1);
            }
            else
            {
                if (!brr.empty()&&a[i] == '(' && b[i] == ')' && brr.top() == 1)
                {
                    brr.pop();
                    arr.push(1);
                }
                else
                {
                    if (!brr.empty()&&!a.empty()&&a[i] == ')' && b[i] == ')' && brr.top() == 1 && arr.top() == 1)
                    {
                        brr.pop();
                        arr.pop();
                    }

                    else
                    {
                        if (!arr.empty()&&a[i] == '(' && b[i] == ')' && arr.top() == 1)
                        {
                            arr.pop();
                            brr.push(1);
                        }
                        else
                        {
                            if (!brr.empty()&&a[i] == ')' && b[i] == '(' && brr.top() == 1)
                            {
                                brr.pop();
                                arr.push(1);
                            }
                            else{
                                ans = 0;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    if(!arr.empty()||!brr.empty()){
        ans = 0;
    }

    cout<<(ans==1?"Yes\n":"No\n");
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