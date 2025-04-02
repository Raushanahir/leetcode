class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        
        int n=nums.size();
        long long ans=0;
        long long res=INT_MIN;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    ans=(nums[i]-nums[j]);
                    ans*=nums[k];
                    res=max(ans,res);
                }
            }
        }

        if(res<0) return 0;
        return res;
    }
};