bool isvalid(int n,int m,int nx,int ny,vector<vector<int>> &visited){ 
    if(nx>=0&& ny>=0&&nx <n &&ny <m&&!visited[nx][ny])return true;//小细节&&有两个
    else return false;
}

int dx[4] ={0,1,0,-1};
int dy[4] ={1,0,-1,0};

class Solution {
    


public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n =matrix.size();int m = matrix[0].size();  
    vector <vector<int >> visited(n,vector (m,0));
    vector<int> ans;
    
    int x=0,y=0,dir=0;
    int nx,ny ;

    for (int i=0;i<n*m;i++){//记录有这么多次操作
        ans.push_back(matrix[x][y]);
        visited[x][y] = 1; 

        nx = x + dx[dir];
        ny = y + dy[dir];                         //先假设状态转移，

        if(!isvalid(n,m,nx,ny,visited)){
            dir = (dir + 1) % 4;
            nx = x + dx[dir];
            ny = y + dy[dir];
        }
        x= nx;
        y= ny;
    }
    return ans;
        
    }
};