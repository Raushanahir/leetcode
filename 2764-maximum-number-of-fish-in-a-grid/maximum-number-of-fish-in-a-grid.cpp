class Solution {
public:
    int n,m;
    int dfs(int row, int col,vector<vector<int>>& grid,int maxi,vector<vector<int>>& vis) {

        vis[row][col]=1;
        if(col+1<m && grid[row][col+1]>0 && vis[row][col+1]==0){
            maxi=dfs(row,col+1,grid,maxi+grid[row][col+1],vis);
        }
        if(col-1>=0 && grid[row][col-1]>0 && vis[row][col-1]==0){
            maxi=dfs(row,col-1,grid,maxi+grid[row][col-1],vis);
        }
        if(row+1<n && grid[row+1][col]>0 && vis[row+1][col]==0){
            maxi=dfs(row+1,col,grid,maxi+grid[row+1][col],vis);
        }
        if(row-1>=0 && grid[row-1][col]>0 && vis[row-1][col]==0){
            maxi=dfs(row-1,col,grid,maxi+grid[row-1][col],vis);
        }

        return maxi;

    }
    int findMaxFish(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j]>0 and vis[i][j]==0){
                    vis[i][j]=1;
                    ans = max(ans, dfs(i, j, grid,grid[i][j],vis));
                }
            }
        }
        return ans;
    }
};