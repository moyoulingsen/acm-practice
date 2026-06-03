#include<bits/stdc++.h>
using namespace std;
const int dir[8][2]={{1,2},{1,-2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,1},{-2,-1}};
bool d[30][30];
long long dp[30][30],n,m,cx,cy;
int main(){
    cin>>n>>m>>cx>>cy;
    d[cx][cy]=true;
    for(int i=0;i<8;i++){
        int tx=cx+dir[i][0],ty=cy+dir[i][1];
        if(tx>=0&&tx<=n&&ty>=0&&ty<=m) d[tx][ty]=true; //这里防止马越界
    }
    dp[0][0]=1;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(d[i][j]==false){
                if(i) dp[i][j]+=dp[i-1][j];
                if(j) dp[i][j]+=dp[i][j-1];             //这里用if防止grid里面的点越界
            }
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}
