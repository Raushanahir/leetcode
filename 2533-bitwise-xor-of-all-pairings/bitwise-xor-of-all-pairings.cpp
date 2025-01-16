class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        
        int ans=0;
        for(int i=0;i<32;i++){
            int o1=0 , l1=0 , o2=0 , l2=0;
            for(int j=0;j<nums1.size();j++){
                if(nums1[j]&(1<<i)) l1++;
                else o1++;
            }
            for(int j=0;j<nums2.size();j++){
                if(nums2[j]&(1<<i)) l2++;
                else o2++;
            }
            int x1=o1*l2;
            int x2=o2*l1;

            if((x1+x2)%2!=0) ans+=(1<<i);
        }

        return ans;
    }
};