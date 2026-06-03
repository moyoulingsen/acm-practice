//搜索

#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int long long
#define pii array<int, 2>
#define endl "\n"

int n,k;
vector<int> col(8);
vector<string> grid(8);
int ans;//只要声明在这里
        //赋值随便放后面

void dfs(int row,int num){
    
    if(num == k) {
        ans++;
        return ;
    }

    if(row == n){
        return;
    }

    if(n-row<k-num){
        return;
    }

    dfs(row+1,num);

    for(int i = 0;i<n;i++){
        if(grid[row][i]=='#'&& !col[i]){
            col[i] = 1;
            dfs(row+1,num+1);
            col[i] = 0;
        }
    }
}


void solve() {
    
   while(cin>>n>>k){
      if (n==-1&&k==-1)return;
      for(int i = 0;i<n;i++){
        cin >> grid[i]; 
      }

      ans = 0;
      dfs(0,0);

      cout<< ans << endl; 
   }

    

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}