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
    int pathSum(TreeNode* root, int targetSum) {
        
        queue<TreeNode*>q;
        if(root==NULL) return 0;

        int cnt=0;
        q.push(root);

        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            long long sum=0;
            solve(node,targetSum,sum,cnt); 
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
        }
        return cnt;
    }

    void solve(TreeNode* node, int target,long long sum,int &cnt){

        if(node==NULL) return ;
        sum+=node->val;
        if(sum==target) cnt++;
        solve(node->left,target,sum,cnt);
        solve(node->right,target,sum,cnt);

        return ;
    }
};