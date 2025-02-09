class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {

        int n_grp = groups.size();
        int n_ele = elements.size();

        int maxi = *max_element(begin(groups), end(groups));

        unordered_map<int, int> mp;
        vector<int> ans;

        for (int i = n_ele - 1; i >= 0; i--) {
            mp[elements[i]] = i;
        }

        for (int i = 0; i < n_grp; i++) {
            vector<int> v = factor(groups[i], maxi);
            int mini = INT_MAX;
            for (auto it : v) {
                if (mp.find(it) != mp.end()) {
                    mini = min(mini, mp[it]);
                }
            }
            if (mini == INT_MAX) {
                groups[i] = -1;
            } else {
                groups[i] = mini;
            }
        }

        return groups;
    }

    vector<int> factor(int n, int maxi) {

        vector<int> ans;

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0 and i <= maxi) {
                ans.push_back(i);
                if (n / i <= maxi)
                    ans.push_back(n / i);
            }
        }

        return ans;
    }
};