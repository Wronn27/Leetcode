class Solution {
public:
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    void bfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& vis,int m,int n){
        queue<pair<int,int>> qu;
        qu.push({i,j});
        while(!qu.empty()){
            pair<int,int> p=qu.front();
            qu.pop();
            for(int d=0;d<4;d++){
                int nx=p.first+dir[d][0];
                int ny=p.second+dir[d][1];

                if(nx<0 || ny>=n || ny<0 || nx>=m || vis[nx][ny]==1 || grid[nx][ny]=='0')
                continue;

                qu.push({nx,ny});
                vis[nx][ny]=1; 
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size(),count=0;
        vector<vector<int>> vis(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && vis[i][j]!=1)
                {
                    count++;
                    vis[i][j]=1;
                    bfs(i,j,grid,vis,m,n);
                }
            }
        }
        return count;
    }
};