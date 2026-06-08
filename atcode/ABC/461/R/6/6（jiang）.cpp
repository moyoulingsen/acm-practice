#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int main(){
    long long n;
    cin>>n;
    vector<long long> p;
    vector<int> e;
    long long t=n;
    for(long long i=2;i*i<=t;++i){
        if(t%i==0){
            int c=0;
            while(t%i==0){
                t/=i;
                ++c;
            }
            p.push_back(i);
            e.push_back(c);
        }
    }
    if(t>1){
        p.push_back(t);
        e.push_back(1);
    }
    vector<long long> d;
    function<void(int,long long)> f=[&](int i,long long v){
        if(i==(int)p.size()){
            d.push_back(v);
            return;
        }
        long long x=p[i];
        int c=e[i];
        long long m=1;
        for(int j=0;j<=c;++j){
            f(i+1,v*m);
            m*=x;
        }
    };
    f(0,1);
    sort(d.begin(),d.end());
    int s=d.size();
    unordered_map<long long,int> id;
    for(int i=0;i<s;++i) id[d[i]]=i;
    int k=0;
    for(int c:e) k+=c;
    int l=k+1;
    vector<vector<pair<int,int>>> g(s);
    for(int i=0;i<s;++i){
        long long vi=d[i];
        long long rn=n/vi;
        for(int j=0;j<s;++j){
            long long vj=d[j];
            if(vj>rn) break;
            if(rn%vj==0){
                long long w=vj*vi;
                int to=id[w];
                g[i].emplace_back(j,to);
            }
        }
    }
    vector<vector<long long>> c(s,vector<long long>(l+1,0));
    vector<vector<long long>> h(s,vector<long long>(l+1,0));
    c[0][0]=1;
    for(int i=0;i<s;++i){
        long long vm=d[i]%M;
        const auto& list=g[i];
        for(int L=l-1;L>=0;--L){
            for(auto& pr:list){
                int r=pr.first;
                int to=pr.second;
                long long cnt=c[r][L];
                if(cnt==0) continue;
                long long sum=h[r][L];
                c[to][L+1]=(c[to][L+1]+cnt)%M;
                h[to][L+1]=(h[to][L+1]+sum+cnt*vm)%M;
            }
        }
    }
    vector<long long> fac(l+1);
    fac[0]=1;
    for(int i=1;i<=l;++i) fac[i]=fac[i-1]*i%M;
    long long ans=0;
    int tg=s-1;
    for(int L=1;L<=l;++L) ans=(ans+fac[L]*h[tg][L])%M;
    cout<<ans<<endl;
    return 0;
}