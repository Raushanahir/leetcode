class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int ans = INT_MIN, s = 0;
        unordered_map<int, int> mp;
        for(auto it : nums) {
            s += it;
            mp[2 * it]++;
        }
        for(auto it: nums) {
            int x = s - it;
            if(mp[x] >= 2 || mp[x] == 1 && x != it * 2) ans = max(ans, it);
        }
        return ans;
    }
};