class Solution {
public:
    vector<int> partitionLabels(string s) {

        unordered_set<char> st;
        int n = s.size();

        vector<int> ans;
        unordered_map<char, int> mp;

        for (auto it : s) {
            mp[it]++;
        }
        int ind = 0;
        for (int i = 0; i < n; i++) {
            st.insert(s[i]);
            mp[s[i]]--;
            // checking all element in map that all element of set is zero(0)
            // hai ki nahi;
            int flag = 0;
            for (auto it : st) {
                if (mp[it] > 0) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                ans.push_back(i - ind + 1);
                st.clear();
                ind = i + 1;
            }
        }

        return ans;
    }
};