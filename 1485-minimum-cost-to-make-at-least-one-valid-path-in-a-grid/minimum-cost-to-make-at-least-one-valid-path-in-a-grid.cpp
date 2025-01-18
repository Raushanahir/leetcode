class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        vector<vector<int>> shortest(n, vector<int>(m, 1e9));
        shortest[0][0] = 0;
        int delrow[] = {-1, 0, 1, 0};
        int dir[] = {4, 1, 3, 2};
        while(!pq.empty()) {
            auto it = pq.top();
            int row = it.second.first;
            int col = it.second.second;
            int cost = it.first;
            pq.pop();
            if(row == n - 1 and col == m - 1) return cost;
            for(int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delrow[4 - i - 1];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    if(grid[row][col] == dir[i]) {
                        if(shortest[nrow][ncol] > cost) {
                            shortest[nrow][ncol] = cost;
                            pq.push({cost, {nrow, ncol}});
                        }
                    }
                    else {
                        if(shortest[nrow][ncol] > cost + 1) {
                            shortest[nrow][ncol] = cost + 1;
                            pq.push({cost + 1, {nrow, ncol}});
                        }
                    }
                }
            }
        }
        return 0;
    }
};