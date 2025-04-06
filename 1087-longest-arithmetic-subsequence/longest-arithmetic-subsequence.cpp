// struct pair_hash {
//     template <class T1, class T2>
//     size_t operator()(const pair<T1, T2>& p) const {
//         return hash<T1>()(p.first) ^ (hash<T2>()(p.second) << 1);
//     }
// };

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size(), ans = 2;
        vector<map<int, int>> dp(n);
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j];
                int len = 2;
                if(dp[j].find(diff) != dp[j].end()) len = dp[j][diff] + 1;
                dp[i][diff] = max(dp[i][diff], len);
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};
