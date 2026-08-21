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
    bool dfs(TreeNode* root, int maxVal, int minVal){
        if(!root)
            return true;

        return (root->val>minVal) && (root->val<maxVal) 
                && dfs(root->left, min(maxVal, root->val), minVal) 
                && dfs(root->right, maxVal, max(minVal, root->val));
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MAX, INT_MIN);
    }
};
