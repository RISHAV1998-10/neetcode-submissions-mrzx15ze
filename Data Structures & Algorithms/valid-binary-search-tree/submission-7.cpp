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
    bool dfs(TreeNode* node, int maxVal, int minVal){
        if(!node)
            return true;

        bool left = dfs(node->left, node->val, minVal);
        bool right = dfs(node->right,  maxVal, node->val);

        return (node->val < maxVal) && (node->val >minVal) && left && right;
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MAX, INT_MIN);
    }
};
