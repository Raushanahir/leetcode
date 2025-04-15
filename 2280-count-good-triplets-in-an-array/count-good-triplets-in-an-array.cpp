class Solution {
public:
    vector<long long> tree;
    int n;

    void update(int ind, int l, int r, int updateindex) {
        if (l == r) {
            tree[ind]++;
            return;
        }
        int mid = (l + r) / 2;
        if (updateindex <= mid) {
            update(2 * ind + 1, l, mid, updateindex);
        } else {
            update(2 * ind + 2, mid + 1, r, updateindex);
        }
        tree[ind] = tree[2 * ind + 1] + tree[2 * ind + 2];
    }

    long long cntcommon(int ind, int l, int r, int queryL, int queryR) {
        if (queryR < l || queryL > r) return 0;  // No overlap
        if (queryL <= l && r <= queryR) return tree[ind]; // Full overlap

        int mid = (l + r) / 2;
        long long left = cntcommon(2 * ind + 1, l, mid, queryL, queryR);
        long long right = cntcommon(2 * ind + 2, mid + 1, r, queryL, queryR);

        return left + right;
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        tree.resize(4 * n, 0);  // Proper initialization

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums2[i]] = i;
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int ind = mp[nums1[i]];

            long long leftCount = cntcommon(0, 0, n - 1, 0, ind - 1);
            long long rightCount = (n - ind - 1) - cntcommon(0, 0, n - 1, ind + 1, n - 1);

            ans += (leftCount * rightCount) ;

            update(0, 0, n - 1, ind);
        }

        return ans;
    }
};
