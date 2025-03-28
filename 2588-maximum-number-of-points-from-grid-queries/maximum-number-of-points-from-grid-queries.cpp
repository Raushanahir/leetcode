class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {

        int k = queries.size();
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int, int>> que;
        for (int i = 0; i < k; i++) {
            que.push_back({queries[i], i});
        }
        sort(que.begin(), que.end());

        vector<int> ans(k, 0);

        // int row=0,col=0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = 1;
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            int querie = que[i].first;
            while (!pq.empty() and pq.top().first < querie) {
                int row = pq.top().second.first;
                int col = pq.top().second.second;
                pq.pop();
                cnt++;
                if (row + 1 < n and vis[row + 1][col] == 0) {
                    pq.push({grid[row + 1][col], {row + 1, col}});
                    vis[row + 1][col] = 1;
                }
                if (col + 1 < m and vis[row][col + 1] == 0) {
                    pq.push({grid[row][col + 1], {row, col + 1}});
                    vis[row][col + 1] = 1;
                }
                if (row - 1 >= 0 and vis[row - 1][col] == 0) {
                    pq.push({grid[row - 1][col], {row - 1, col}});
                    vis[row - 1][col] = 1;
                }
                if (col - 1 >= 0 and vis[row][col - 1] == 0) {
                    pq.push({grid[row][col - 1], {row, col - 1}});
                    vis[row][col - 1] = 1;
                }
            }
            ans[que[i].second] = cnt;
        }

        return ans;
    }
};