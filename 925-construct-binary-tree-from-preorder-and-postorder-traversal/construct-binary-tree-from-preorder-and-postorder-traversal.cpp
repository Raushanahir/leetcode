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
    unordered_map<int,int>mp;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        
        int n=preorder.size();
        unordered_set<int>st;

        for(int i=0;i<n;i++){
            mp[postorder[i]]=i;
            st.insert(i);
        }
        int ind=0;
        return constructTree(preorder,postorder,ind,st);
    }

    TreeNode* constructTree(vector<int>&pre, vector<int>&post,int &ind,unordered_set<int>&st){

        if(ind==pre.size()) return NULL;
        TreeNode* node=new TreeNode(pre[ind]);
        int k=mp[pre[ind]];
        st.erase(k);
        ind++;
        if(st.find(k-1)==st.end())return node;
        node->left=constructTree(pre,post,ind,st);
        if(st.find(k-1)==st.end())return node;
        node->right=constructTree(pre,post,ind,st);

        return node;
    }
};