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
    vector<int> v;
    void inorder(TreeNode* root){
        if(!root)
            return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }

    bool isValidBST(TreeNode* root) {
        inorder(root);
        vector<int> v2=v;
        sort(v2.begin(),v2.end());
        auto it=unique(v2.begin(),v2.end());
        if(it!=v2.end())return false;
        if(v==v2)
            return true;
        return false;    
    }
};
