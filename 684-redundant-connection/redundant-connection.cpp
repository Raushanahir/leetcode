class Disjoint_Set {
    vector<int> parent, size;
public:
    Disjoint_Set(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int x, int y) {
        int ulp_x = findUPar(x);
        int ulp_y = findUPar(y);
        if(x == y) return;
        if(size[ulp_x] > size[ulp_y]) {
            parent[ulp_y] = ulp_x;
            size[ulp_x] += size[ulp_y];
        }
        else {
            parent[ulp_x] = ulp_y;
            size[ulp_y] += size[ulp_x];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        Disjoint_Set ds(edges.size() + 1);
        vector<int> ans;
        for(auto it : edges) {
            if(ds.findUPar(it[0]) != ds.findUPar(it[1])) 
                ds.unionBySize(it[0], it[1]);
            else ans = it;
        }
        return ans;
    }
};