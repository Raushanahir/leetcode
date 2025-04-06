class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int offset = 500; // to shift negative diffs to positive indices
        int maxDiff = 1000; // range of diff: -500 to +500

        vector<vector<int>> dp(n, vector<int>(maxDiff + 1, 1));
        int ans = 2;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int diff = nums[i] - nums[j] + offset;
                dp[i][diff] = dp[j][diff] + 1;
                ans = max(ans, dp[i][diff]);
            }
        }

        return ans;
    }
};
