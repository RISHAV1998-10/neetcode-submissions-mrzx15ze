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
    int dfs(TreeNode* root, int maxVal){
        if(!root)
            return 0;

        int res = root->val >= maxVal ? 1 : 0;
        maxVal = max(maxVal, root->val);
        return dfs(root->left, maxVal)+dfs(root->right, maxVal)+res;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};
