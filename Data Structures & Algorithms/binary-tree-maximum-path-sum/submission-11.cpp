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

        int lmax = dfs(root->left, ans);
        lmax=lmax>0?lmax:0;
        int rmax = dfs(root->right, ans);
        rmax=rmax>0?rmax:0;
        ans=max(ans, lmax+rmax+root->val);
        return root->val+max(lmax, rmax);
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        dfs(root, ans);
        return ans;
    }
};
