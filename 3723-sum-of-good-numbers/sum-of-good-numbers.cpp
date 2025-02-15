class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(i-k<0 and i+k>n)
            ans+=nums[i];
            else if(i-k>=0 and nums[i]>nums[i-k]){
                if(i+k>=n) 
                ans+=nums[i];
                else if(i+k<n and nums[i]>nums[i+k])
                ans+=nums[i];
            }
            else if(i+k<n and nums[i]>nums[i+k]){
                if(i-k<0) 
                ans+=nums[i];
                else if(i-k>=0 and nums[i]>nums[i-k])
                ans+=nums[i];
            }
        }

        return ans;
    }
};