class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        
        vector<int>g;
        int n=grid.size();
        int diff=0;

        for(int i=0;i<n;i++){
            for(auto it:grid[i]){
                g.push_back(it);
            }
        }

        sort(begin(g),end(g));

        n=g.size();
        int median=g[n/2];

        int ope=0;

        for(int i=0;i<n;i++){
            int diff=abs(g[i]-median);
            if(diff%x!=0) return -1;
            ope+=diff/x;
        }

        return ope;
    }
};