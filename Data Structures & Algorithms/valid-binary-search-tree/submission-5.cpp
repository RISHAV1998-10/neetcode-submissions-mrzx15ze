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
    bool checkBST(TreeNode* node, int minVal, int maxVal){
        if(!node)
            return true;

        bool isBST = (node->val < maxVal) && (node->val > minVal);
        if(isBST){
            return  checkBST(node->left, minVal, node->val) && 
                    checkBST(node->right, node->val, maxVal); 
        }
        else{
            return false;
        }
    }

    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;

        return checkBST(root, INT_MIN, INT_MAX);
    }
};
