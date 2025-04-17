class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        
        int i=0 , j=0;
        int n=nums.size();
        long long pair=0;
        long long ans=0;
        unordered_map<int,int>mp;
        // 1 1 1 1 1 1
        while(j<n){
            mp[nums[j]]++;
            if(mp[nums[j]]>1){
                int p=mp[nums[j]]-1;
                int t=mp[nums[j]];
                pair+=(t*(t-1))/2-(p*(p-1))/2;
                if(pair>=k){
                    int flag=0;
                    while(i<j and pair>=k){
                        t=mp[nums[i]];
                        p=mp[nums[i]]-1;
                        mp[nums[i]]--;
                        if(t>1)
                        pair-=(t*(t-1))/2-(p*(p-1))/2;
                        i++;
                        flag++;
                    }
                    ans+=flag*(n-j);
                }
            }
            j++;
        }

        return ans;
    }
};