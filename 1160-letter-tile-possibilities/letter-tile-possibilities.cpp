class Solution {
public:
    int n;
    int numTilePossibilities(string tiles) {

        n = tiles.size();
        unordered_set<string> ans;
        vector<bool>vis(n,false);

        solve(tiles, ans, "",vis);

        // -1 for space " " substring
        return ans.size() - 1;
    }

// substring and it permutation 
    void solve(string s, unordered_set<string>& st, string temp,vector<bool>&vis) {
        
        st.insert(temp);
        for(int i=0;i<n;i++){
            if(vis[i]){
                continue;
            }
            vis[i]=true;
            temp.push_back(s[i]);
            solve(s,st,temp,vis);
            temp.pop_back();
            vis[i]=false;
        }
    }
};