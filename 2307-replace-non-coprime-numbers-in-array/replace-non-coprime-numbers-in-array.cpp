class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {

        int n = nums.size();
        stack<int> st;
        st.push(nums[0]);
        int k = 1;

        for (int i = 1; i < n; i++) {
            if (!st.empty())
                k = gcd(st.top(), nums[i]);
            if (st.empty() || k == 1)
                st.push(nums[i]);
            else {
                int kk = nums[i];
                while (!st.empty() and k > 1) {
                    kk = (1LL * st.top() * kk) / k;
                    st.pop();
                    if (!st.empty())
                        k = gcd(st.top(), kk);
                }
                st.push(kk);
            }
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};