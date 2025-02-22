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
    TreeNode* recoverFromPreorder(string traversal) {
        
        int n=traversal.size();
        if(n==0) return NULL;
        queue<pair<int,int>>q; //< value , level>
        unordered_map<int,TreeNode*>mp; // < TreeNode, level>
        int i=0;
        int level=0;
        // putting all element in queue(value , level)
        while(i<n){
            int k=i;
            while(i<n and traversal[i]!='-'){
                i++;
            }
            int val=stoi(traversal.substr(k,i-k));
            q.push({val,level});
            level=0;
            while(i<n and traversal[i]=='-') {
                level++;
                i++;
            }
        }

        // putting in map < level and TreeNode> 
        TreeNode* temp=new TreeNode(q.front().first);
        TreeNode* root=temp;
        mp[q.front().second]=temp;
        temp->left==NULL; temp->right==NULL;
        q.pop();
        while(!q.empty()){
            int level=q.front().second;
            int val=q.front().first;
            q.pop();
            if(mp.find(level-1)!=mp.end()){
                TreeNode* node=new TreeNode(val);
                temp=mp[level-1];
                if(temp->left==NULL) temp->left=node;
                else temp->right=node;
                mp[level]=node;
                node->left=NULL; node->right=NULL;
            }
            
        }

        return root;
    }
};