#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

vector<int> arr,tree,lazy;//全局建立树，resize（）再赋值
void build_tree(int s,int t,int p){
    if(s==t){
        tree[p] = arr[s];
        return;//递归返回
    }
    else{
        int mid = s+((t-s)>>1);
        build_tree(s,mid,p<<1),build_tree(mid+1,t,p << 1 | 1);
        tree[p] = tree[p<<1]+tree[p << 1 | 1];
    }
}

int inquiry(int l,int r,int s,int t,int p){
    if(l<=s&&r>=t){

        return tree[p];
    }
    int mid = s+((t-s)>>1);//已经需要子树了
    if(lazy[p]){
        lazy[p<<1] += lazy[p];
        lazy[p << 1 | 1] += lazy[p];
        // lazy[p<<1] = lazy[p];
        //不要忘记了可能是再来一个懒人标记
        //lazy[p] =0;

        tree [p<<1] += lazy[p]*(mid - s+1);
        tree [p << 1 | 1] += lazy[p]*(t-mid);
        //要用父节点的懒人标记更新子节点的值。否则如果原来子节点懒人标记有值，结果偏大

        // tree [p << 1 | 1] = tree[p << 1 | 1]+lazy[p << 1 | 1];
        //不就是+=吗



        lazy[p] =0;
        //最后才能清零
    }

    int sum = 0; 
    if(l<=mid){
        sum += inquiry(l,r,s,mid,p<<1);

    }
    if(r>mid){
        sum+= inquiry(l,r,mid+1,t,p << 1 | 1);
    }
    return sum;
}

void change(int l,int r,int s,int t,int c,int p){
//c++不允许没有返回类型的函数
    if(l<=s&&r>=t){
        tree[p]+=(t-s+1)*c;lazy[p]+=c;
        return;
        //别忘记返回啊
    }
    int mid = s+((t-s)>>1);
    if(lazy[p]){
        lazy[p<<1] += lazy[p];
        lazy[p << 1 | 1] += lazy[p];
        tree [p<<1] += lazy[p]*(mid - s+1);
        tree [p << 1 | 1] += lazy[p]*(t-mid);
        lazy[p] =0;
    }

    if(l<=mid){
        change(l,r,s,mid,c,p<<1);
        //<<才是*2，不要忘记了
    }
    if(r>mid){
        change(l,r,mid+1,t,c,p << 1 | 1);
    }
    tree[p] = tree[p<<1]+tree[p << 1 | 1];
}

void solve() {
    int n,m;
    cin>>n>>m;
    
    arr.resize(n+1);
    tree.resize(4*n+5);
    lazy.resize(4*n+5);

    rep(i,1,n+1){
        cin>>arr[i];
        //一定需要1开始的这种
    }
    build_tree(1,n,1);
    
    while(m--){
        int x;cin>>x;

        if(x==1){
            int a,b,c;
            cin>>a>>b>>c;
            change(a,b,1,n,c,1);

        }
        else{
            int a,b;
            cin>>a>>b;
            cout<<inquiry(a,b,1,n,1)<<endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}