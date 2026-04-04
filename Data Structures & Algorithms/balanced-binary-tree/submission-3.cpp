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
    int htBt(TreeNode* root){
        if(!root)
            return 0;

        int lh = htBt(root->left);
        int rh = htBt(root->right);
        return 1+max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        
        int lh = htBt(root->left);
        int rh = htBt(root->right);
        return (abs(lh-rh)<=1 ) && isBalanced(root->left) && isBalanced(root->right);
    }
};
