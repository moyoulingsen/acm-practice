#include <bits/stdc++.h>
using namespace std;

typedef long long ll;  

int fx[8]={1,1,2,2,-1,-1,-2,-2};
int fy[8]={-2,2,-1,1,2,-2,1,-1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b,m,n;
    cin>>a>>b>>m>>n;
    

    a +=2;
    b +=2;
    m +=2;
    n +=2;
    vector<vector<ll>> grid(a+3,vector<ll> (b+3,0));
    vector<vector<ll>> isvilid(a+3,vector<ll> (b+3,0));//你就说这些防止越界妙不妙
    for(int i = 0;i<8;i++){
        isvilid[m+fx[i]][n+fy[i]] = 1;
    }
    
    grid[2][2]=1;
    isvilid[2][2]=1;
    isvilid[m][n]=1;
    for (int i = 2;i<=a+2;i++){
        for(int j = 2;j<=b+2;j++){
            if (!isvilid[i][j]){
                grid[i][j] = grid[i-1][j]+grid[i][j-1];
            }
        }
    }
   cout << grid[a][b];

    

    return 0;
}