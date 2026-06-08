#include<bits/stdc++.h>
using namespace std;
struct hs 
{
    vector<int>t;
    int n;
    hs(int n):n(n){t.assign(n+1,0);}
    void jh(int i,int d){for(;i<=n;i+=i&-i)t[i]+=d;}
    int js(int i){int s=0;for(;i>0;i-=i&-i)s+=t[i];return s;}
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,Q;
    cin>>N>>Q;
    hs r(Q+2),c(Q+2);
    r.jh(1,N);
    c.jh(1,N);
    vector<int>rv(N+1,1),cv(N+1,1);
    long long da=0;
    for(int t=1;t<=Q;++t)
    {
        int tp,x;
        cin>>tp>>x;
        int nv=t+1;
        if(tp==1)
        {
            int jd=rv[x];
            da+=c.js(nv-1)-c.js(jd-1);
            r.jh(jd,-1);
            r.jh(nv,1);
            rv[x]=nv;
        } 
        else
        {
            int jd=cv[x];
            da+=(N-r.js(nv))-(N-r.js(jd));
            c.jh(jd,-1);
            c.jh(nv,1);
            cv[x]=nv;
        }
        cout<<da<<'\n';
    }
}