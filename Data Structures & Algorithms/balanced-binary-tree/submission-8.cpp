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
    int ht(TreeNode* root){
        if(!root)
            return 0;

        int ls=ht(root->left);
        int rs=ht(root->right);
        return 1+max(ls,rs);
    }

    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;

        int lh = ht(root->left);
        int rh = ht(root->right);

        if(abs(lh-rh)>1)
            return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};
