class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int ans=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        int sum=0;
        for(auto it:nums){
            sum+=it;
            int rem=sum%k;
            if(rem<0){
                rem=(sum%k)+k;
            }
            if(mp.count(rem)>0){
                ans+=mp[rem];
            }
            mp[rem]++;
        }
        return ans;
    }
};