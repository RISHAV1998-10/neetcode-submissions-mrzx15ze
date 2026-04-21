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
    int dfs(TreeNode* node, int &maxSum){
        if(!node)
            return 0;
        
        int leftMax = max(dfs(node->left, maxSum), 0);
        int rightMax = max(dfs(node->right, maxSum), 0);
        maxSum = max(maxSum, leftMax+rightMax+node->val);
        return node->val+max(leftMax, rightMax);
    }

    int maxPathSum(TreeNode* root) {
        if(!root)
            return 0;

        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum;
    }
};
