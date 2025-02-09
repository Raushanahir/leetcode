class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        

        long long n=nums.size();
        unordered_map<long long,long long>mp;

        long long no_of_pair=(n*(n-1))/2;

        for(long long i=0;i<n;i++){
            mp[nums[i]-i]++;
        }

        for(auto it:mp){
            long long k=it.second;

            k=(k*(k-1)/2);
            no_of_pair-=k;
        }

        return no_of_pair;
    }
};