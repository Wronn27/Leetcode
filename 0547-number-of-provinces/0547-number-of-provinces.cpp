class Solution {
public:
    void dfs(int V,vector<int>& vis,vector<vector<int>>& connected){
        vis[V]=1;
        for(int i=0;i<connected.size();i++){
            if(connected[V][i]==1 && vis[i]==0)
                dfs(i,vis,connected);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        int V=isConnected.size();
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(vis[i]!=1)
            {
                count++;
                dfs(i,vis,isConnected);
            }
        }   
        return count;
    }
};