class Solution {
public:
    vector<vector<int>> dir={{0,-1},{0,1},{1,0},{-1,0}};

    vector<vector<int>> compute(vector<vector<int>>& grid,int n){
        queue<pair<int,int>> bfs;
        vector<vector<int>> distance(n,vector<int>(n,INT_MAX));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    distance[i][j]=0;
                    bfs.push({i,j});
                }
            }
        }
        while(!bfs.empty()){
            pair<int,int> ind=bfs.front();
            bfs.pop();

            for(int i=0;i<4;i++){
                int nx=ind.first+dir[i][0];
                int ny=ind.second+dir[i][1];

                if(nx>=n || nx<0 || ny>=n || ny<0 || distance[nx][ny]!=INT_MAX)
                continue;

                distance[nx][ny]=distance[ind.first][ind.second]+1;
                bfs.push({nx,ny});
            }
        }
        return distance;
    }

    bool check(int mid,vector<vector<int>>& dist,int n){

        if(dist[0][0]<mid) return false;

        queue<pair<int,int>> qu;
        vector<vector<int>> vis(n,vector<int>(n,0));
        qu.push({0,0});
        vis[0][0]=1;
        while(!qu.empty()){
            auto p=qu.front();
            qu.pop();

            if(p.first==n-1 && p.second==n-1) return true;
            
            for(int i=0;i<4;i++){
                int nx=p.first+dir[i][0];
                int ny=p.second+dir[i][1];

                if(nx>=n || nx<0 || ny>=n || ny<0 || dist[nx][ny]<mid || vis[nx][ny])
                continue;

                qu.push({nx,ny});
                vis[nx][ny]=1;
            }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size(),max_dist=0;
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return 0;

        vector<vector<int>> dist=compute(grid,n);
        
        int max_element=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            max_element=max(max_element,dist[i][j]);
        }

        int l=1,r=max_element,ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid,dist,n)){
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        return ans;
    }
};