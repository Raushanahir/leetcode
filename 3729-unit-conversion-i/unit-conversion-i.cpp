class Solution {
public:
    using ll = long long;
    const int MOD = 1e9 + 7;

    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        unordered_map<int, vector<pair<int, ll>>> adj;
        int n = 0;
        for (auto &conv : conversions) n = max(n, max(conv[0], conv[1]) + 1);
        vector<ll> res(n,0);
        vector<int>vis(n,0);

        for (auto &conv : conversions) {
            int src = conv[0], tar = conv[1];
            ll fact = conv[2];
            adj[src].push_back({tar, fact});
        }

        queue<int>q;
        q.push(0);
        vis[0]=1;
        res[0]=1;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                while(!q.empty()){
                    int k=q.front();
                    q.pop();
                    for(auto it:adj[k]){
                        if(!vis[it.first]){
                            vis[it.first]=1;
                            res[it.first]=((it.second*res[k])%MOD);
                            q.push(it.first);
                        }
                    }
                }
            }   
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++) ans[i] = res[i] % MOD;
        return ans;
    }
};
