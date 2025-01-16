class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        if(nums2.size() & 1) for(auto it : nums1) ans ^= it;
        if(nums1.size() & 1) for(auto it : nums2) ans ^= it;
        return ans;
    }
};