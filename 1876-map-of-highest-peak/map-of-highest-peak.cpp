class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        
        int n=isWater.size() , m=isWater[0].size();
        vector<vector<int>>mat(n,vector<int>(m,-1));

        queue<pair<int,pair<int,int>>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    q.push({0,{i,j}});
                    mat[i][j]=0;
                 }  
            }
        }

        while(!q.empty()){
            int size=q.size();

            for(int i=0;i<size;i++){
                int ht=q.front().first;
                int r=q.front().second.first;
                int c=q.front().second.second;
                mat[r][c]=ht;
                q.pop();

                if(r+1<n and mat[r+1][c]==-1){
                    q.push({ht+1,{r+1,c}});
                    mat[r+1][c]=ht+1;
                }
                if(c+1<m and mat[r][c+1]==-1){
                    q.push({ht+1,{r,c+1}});
                    mat[r][c+1]=ht+1;
                }
                if(r-1>=0 and mat[r-1][c]==-1){
                    q.push({ht+1,{r-1,c}});
                    mat[r-1][c]=ht+1;
                }
                if(c-1>=0 and mat[r][c-1]==-1){
                    q.push({ht+1,{r,c-1}});
                    mat[r][c-1]=ht+1;
                }

            }
        }
        return mat;
    }
};