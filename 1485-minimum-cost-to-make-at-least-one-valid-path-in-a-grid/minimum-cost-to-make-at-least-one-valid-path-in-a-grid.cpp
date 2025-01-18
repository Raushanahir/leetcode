class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 0});
        vector<vector<int>> shortest(n, vector<int>(m, 1e9));
        shortest[0][0] = 0;
        int delrow[] = {-1, 0, 1, 0};
        int dir[] = {4, 1, 3, 2};
        while(!q.empty()) {
            auto it = q.front();
            int row = it.first.first;
            int col = it.first.second;
            int cost = it.second;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delrow[4 - i - 1];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    if(grid[row][col] == dir[i]) {
                        if(shortest[nrow][ncol] > cost) {
                            shortest[nrow][ncol] = cost;
                            q.push({{nrow, ncol}, cost});
                        }
                    }
                    else {
                        if(shortest[nrow][ncol] > cost + 1) {
                            shortest[nrow][ncol] = cost + 1;
                            q.push({{nrow, ncol}, cost + 1});
                        }
                    }
                }
            }
        }
        return shortest[n - 1][m - 1];
    }
};