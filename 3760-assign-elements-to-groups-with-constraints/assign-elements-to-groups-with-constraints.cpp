class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {

        int n_grp = groups.size();
        int n_ele = elements.size();

        unordered_map<int, int> mp;
        vector<int> ans;

        for (int i = n_ele - 1; i >= 0; i--) {
            mp[elements[i]] = i;
        }

        for (int i = 0; i < n_grp; i++) {
            vector<int> v = factor(groups[i]);
            int mini = INT_MAX;
            for (auto it : v) {
                if (mp.find(it)!=mp.end()) {
                    mini=min(mini,mp[it]);
                }

            }
            if (mini == INT_MAX) {
                groups[i]=-1;
            }
            else{
                groups[i]=mini;
            }
        }

        return groups;
    }

    vector<int> factor(int n) {

        vector<int> ans;

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                ans.push_back(i);
                ans.push_back(n/i);
            }
        }

        return ans;
    }
};