#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

vector<int> arr, tree, lazy;

void build_tree(int s, int t, int p) {
    tree[p] = 1;
    lazy[p] = 1;
    if (s == t) {
        return;
    }
//怎么初始化
//这道题目树的初始状态就是00001，不是赋值

    int mid = s + ((t - s) >> 1);
    build_tree(s, mid, p << 1);
    build_tree(mid + 1, t, p << 1 | 1);
    tree[p] = tree[p << 1] | tree[p << 1 | 1];
//怎么合并；
//这道题目的合并操作是 位运算集合

}

int inquiry(int l, int r, int s, int t, int p) {
    if (l <= s && r >= t) {
        return tree[p];
    }
    int mid = s + ((t - s) >> 1);
    if (lazy[p]) {
        lazy[p << 1] = lazy[p];
        lazy[p << 1 | 1] = lazy[p];
        tree[p << 1] = lazy[p];
        tree[p << 1 | 1] = lazy[p] ;
        lazy[p] = 0;
    }
    int sum = 0;
    if (l <= mid) {
        sum |= inquiry(l, r, s, mid, p << 1);
    }
    if (r > mid) {
        sum |= inquiry(l, r, mid + 1, t, p << 1 | 1);
    }
    return sum;
//怎么合并；
//这道题目的合并操作是 位运算集合

}

void change(int l, int r, int s, int t, int c, int p) {
    if (l <= s && r >= t) {
        tree[p] =1LL<<(c-1);
        lazy[p] =1LL<<(c-1);
        return;
    }
    //怎么修改
    //本题就是赋值修改覆盖

    int mid = s + ((t - s) >> 1);
    if (lazy[p]) {
        lazy[p << 1] = lazy[p];
        lazy[p << 1 | 1] = lazy[p];
        tree[p << 1] = lazy[p] ;
        tree[p << 1 | 1] = lazy[p] ;
        lazy[p] = 0;
    }
    //怎么转移，就是把懒人标记下移干什么
    //本题就是lazy覆盖子树

    if (l <= mid) {
        change(l, r, s, mid, c, p << 1);
    }
    if (r > mid) {
        change(l, r, mid + 1, t, c, p << 1 | 1);
    }
    tree[p] = tree[p << 1] | tree[p << 1 | 1];
}

void solve() {
    int n,m,t;
    cin>>n>>m>>t;
    
   
    tree.resize(4*n+5);
    lazy.resize(4*n+5);

    // arr.resize(n+1);
    // rep(i,1,n+1){
    //     cin>>arr[i];
    // }
//有的时候是不需要的哦

    build_tree(1,n,1);
    
    while(t--){
        char x;cin>>x;

        if(x=='C'){
            int a,b,c;
            cin>>a>>b>>c;
            if(a>b)swap(a,b);
            change(a,b,1,n,c,1);

        }
        else{
            int a,b;
            cin>>a>>b;
            if(a>b)swap(a,b);
            cout<<__builtin_popcountll(inquiry(a,b,1,n,1))<<endl;
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