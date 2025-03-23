class Disjoint_Set {
public:
    vector<int> parent, size;
    Disjoint_Set(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] > size[ulp_v])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        } else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

bool check(vector<int> a, vector<int> b, int k) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> v;
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(v));
    int len = v.size();
    for(int i = 1; i < v.size(); i++) {
        if(v[i] == v[i - 1]) len--;
    }
    return len >= k;
}

class Solution {
public:
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        Disjoint_Set ds(n);
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(check(properties[i], properties[j], k)) {
                    ds.unionBySize(i, j);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(ds.findUPar(i) == i) ans++;
        }
        return ans;
    }
};