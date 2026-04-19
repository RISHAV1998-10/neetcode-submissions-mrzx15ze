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
    bool dfs(TreeNode* node, int maxVal, int minVal, bool& isBST){
        if(!node)
            return true;

        isBST = node->val > minVal && node->val < maxVal;
        if(!isBST)
            return false;

        else{
            return dfs(node->left, node->val, min(minVal, node->val), isBST) &&
                   dfs(node->right, max(node->val, maxVal), node->val, isBST);
        }
            
    }
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        
        bool isBST = true;
        dfs(root, INT_MAX, INT_MIN, isBST);
        return isBST;

    }
};
