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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        
        int level=checklevel(root);

        cout << level << endl;

        if(root->left==NULL and root->right==NULL) return root;

        while(level--){

            int left=0;
            if(root->left!=NULL)left=checklevel(root->left);
            int right=0;
            if(root->right!=NULL)right=checklevel(root->right);

            if(left==right) return root;
            if(left>right) root=root->left;
            else root=root->right;
        }

        return NULL;
    }

    int checklevel(TreeNode* root){

        int level=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            level++;
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
        }

        return level;
    }
};