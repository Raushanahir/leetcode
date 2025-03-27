class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        
        unordered_map<int,int>mp;
        unordered_map<int,int>mp2;
        int n=nums.size();

        for(auto it:nums){
            mp[it]++;
        }

        if(nums.size()==1) return -1;

        for(int i=0;i<n;i++){
            mp2[nums[i]]++;
            int left=mp2[nums[i]];
            int right=mp[nums[i]]-left;

            if(left*2 >(i+1) and right*2>(n-i-1)) return i;
        }

        return -1;
    }
};