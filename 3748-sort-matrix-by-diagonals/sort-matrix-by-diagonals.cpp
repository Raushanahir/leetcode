class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        int m = n - 1;

        for (int i = 0; i < n-1; i++) {
            multiset<int> st;
            int p = m;
            int j = 0;
            while (p < n) {
                st.insert(grid[j][p]);
                j++;
                p++;
            }
            j = 0;
            p = m;
            for (auto it : st) {
                grid[j][p] = it;
                j++;
                p++;
            }
            m--;
        }

        m = 0;
        for (int i = 0; i < n ; i++) {
            vector<int> v;
            int p = m;
            int j = 0;
            while (p < n) {
                v.push_back(grid[p][j]);
                j++;
                p++;
            }
            j = 0;
            p = m;
            sort(v.rbegin(), v.rend());
            for (auto it : v) {
                grid[p][j] = it;
                j++;
                p++;
            }
            m++;
        }

        return grid;
    }
};