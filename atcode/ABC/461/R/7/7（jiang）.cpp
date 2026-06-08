#include<bits/stdc++.h>
using namespace std;
struct dn
{
    struct ed{int to,ev,cp;};
    vector<vector<ed>>g;
    vector<int>dj,ir;
    dn(int n):g(n),dj(n),ir(n){}
    void je(int ks,int to,int cp)
    {
        g[ks].push_back({to,(int)g[to].size(),cp});
        g[to].push_back({ks,(int)g[ks].size()-1,0});
    }
    void ss(int s)
    {
        fill(dj.begin(),dj.end(),-1);
        queue<int>q;
        dj[s]=0;
        q.push(s);
        while(!q.empty())
        {
            int v=q.front();q.pop();
            for(auto&e:g[v])
            {
                if(e.cp>0&&dj[e.to]<0)
                {
                    dj[e.to]=dj[v]+1;
                    q.push(e.to);
                }
            }
        }
    }
    int sd(int v,int t,int f)
    {
        if(v==t) return f;
        for(int&i=ir[v];i<(int)g[v].size();++i)
        {
            ed&e=g[v][i];
            if(e.cp>0&&dj[v]<dj[e.to])
            {
                int d=sd(e.to,t,min(f,e.cp));
                if(d>0)
                {
                    e.cp-=d;
                    g[e.to][e.ev].cp+=d;
                    return d;
                }
            }
        }
        return 0;
    }
    int mf(int s,int t)
    {
        int fw=0;
        while(1)
        {
            ss(s);
            if(dj[t]<0) return fw;
            fill(ir.begin(),ir.end(),0);
            int f;
            while((f=sd(s,t,INT_MAX))>0) fw+=f;
        }
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,M;
    cin>>N>>M;
    int S=0,T=2*N+1;
    dn dc(T+1);
    for(int i=1;i<=N;++i)
    {
        dc.je(S,i,1);
        dc.je(N+i,T,1);
    }
    for(int i=0;i<M;++i)
    {
        int u,v;
        cin>>u>>v;
        dc.je(u,N+v,1);
        dc.je(v,N+u,1);
    }
    int bs=dc.mf(S,T);
    long long da=2026LL*N-1013LL*bs;
    cout<<da<<"\n";
    return 0;
}