#include <bits/stdc++.h>

#if __has_include("tool/local.hpp")
    #include "tool/local.hpp"
#else
    #define debug(...) 42
#endif

using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using f80 = long double;
using pii = pair<int, int>;
using pll = pair<i64, i64>;

constexpr int INF = 1e9 + 7;
constexpr i64 INF64 = 4e18;

struct Node{int x,step;};
queue<Node> q;

int arr[205];
int ans[205];

int bfs(int N,int a,int b){
    q.push({a,0});
    ans[a] = 0;
    if (a==b)return 0;
    while (!q.empty()){
        int a1 ,a2 ;
        Node p = q.front();
        q.pop();
        
        int len = arr[p.x-1];

        a1 = p.x + len;//这里数组下标混乱赋值了垃圾值
                       //楼层和下表永远的1
        if (a1 == b)
        return p.step+1;

        if (a1>0 && a1<=N && ans[a1]==-1){
            
            ans[a1] = p.step+1 ;
            q.push({a1,ans[a1]});
        }

        a2 = p.x - len;
        if(a2 == b) return p.step+1;
        if (a2>0 && a2<=N && ans[a2]==-1){
            
            ans[a2] = p.step+1;
            q.push({a2,ans[a2]});
        }
    
    }
    return -1;
}

void solve() {

    int  N,A,B;
    
    cin >> N>>A>>B;
    for (int i =0 ;i<N;i++){
        cin>>arr[i];
    }
    memset(ans,-1,sizeof(ans));
    
    cout << bfs(N,A,B);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        (void)!freopen("data.in", "r", stdin);
        (void)!freopen("data.out", "w", stdout);
    #endif

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}