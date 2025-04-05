class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        
        return solve(0,nums,0);
    }

    int solve(int ind,vector<int>&nums, int xors){

        if(ind>=nums.size()){
            return xors;
        }

        int take=solve(ind+1,nums,xors^nums[ind]);
        int not_take=solve(ind+1,nums,xors);

        return take+not_take;
    }
};