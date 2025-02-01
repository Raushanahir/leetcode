class Disjoint_Set {
public:
    vector<int> par, size;
    Disjoint_Set(int n) {
        par.resize(n + 1);
        size.resize(n + 1);
        for(int i = 0; i < n; i++) {
            par[i] = i;
            size[i] = 1 ;
        }
    }
    int findUPar(int node) {
        if(node == par[node]) return node;
        return par[node] = findUPar(par[node]);
    }
    void unionBySize(int x, int y) {
        int ulp_x = findUPar(x);
        int ulp_y = findUPar(y);

        if(ulp_x == ulp_y) return;

        if(size[ulp_x] > size[ulp_y]) {
            par[ulp_y] = ulp_x;
            size[ulp_x]+=size[ulp_y];
        }
        else {
            par[ulp_x] = ulp_y;
            size[ulp_y] += size[ulp_x];
        }
    }
};


class Solution {
public:
    int n,m;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        n=grid.size();
        m=grid[0].size();
        // vector<vector<int>>vis(n,vector<int>(m,0));

        Disjoint_Set ds(n*m);

        int delr[]={1,-1,0,0};
        int delc[]={0,0,-1,1};


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0)continue;

                for(int k=0;k<4;k++){
                    int r=i+delr[k];
                    int c=j+delc[k];

                    if(r<n and r>=0 and c<m and c>=0 and grid[r][c]==1 ){
                        ds.unionBySize(i*m+j , r*m+c);
                    }
                }
            }
        }

        int ans=0;
        for(int i=0;i<n ; i++){
            for(int j = 0; j< m;j++){
            if(grid[i][j])
            ans=max(ans,ds.size[ds.findUPar(i*m + j)]);
            }
            cout << ds.size[i]<<" ";
        }

        return ans;
    }
};