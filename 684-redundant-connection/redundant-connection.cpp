class Disjoint_Set {
    vector<int> par, rank;
public:
    Disjoint_Set(int n) {
        for(int i = 0; i <= n; i++) {
            par.push_back(i);
            rank.push_back(0);
        }
    }
    int findUPar(int node) {
        if(node == par[node]) return node;
        return par[node] = findUPar(par[node]);
    }
    void unionByRank(int x, int y) {
        int ulp_x = findUPar(x);
        int ulp_y = findUPar(y);

        if(x == y) return;

        if(rank[ulp_x] > rank[ulp_y]) {
            par[ulp_y] = ulp_x;
        }
        else {
            par[ulp_x] = ulp_y;
            rank[ulp_y] += 1;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        Disjoint_Set ds(edges.size() + 1);
        vector<int>ans;
        for(auto it:edges){
            if(ds.findUPar(it[0]) != ds.findUPar(it[1])){
                ds.unionByRank(it[0],it[1]);
            }
            else ans=it;
        }
        return ans;
    }
};