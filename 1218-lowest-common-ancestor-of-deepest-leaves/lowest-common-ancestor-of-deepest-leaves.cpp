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
    TreeNode* find_lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;
        TreeNode* leftChild = find_lca(root->left, p, q);
        TreeNode* rightChild = find_lca(root->right, p, q);
        if(leftChild == NULL) return rightChild;
        if(rightChild == NULL) return leftChild;
        return root;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> last;
        while(!q.empty()) {
            int size = q.size();
            vector<TreeNode*> level;
            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                level.push_back(node);
            }
            last = level;
        }
        int size = last.size();
        return find_lca(root, last[0], last[size - 1]);
    }
};