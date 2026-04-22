#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve()
{
    string n, m;
    cin >> n >> m;
    stack<char> st;
    for (char c : n)
    {
        if (c == 'x' || c == '(')
            st.push(c);
        else
        {
            if (st.empty() || st.top() == '(' || st.top() == ')')
                st.push(c);
            else
            {
                st.pop();
                if (st.empty() || st.top() == '(' || st.top() == ')')
                {
                    st.push('x');
                    st.push(')');
                }
                else
                {
                    st.pop();
                    if (st.empty() || st.top() == 'x' || st.top() == ')')
                    {
                        st.push('x');
                        st.push('x');
                        st.push(')');
                    }
                    else
                    {
                        st.pop();
                        st.push('x');
                        st.push('x');
                    }
                }
            }
        }
    }
    stack<char> st1;
    for (char c : m)
    {
        if (c == 'x' || c == '(')
            st1.push(c);
        else
        {
            if (st1.empty() || st1.top() == '(' || st1.top() == ')')
                st1.push(c);
            else
            {
                st1.pop();
                if (st1.empty() || st1.top() == '(' || st1.top() == ')')
                {
                    st1.push('x');
                    st1.push(')');
                }
                else
                {
                    st1.pop();
                    if (st1.empty() || st1.top() == 'x' || st1.top() == ')')
                    {
                        st1.push('x');
                        st1.push('x');
                        st1.push(')');
                    }
                    else
                    {
                        st1.pop();
                        st1.push('x');
                        st1.push('x');
                    }
                }
            }
        }
    }
    string a ="";
    string b = "";
    while(!st.empty()){
        a+=st.top();
        st.pop();
    }
    while(!st1.empty()){
        b+=st1.top();
        st1.pop();
    }
    if(a==b)cout<<"Yes\n";
    else cout<<"No\n";
    
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