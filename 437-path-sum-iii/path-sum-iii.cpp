/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int cnt=0;
    int pathSum(TreeNode* root, int targetSum) {
        
        if(root==NULL) return 0;
        unordered_map<long long,int>mp;
        mp[0]=1;
        solve(root,targetSum,0,mp);
        
        return cnt;
    }

    void solve(TreeNode* node, int target,long long sum,unordered_map<long long,int>&mp){

        if(node==NULL) return ;
        sum+=node->val;
        if(mp.find(sum-target)!=mp.end()) cnt+=mp[sum-target];
        mp[sum]++;
        solve(node->left,target,sum,mp);
        solve(node->right,target,sum,mp);
        
        mp[sum]--;
        if(mp[sum]==0) mp.erase(sum);

        return ;
    }
};