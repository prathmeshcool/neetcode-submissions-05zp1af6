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
    bool check(TreeNode* r1, TreeNode* r2){
        if(!r1 && !r2)
            return true;
        if(!r1 || !r2)
            return false;
        if(r1->val != r2->val)
            return false;
        
        return check(r1->left, r2->left) && check(r1->right, r2->right);

    } 
    bool ans = false;
    void DFS(TreeNode* root, TreeNode* subRoot){
        if(!root)
            return;
        if(root->val==subRoot->val){
            if(check(root, subRoot)){
                ans = true;
                return;
            }
        }
        DFS(root->left,subRoot);
        DFS(root->right, subRoot);

    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)
            return false;
        if(!subRoot)
            return true;
        if(check(root,subRoot))
            return true;

        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);        

    }
};
