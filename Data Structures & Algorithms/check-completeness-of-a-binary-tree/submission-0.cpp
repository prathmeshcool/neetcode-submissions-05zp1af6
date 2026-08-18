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
    bool isCompleteTree(TreeNode* root) {
        if(!root)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        
        bool chk = false;
        while(q.size()){
            int sz = q.size();

            for(int i=0; i<sz; i++){
                TreeNode* node = q.front(); q.pop();

                if(node->left){
                    if(chk)return false;
                    q.push(node->left);
                }
                else{
                    chk = true;
                }
                if(node->right){
                    if(chk)return false;
                    q.push(node->right);
                }
                else{
                    chk = true;
                }

            }
        }
        return true;
    }
};