class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int n = strs.size();
        unordered_map<string, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            mp[s].push_back(i);
        }
        vector<vector<string>> ans;

        for (auto& it : mp) {
            vector<string>v;
            for (auto i : it.second)
                v.push_back(strs[i]);
            ans.push_back(v);
        }
        return ans;
    }
};