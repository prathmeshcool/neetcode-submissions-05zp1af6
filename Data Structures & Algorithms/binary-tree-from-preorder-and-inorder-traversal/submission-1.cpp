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
    TreeNode* build(int l1,int r1,int l2,int r2,unordered_map<int,int>&id,vector<int>&preorder,vector<int>&inorder){
        
        if(l2>r2){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[l1]);
        int idx=id[root->val];
        root->left=build(l1+1,l1+(idx-l2),l2,idx-1,id,preorder,inorder);
        root->right=build(l1+(idx-l2)+1,r1,idx+1,r2,id,preorder,inorder);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        unordered_map<int,int> id;


        for(int i=0;i<n;i++){
            id[inorder[i]]=i;
        }

        return build(0,n-1,0,n-1,id,preorder,inorder);
    }
};
