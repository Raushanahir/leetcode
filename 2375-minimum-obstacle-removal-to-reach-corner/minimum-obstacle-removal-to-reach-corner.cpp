class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        int delrow[] = {-1, 0, 1, 0};
        while(!pq.empty()) {
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            for(int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delrow[4 - i - 1];
                if(nrow >=0 and ncol >=0 and nrow < n and ncol < m) {
                    if(dist[nrow][ncol] > dist[row][col] + grid[nrow][ncol]) {
                        dist[nrow][ncol] = dist[row][col] + grid[nrow][ncol];
                        pq.push({dist[nrow][ncol], {nrow, ncol}});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};