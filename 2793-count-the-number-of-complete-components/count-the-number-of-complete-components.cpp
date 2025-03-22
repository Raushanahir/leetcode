class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges){
        
        vector<vector<int>>adj(n);

        for(auto it:edges){
            int u=it[0];
            int v=it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>vis(n,false);
        int ans=0;

        for(int i=0;i<n;i++){
            if(vis[i]==false){
                int nodes=0, edge=0;
                dfs(i,adj,nodes,edge,vis,-1);
                cout << nodes << " " << edge << endl;
                int no_of_edges=nodes*(nodes-1);
                if(no_of_edges==edge){
                    ans++;
                }
            }
        }

        return ans;
    }

    void dfs(int node,vector<vector<int>>&adj,int &nodes,int &edges,vector<bool>&vis,int par_node){

        if(vis[node]==true) return;
        nodes+=1;
        vis[node]=true;

        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,nodes,edges,vis,node);
            }
            edges++;
        }
    }
};