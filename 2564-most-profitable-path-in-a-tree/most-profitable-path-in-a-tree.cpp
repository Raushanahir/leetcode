class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        
        int n=edges.size();
        vector<vector<int>>list(n+1);

        for(auto it:edges){
            list[it[0]].push_back(it[1]);
            list[it[1]].push_back(it[0]);
        }

        vector<int>vis(n+1,-1);
        vector<int>alice(n+1,0);
        alice[0] = 1;
        int dis=0;
        bob_moves(list,bob,vis,dis);

        for(auto it:vis) cout << it << endl;

        queue<pair<int,pair<int,int>>>q; //node,ind,amt
        
        q.push({0,{0,amount[0]}});
        int ans=INT_MIN;
        vector<int> v(n+1);
        v[0] = amount[0];
        while(!q.empty()){
            int node=q.front().first;
            int level=q.front().second.first;
            int amt=q.front().second.second;
            q.pop();
            // cout << amt << endl;
            for(auto it:list[node]){
                if(!alice[it]) {
                    if(vis[it] == level + 1) {
                        q.push({it, {level + 1, amt + amount[it] / 2}});
                        v[it] = amt + amount[it] / 2;
                    }
                    else if(vis[it] == -1 || vis[it] > level + 1) {
                        q.push({it, {level + 1, amt + amount[it]}});
                        v[it] = amt + amount[it];
                    }
                    else {
                        q.push({it, {level + 1, amt}});
                        v[it] = amt;
                    }
                    alice[it] = 1;
                }
            }
        }
        for(int i = 0; i <= n; i++) {
            if(list[i].size() == 1 && i != 0) ans = max(ans, v[i]);
        }
        return ans;
        return *max_element(v.begin(), v.end());

    }

    bool bob_moves(vector<vector<int>>&list, int bob, vector<int>&vis,int &dis){

        if(vis[bob]!=-1) return false;
        vis[bob]=dis;
        if(bob==0) return true;


        for(auto it:list[bob]){

            if(vis[it]==-1){
                dis++;
            if(bob_moves(list,it,vis,dis))
             return true;
             dis--;
             vis[it]=-1;
            }

        }

        return false;
    }
};