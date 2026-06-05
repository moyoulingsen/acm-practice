// #include <bits/stdc++.h>
// using namespace std;

// #define ull unsigned long long
// #define int long long
// #define pii array<int, 2>
// #define endl "\n"
// #define rep(i, a, b) for (int i = (a); i < (b); ++i)
// struct Node{
//     int sum;
//     int lmmax;
//     int rmmax;
//     int mx;
// };

// vector<int> arr,lazy;
// vector<Node> tree;

// Node merge(Node a,Node b){
//     Node ans;
//     ans.sum = a.sum+b.sum;
//     ans.lmmax = max(a.lmmax,a.sum+b.lmmax);
//     ans.rmmax = max(b.rmmax,a.rmmax+b.sum);
//     // ans.mx = max({ans.lmmax,ans.rmmax,a.rmmax+b.lmmax});
//     ans.mx = max({a.mx,b.mx,a.rmmax+b.lmmax});
//     return ans;
// }

// void build_tree(int s, int t, int p) {
//     if (s == t) {
//         int x= arr[s];
//         tree[p] = {x,x,x,x};
//         return;
//     }
//     int mid = s + ((t - s) >> 1);
//     build_tree(s, mid, p << 1);
//     build_tree(mid + 1, t, p << 1 | 1);
//     tree[p] = merge(tree[p << 1] , tree[p << 1 | 1]);
// }

// Node inquiry(int l, int r, int s, int t, int p) {
//     int mmax  =LLONG_MIN;
//     if (l <= s && r >= t) {
//         return max(tree[p].mx,mmax);
//     }
//     int mid = s + ((t - s) >> 1);
//     if (lazy[p]) {
//         lazy[p << 1] = lazy[p];
//         lazy[p << 1 | 1] = lazy[p];
//         int x,y;
//         x = lazy[p] * (mid - s + 1);
//         y = lazy[p] * (t - mid);
//         tree[p << 1] = {x,x,x,x};
//         tree[p << 1 | 1] = {y,y,y,y};
//         lazy[p] = 0;
//     }
    
//     if (l <= mid) {
//         mmax =max(mmax,inquiry(l, r, s, mid, p << 1).mx);
//     }
//     if (r > mid) {
//         mmax =max(mmax,inquiry(l, r, mid+1, t, (p << 1)+1).mx);
//     }
//     return mmax;
// }

// void change(int l, int r, int s, int t, int c, int p) {
//     if (l <= s && r >= t) {
//         int x = (t - s + 1) * c;
//         tree[p] = {x,x,x,x};
//         lazy[p] = c;
//         return;
//     }
//     int mid = s + ((t - s) >> 1);
//     if (lazy[p]) {
//         lazy[p << 1] = lazy[p];
//         lazy[p << 1 | 1] = lazy[p];
//         int x,y;
//         x = lazy[p] * (mid - s + 1);
//         y = lazy[p] * (t - mid);
//         tree[p << 1] = {x,x,x,x};
//         tree[p << 1 | 1] = {y,y,y,y};
//         lazy[p] = 0;
//     }
//     if (l <= mid) {
//         change(l, r, s, mid, c, p << 1);
//     }
//     if (r > mid) {
//         change(l, r, mid + 1, t, c, p << 1 | 1);
//     }
//     tree[p] = merge(tree[p << 1] , tree[p << 1 | 1]);
// }

// void solve() {
//     int n,m;
//     cin>>n>>m;
    
//     arr.resize(n+1);
//     tree.resize(4*n);
//     lazy.resize(4*n);

//     rep(i,1,n+1){
//         cin>>arr[i];
//     }
//     build_tree(1, n, 1);

//     while(m--){
//         int k;cin>>k;
//         if(k==1){
//             int a,b;cin>>a>>b;
//             if(a>b)swap(a,b);
//             cout<<inquiry(a,b,1,n,1).mx<<endl;

//         }
//         else{
//             int a,b;cin>>a>>b;
//             change(a,a,1,n,b,1);
//         }
//     }

// }

// signed main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int t = 1;
//     //cin >> t;
//     for (int i = 0; i < t; i++) {
//         solve();
//     }
//     return 0;
// }

//就是错的。懒人标记适用于区间修改，单点修改不需要。



#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

struct Node{
    int lx;
    int rx;
    int sum;
    int mx;
};
vector<int> arr;
vector<Node> tree;

Node merge(Node a,Node b){
    Node ans;
    // ans.lx = max(a.lx,a.sum+a.rx);
    // ans.lx = max(a.lx,a.sum+b.rx);
    ans.lx = max(a.lx,a.sum+b.lx);
    ans.rx = max(b.rx,b.sum+a.rx);
    ans.sum = a.sum+b.sum;
    // ans.mx = max({a.mx,b.mx,a.lx+b.rx}); 
    ans.mx = max({a.mx,b.mx,a.rx+b.lx}); 
    return ans;
} 

void build_tree(int s,int t,int p){
    if(s==t){
        int x = arr[s];
        // tree[s] = {x,x,x,x};
         tree[p] = {x,x,x,x};
        return;
    }
    int mid = s+((t-s)>>1);
    build_tree(s,mid,p<<1),build_tree(mid+1,t,(p<<1)+1);
    tree[p] = merge(tree[p<<1],tree[(p<<1)+1]);
}

void change(int pos,int s,int t ,int c,int p){
    if(s==t){
        // tree[s] = {c,c,c,c};
        tree[p] = {c,c,c,c};
        return;
    }
    int mid = s+((t-s)>>1);
    if(pos<=mid&&pos>=s){
        change(pos,s,mid,c,p<<1);
    }
    if(pos<=t&&pos>mid){
        change(pos,mid+1,t,c,(p<<1)+1);
    }
    tree[p] = merge(tree[p<<1], tree[p<<1|1]);
    //之前处理了子叶，怎么父叶一个也不管了
}

Node find(int l,int r,int s,int t,int p){
    if(l<=s&&r>=t){
        return tree[p];
    }
    int mid = s+((t-s)>>1);
   
    if(r<=mid){
        // merge(mmax,find(l,r,s,mid,p<<1));
        return find(l,r,s,mid,p<<1);
    }
    if(l>mid){
        return find(l,r,mid+1,t,(p<<1)+1);
    }
    return merge((find(l,r,s,mid,p<<1)),(find(l,r,mid+1,t,(p<<1)+1)));
}

void solve() {
    int n,m;cin>>n>>m;
    // arr.resize(n);
    arr.resize(n+1);
    tree.resize(4*n);

    rep(i,1,n+1){
        cin>>arr[i];
    }
    
    build_tree(1,n,1);

    while(m--){
        // int n;cin>>n;
        // if(n==1){
        //不要修你的语法了，下面有n,直接覆盖
        int k;cin>>k;
        if(k==1){
          
            int a,b;cin>>a>>b;
            if(a>b)swap(a,b);
            cout<<find(a,b,1,n,1).mx<<endl;
        }
        else{
            int p,s;
            cin>>p>>s;
            change(p,1,n,s,1);
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

// 所以线段树查询牢记这个模板：
// if(完全覆盖) return tree[p];
// if(查询区间完全在左边) return 查左边;
// if(查询区间完全在右边) return 查右边;
// 否则 return merge(查左边, 查右边);