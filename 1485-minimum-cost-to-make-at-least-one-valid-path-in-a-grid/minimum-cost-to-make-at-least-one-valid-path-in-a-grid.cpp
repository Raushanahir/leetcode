class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {0, 0}});
        vector<vector<int>> vis(n, vector<int>(m, 0));

        while (!pq.empty()) {
            int step = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            int dir = grid[r][c];
            pq.pop();

            // Check if already visited
            if (vis[r][c] == 1) continue;
            vis[r][c] = 1;

            // If reached the destination
            if (r == n - 1 && c == m - 1) return step;

            // Handle preferred direction
            if (dir == 1 && c + 1 < m ) 
                pq.push({step, {r, c + 1}});

            else if (dir == 2 && c - 1 >= 0) 
                pq.push({step, {r, c - 1}});
            
            else if (dir == 4 && r - 1 >= 0 )
                pq.push({step, {r - 1, c}});
            
            else if (dir == 3 && r + 1 < n )
                pq.push({step, {r + 1, c}});
            

            // Handle other directions with cost +1
            if (dir != 3 && r + 1 < n )
                pq.push({step + 1, {r + 1, c}});
            
            if (dir != 1 && c + 1 < m )
                pq.push({step + 1, {r, c + 1}});
            
            if (dir != 2 && c - 1 >= 0 )
                pq.push({step + 1, {r, c - 1}});
            
            if (dir != 4 && r - 1 >= 0 )
                pq.push({step + 1, {r - 1, c}});
            
        }

        return -1; // No path found (edge case)
    }
};
