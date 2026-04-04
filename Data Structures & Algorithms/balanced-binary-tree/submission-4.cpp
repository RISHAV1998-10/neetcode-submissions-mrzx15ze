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
   int htBt(TreeNode* root, bool &isBal) {
        if (!root) return 0;

        int lh = htBt(root->left, isBal);
        if (!isBal) return -1; 

        int rh = htBt(root->right, isBal);
        if (!isBal) return -1;  
        
        if (abs(lh - rh) > 1) {
            isBal = false;
            return -1;  
        }

        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        bool isBal = true;  
        htBt(root, isBal);
        return isBal;  
    }
};
