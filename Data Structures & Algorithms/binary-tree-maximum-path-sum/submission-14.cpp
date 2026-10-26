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
    int dfs(TreeNode* node, int &maxVal){
        if(!node)
            return 0;

        int lh = max(dfs(node->left, maxVal), 0);
        int rh = max(dfs(node->right, maxVal), 0);
        maxVal = max(maxVal, lh+rh+node->val);
        return node->val+max(lh, rh);
    }
    int maxPathSum(TreeNode* root) {
        int ans = root->val;
        dfs(root, ans);
        return ans;
    }
};
