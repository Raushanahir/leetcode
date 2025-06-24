class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        
        vector<int>ans;
        vector<int>fre;
        int n=nums.size();
        int i=0,j=0;

        while(true){
            while(j<n and nums[j]!=key) j++;
            while(i<n and abs(j-i)>k) i++;
            while(i<n and j<n and abs(j-i)<=k) {
                ans.push_back(i);
                i++;
            }
            j++;
            if(j>=n || i>=n) break;
        }

        return ans;
    }
};