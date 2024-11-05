class Solution {
public:
//  memoization method 
    int row,col;
    vector<vector<int>>dp;
    int maxMoves(vector<vector<int>>& grid) {
        
        row=grid.size();
        col=grid[0].size();
        int ans=0;
        dp.resize(row, vector<int>(col, -1));

        for(int i=0;i<row;i++){
            int maxi=fn(grid,i,0);
            ans=max(ans,maxi);
            if(ans==col-1) return ans;
        }

        return ans;
    }

    int fn(vector<vector<int>>&grid, int r,int c){

        if(r<0 || r>=row || c>=col) return 0;
        
        if(dp[r][c]!=-1) return dp[r][c];

        int rcc=0 , rrcc=0, cc=0;
        if(c+1<col && grid[r][c+1]>grid[r][c]) 
            rcc=fn(grid,r,c+1)+1;
        if(r+1 < row && c+1<col && grid[r+1][c+1]>grid[r][c]) 
            rrcc=fn(grid,r+1,c+1)+1;
        if(r-1>=0 && c+1 <col && grid[r-1][c+1]>grid[r][c]) 
            cc=fn(grid,r-1,c+1)+1;

        return dp[r][c]=max({rcc,rrcc,cc});
    }
};