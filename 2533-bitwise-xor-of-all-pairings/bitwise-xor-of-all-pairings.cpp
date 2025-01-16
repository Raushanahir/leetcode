class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size(), ans = 0;
        if(len2 & 1) {
            for(auto it : nums1) ans ^= it;
        }
        if(len1 & 1) {
            for(auto it : nums2) ans ^= it;
        }
        return ans;
    }
};