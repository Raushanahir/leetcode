/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
// solving the question by preorder traversal
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int>in;
        preorder_traversal(root,in);
        
        for(auto it:in){
            if(it>p->val and it>q->val) continue;
            else if(it<p->val and it<q->val) continue;
            else {
                TreeNode* node=new TreeNode(it);
                return node;
            }
        }
        
        return NULL;
    }
    
    void preorder_traversal(TreeNode* node,vector<int>&in){
        
        if(node==NULL) return;
    
        in.push_back(node->val);
        preorder_traversal(node->left,in);
        preorder_traversal(node->right,in);
        
    }
};