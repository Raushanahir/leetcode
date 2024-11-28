class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> dist(n, 1e9);
        dist[0] = 0;
        vector<int> ans;
        vector<int> adj[n];
        for(int i = 0; i < n; i++) {
            adj[i].push_back(i + 1);
        }
        for(auto &q : queries) {
            adj[q[0]].push_back(q[1]);
            for(int i = 0; i < n - 1; i++) {
                for(auto &it : adj[i]) {
                    if(dist[it] > dist[i] + 1) {
                        dist[it] = dist[i] + 1;
                    }
                }
            }
            ans.push_back(dist[n - 1]);
        }
        return ans;
    }
};