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
    int dfs(TreeNode* root, int &ans){
        if(!root)
            return 0;

        int ls = dfs(root->left, ans);
        ls= ls>0?ls : 0;
        int rs = dfs(root->right, ans);
        rs= rs>0?rs : 0;

        ans = max(ans, root->val + ls+rs);
        return root->val + max(ls, rs);
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        dfs(root, ans);
        return ans;
    }
};
