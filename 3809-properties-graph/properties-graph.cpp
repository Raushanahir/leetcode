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

        if (x_par < y_par) {
            par[y_par] = x_par;
        } else {
            par[x_par] = y_par;
        }
        return;
    }

    int numberOfComponents(vector<vector<int>>& properties, int k) {

        unordered_map<int, unordered_set<int>> mp;
        int n = properties.size();

        for (int i = 0; i < n; i++) {
            for (auto it : properties[i]) {
                mp[i].insert(it);
            }
        }

        vector<int> par(n);
        for (int i = 0; i < n; i++)
            par[i] = i;

        for (int i = 0; i < n; i++) {
            for (int j = 1 + i; j < n; j++) {
                int same = 0;
                unordered_set<int> st = mp[i];
                for (auto it : mp[j]) {
                    if (st.find(it) != st.end()) {
                        same++;
                    }
                }
                if (same >= k) {
                    combine(i, j, par);
                }
            }
        }

        int ans = 0;
        // sort(par.begin(), par.end());
        for (int i = 0; i < n; i++) {
            if (par[i] == i) {
                ans++;
            }
        }

        return ans;
    }
};