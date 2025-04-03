class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        
        int n=nums.size();
        vector<long long>right(n),left(n);

        // putting left maximum
        left[0]=(nums[0]);
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],(long long)nums[i]);
        }

        // pushing right maximum
        right[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],(long long)nums[i]);
        }

        long long ans=0;

        // result is storing
        for(int i=1;i<n-1;i++){
            long long diff=(left[i-1]-nums[i])*right[i+1];
            ans=max(diff,ans);
        }

        if(ans<0) return 0 ;
        return ans;
    }
};