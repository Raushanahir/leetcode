class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        sort(nums.begin(), nums.end());

        // dp[i]: length of the largest subset ending at index i
        vector<int> dp(n, 1);
        // parent[i]: the previous index in the subset chain
        vector<int> parent(n, -1);

        int max_len = 1;
        int max_index = 0;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > max_len) {
                max_len = dp[i];
                max_index = i;
            }
        }

        // Reconstruct the subset
        vector<int> result;
        int curr = max_index;
        while (curr != -1) {
            result.push_back(nums[curr]);
            curr = parent[curr];
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
