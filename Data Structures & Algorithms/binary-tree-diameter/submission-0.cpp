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
    int mx = INT_MIN;

    int diameter(TreeNode* root){
        if(!root)
            return 0;
       
        int l = 1 + diameter(root->left);
        int r = 1 + diameter(root->right);

        mx = max(mx, l+r-2);
        return max(l,r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
    
        diameter(root);
        return mx;

    }
};
