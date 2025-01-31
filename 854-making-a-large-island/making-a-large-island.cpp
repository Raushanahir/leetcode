class Disjoint_Set {
public:
    vector<int> par, size;
    Disjoint_Set(int n) {
        for(int i = 0; i <= n; i++) {
            par.resize(n + 1);
            size.resize(n + 1);
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
    int largestIsland(vector<vector<int>>& grid) {
        
        int n=grid.size();
        Disjoint_Set ds(n*n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                int delr[]={-1, 0, 1, 0};
                int delc[]={0, 1, 0, -1};
                for(int k=0;k<4;k++){
                    int nr=i+delr[k];
                    int nc=j+delc[k];
                    if(nr >= 0 and nr < n and nc >= 0 and nc < n and grid[nr][nc] == 1) ds.unionBySize(i * n + j , nr * n + nc);
                }
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    set<int>st;
                    int delr[]={-1, 0, 1, 0};
                    int delc[]={0, 1, 0, -1};
                    for(int k=0;k<4;k++){
                        int nr=i+delr[k];
                        int nc=j+delc[k];
                        if(nr>=0 and nr<n and nc<n and nc>=0 and grid[nr][nc]==1 ){
                            st.insert(ds.findUPar(nr*n+nc));
                        }
                    }
                    int sizes=0;
                    for(auto it:st){
                        sizes+=ds.size[it];
                    }
                    ans=max(ans,sizes+1);
                }
            }
        }


        for(int i=0;i<n*n;i++){
            ans=max(ans,ds.size[ds.findUPar(i)]);
        }

        return ans;

    }
};