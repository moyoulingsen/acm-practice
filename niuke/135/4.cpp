#include <bits/stdc++.h>
using namespace std;

typedef long long ll;  

void f (int n,set<int> &s){
    int ans = 0;
        while(s.count(s.begin(),s.end(),*s.begin())!=n)
        if ( *s.begin()+1<=*s.rbegin()){
            *s.begin()+1;
            *s.rbegin()-1;
            ans++;
        }
        else {ans+=(*s.count(s.begin(),s.end(),*s.begin()));
        cout<< ans<<"\n";return ;}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        multiset<int> s;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            s.insert(a);
        }
        
        f(n,s);
    }

    return 0;
}