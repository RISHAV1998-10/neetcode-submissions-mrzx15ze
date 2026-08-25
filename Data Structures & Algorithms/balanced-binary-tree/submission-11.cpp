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
    int maxd(TreeNode* root){
        if(!root)
            return 0;

        int lh = maxd(root->left);
        int rh = maxd(root->right);
        return 1+max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;

        bool lb = isBalanced(root->left);
        if(!lb)
            return false;

        bool rb = isBalanced(root->right);
        if(!rb)
            return false;

        int lh = maxd(root->left);
        int rh = maxd(root->right);
        bool currBal = false;
        if(abs(lh - rh)<=1)
            currBal = true;

        return currBal && lb && rb;
    }
};
