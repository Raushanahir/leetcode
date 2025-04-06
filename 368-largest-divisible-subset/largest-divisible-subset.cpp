class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), ans = 1, ind = 0;
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> hash(n);
        for(int i = 0; i < n; i++) hash[i] = i;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
                if(ans < dp[i]) {
                    ans = dp[i];
                    ind = i;
                }
            }
        }
        vector<int> result;
        while(hash[ind] != ind) {
            result.push_back(nums[ind]);
            ind = hash[ind];
        }
        result.push_back(nums[ind]);
        reverse(result.begin(), result.end());
        return result;
    }
};