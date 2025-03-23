class Solution {
public:
    // dsu;
    int find(int x, vector<int>& par) {
        if (x == par[x])
            return x;

        return par[x] = find(par[x], par);
    }

    void combine(int x, int y, vector<int>& par) {
        int x_par = find(x, par);
        int y_par = find(y, par);

        if (x_par != y_par) {
            par[y_par] = x_par;
        }
        return;
    }

    int numberOfComponents(vector<vector<int>>& properties, int k) {

        int n = properties.size();

        vector<int> par(n);
        for (int i = 0; i < n; i++)
            par[i] = i;

        for (int i = 0; i < n; i++) {
            for (int j = 1 + i; j < n; j++) {
                if(intersect(properties[i], properties[j], k))                  combine(i, j, par);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (par[i] == i) {
                ans++;
            }
        }

        return ans;
    }

    bool intersect(vector<int> a, vector<int> b,int k) {
        sort(a.begin(), a.end()); sort(b.begin(), b.end());
        vector<int> v;
        set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(v));
        unordered_set<int> st(v.begin(), v.end());
        return st.size() >= k;
    }
};