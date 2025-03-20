class Solution {
public:
    vector<int>parent;

int find(int i, vector<int>&parent){
    if(parent[i]==i){
        return i;
    }

    return parent[i]=find(parent[i],parent);
}

void combine(int x,int y,vector<int>&parent){

    int x_par=find(x,parent);
    int y_par=find(y,parent);

    if(x_par!=y_par){
        parent[y_par]=x_par;
    }
}


    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {

        vector<vector<pair<int,int>>>list(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];

            list[u].push_back({v,wt});
            list[v].push_back({u,wt});
        }
        
        vector<int>parent(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        vector<bool>vis(n,false);
        // for stroing weight of each graph
        unordered_map<int,int>mp; 
        for(int i=0;i<n;i++){
            int and_wt=pow(2,31)-1;
            if(vis[i]==false){
                queue<int>q;
                q.push(i);
                while(!q.empty()){
                    int u=q.front();
                    q.pop();
                    vis[u]=true;
                    for(auto it:list[u]){
                        if(vis[it.first]==false){
                            and_wt&=it.second;
                            q.push(it.first);
                            combine(u,it.first,parent);
                        }
                    }
                }
            }
            if(and_wt==pow(2,31)-1){
                mp[i]=0;
            }else{
                mp[i]=and_wt;
            }    
        }


        // for query operation
        vector<int>ans;
        for(auto it:query){

            int x_par=find(it[0],parent);
            int y_par=find(it[1],parent);
            int wt=mp[x_par];

            if(x_par==y_par){
                ans.push_back(wt);
            }else{
                ans.push_back(-1);
            }
        }

        return ans;
    }
};