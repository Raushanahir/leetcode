class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int len = 2;
                int prev = arr[j];
                int val = arr[i] + prev;
                for(int k = j + 1; k < n; k++) {
                    if(arr[k] == val) {
                        len++;
                        ans = max(ans, len);
                        int temp = prev;
                        prev = val;
                        val = temp + val;
                    } 
                    else if(arr[k] > val) break;
                }
            }
        }
        return ans;
    }
};