class Solution {
public:
    int minTimeToReach(vector<vector<int>>& move) {
        
        int n=move.size();
        int m=move[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        vector<vector<int>>vis(n,vector<int>(m,0));

        vis[0][0]=1;
        
        while(!pq.empty()){
            auto it = pq.top();
            int time=it.first;
            int r=it.second.first;
            int c=it.second.second;
            pq.pop();

            if(r==n-1 and c==m-1) return time;
            int drow[4]={1,-1,0,0};
            int dcol[4]={0,0,-1,1};

            for(int i=0;i<4;i++){
                    int row=r+drow[i];
                    int col=c+dcol[i];
                    if(row<n and row>=0 and col<m and col>=0 and vis[row][col]==0){
                        if(time>move[row][col]){
                            pq.push({time+1,{row,col}});
                        }
                        else{
                            pq.push({move[row][col]+1,{row,col}});
                        }
                        vis[row][col] = 1;
                    }
            }
        }

        return 0;

    }
};