#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"

void solve() {
    int n;
    while(cin>>n){
        if(n==0)break;
        
        vector<int> pre(n,-1);///用一个前置数组，优雅的表示路径
        vector<char> cha(n);
        vector<int> vis(n,0);

        queue<int> q;
        q.push(1);
        pre[1] = -1;
        cha[1] = '1';
        vis[1] = 1;
        int end;
        
        while(!q.empty()){
            int cur = q.front();
            q.pop();

            if(cur == 0) {
                end = cur;
                break;
            }

            int r0 = (cur*10)%n;
            if(!vis[r0]){
                q.push(r0);
                pre[r0] = cur;
                cha[r0] = '0';
                vis[r0] = 1; 
            }

            int r1 = (cur*10+1)%n;
             if(!vis[r1]){
                q.push(r1);
                pre[r1] = cur;
                cha[r1] = '1';
                vis[r1] = 1; 
            }
        }

        string ans = "";
        int ten = end;
        while(ten !=-1){
            ans += cha[ten];
            ten = pre[ten];
        }
        reverse(ans.begin(),ans.end());
        cout << ans <<endl; 
        
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