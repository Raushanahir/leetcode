class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        
        int num=nums[0];
        int n=nums.size();
        int ans=0;
        int k=num;

        for(int i=1;i<n;i++){
            k=max(k,nums[i]);
            if(nums[i]<num){
                ans=i;
                num=k;
            }
        }

        return ans+1;
    }
};