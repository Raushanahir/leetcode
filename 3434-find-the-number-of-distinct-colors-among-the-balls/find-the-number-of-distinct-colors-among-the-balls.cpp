class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        
        int n=queries.size();
        unordered_map<int,int>mp;
        vector<int>ans;
        unordered_map<int,int>st;

        for(auto it:queries){

            if(mp.find(it[0])!=mp.end()){
                int k=mp[it[0]];
                st[k]--;
                if(st[k]==0) st.erase(k);
            }
            st[it[1]]++;
            mp[it[0]]=it[1];
            ans.push_back(min(mp.size(),st.size()));
        }

        return ans;
    }
};