class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        int n=recipes.size();
        // recipes
        unordered_map<string,int>rec;
        int i=0;
        for(auto it:recipes) {
            rec[it]=i;
            i++;
        }

        // supplies
        unordered_set<string>sup(supplies.begin(),supplies.end());

        // ingredients in list form
        unordered_map<string,vector<string>>ing;
        for(int i=0;i<n;i++){
            for(auto mat:ingredients[i]){
                // if(rec.find(mat)!=rec.end()){
                    ing[recipes[i]].push_back(mat);
                // }
            }
        }

        unordered_map<string, int>vis;
        stack<string>st;

        for(auto it:recipes){
            if(vis.find(it)==vis.end()){
                // dfs
                dfs(st,it,ing,vis,rec);
                // st.push(it);
            }
        }

        vector<string>topo;
        while(!st.empty()){
            topo.push_back(st.top());
            // cout << st.top() << " ";
            st.pop();
        }

        vector<string>ans;
        reverse(topo.begin(),topo.end());

        for(auto it:topo){
            // cout << it << " ";
            int k=rec[it];
            bool flag=0;
            for(int j=0;j<ingredients[k].size();j++){
                flag=0;
                if(sup.find(ingredients[k][j])!=sup.end()){
                    flag=1;
                }else{
                    flag = 0;
                    break;
                }
            }
            if(flag==1){
                ans.push_back(it);
                sup.insert(it);
            }
        }        

        return ans;
    }

    void dfs(stack<string>&st, string recipes,unordered_map<string,vector<string>>&ing , unordered_map<string,int>&vis , unordered_map<string,int>&rep){

        vis[recipes] = 1;
        
        // vis.insert(recipes);

        for(const auto& it : ing[recipes]){
            if(vis.find(it)==vis.end() && rep.find(it) != rep.end())
                dfs(st,it,ing,vis, rep);
        }
        st.push(recipes);
    }
};