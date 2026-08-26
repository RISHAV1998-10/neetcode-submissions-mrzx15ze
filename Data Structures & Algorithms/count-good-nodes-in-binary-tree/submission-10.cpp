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
    int dfs(TreeNode* node, int maxVal){
        if(!node)
            return 0;
        int cnt = node->val >= maxVal ? 1 : 0;
        maxVal = max(maxVal, node->val);
        return cnt + dfs(node->left, maxVal)
                   + dfs(node->right, maxVal);
    }

    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};
