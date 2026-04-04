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
    void preorder(TreeNode* root, int mx){
        if(!root)
            return;
        if(root->val>=mx){
            cnt++;
            mx=root->val;
        }
        preorder(root->left,mx);
        preorder(root->right,mx);

    }
    int goodNodes(TreeNode* root) {
        preorder(root,-101);
        return cnt;
    }
};
