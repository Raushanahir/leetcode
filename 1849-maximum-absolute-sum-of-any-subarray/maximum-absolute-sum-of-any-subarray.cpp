class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
        int ans=0 , sum=0;


        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>0){
                ans=max(sum,ans);
            }else{
                sum=0;
            }
        }
        sum=0;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum<0){
                ans=max(abs(sum),ans);
            }else{
                sum=0;
            }
        }

        return ans;
    }
};