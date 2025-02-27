class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for(int i = 2; i < n; i++) {
            int first = 0;
            int last = i - 1;
            while(first < last) {
                int val = arr[first] + arr[last];
                if(val == arr[i]) {
                    dp[last][i] = dp[first][last] + 1;
                    ans = max(ans, dp[last][i]);
                    first++;
                    last--;
                }
                else if(val > arr[i]) last--;
                else first++;
            }
        }
        return (ans != 0) ? ans + 2 : 0;
    }
};