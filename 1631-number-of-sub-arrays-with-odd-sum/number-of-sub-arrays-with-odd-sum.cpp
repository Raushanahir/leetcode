class Solution {
public:
    int n;
    int numOfSubarrays(vector<int>& arr) {
        
        n=arr.size();
        long long ans=0 , sum=0;
        int odd=0, even=0;
        int mod=1e9+7;


        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum%2==0){
                ans+=odd;
                even++;
            }else{
                ans+=(even+1);
                odd++;
            }
            ans%=mod;
        }

        return ans;
    }
};