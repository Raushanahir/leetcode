class Solution {
public:
    int n,m;
// dfs method for solving this problem
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 and grid[i][j]==1){
                    int k=dfs(i,j,grid,vis);
                    ans=max(k,ans);
                    cout << ans << " ";
                }
            }
        }

        return ans;
    }

    int dfs(int r,int c,vector<vector<int>>&grid,vector<vector<int>>&vis){

        
        int drow[]={1,0,0,-1};
        int dcol[]={0,1,-1,0};
        int ans=1;
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int row=drow[i]+r;
            int col=dcol[i]+c;
            if(row<n && col<m && row>=0 && col>=0 && vis[row][col]==0 && grid[row][col]==1){
                // updating the value of area after traversing the grid;
               ans+=dfs(row,col,grid,vis);
            }
        }
        return ans;
    }
};