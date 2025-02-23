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
class FindElements {
public:
    unordered_set<int>st;
    TreeNode* node;
    void built_tree(TreeNode* root,int ind){

        if(root==NULL) return ;
        st.insert(ind);
        if(root->left!=NULL) {
            root->left->val=2*ind+1;
            built_tree(root->left,2*ind+1);
        }
        if(root->right!=NULL) {
            root->right->val=2*ind+2;
            built_tree(root->right,2*ind+2);
        }
    }

    FindElements(TreeNode* root) {
        st.insert(0);
        node=root;
        node->val=0;
        built_tree(node,0);
    }
    
    bool find(int target) {

        if(st.find(target)!=NULL) return true;

        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */