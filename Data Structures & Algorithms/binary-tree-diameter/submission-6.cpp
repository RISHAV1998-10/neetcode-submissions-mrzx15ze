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
    int dfs(TreeNode* root, int &res){
        if(!root)
            return 0;

        int ls = dfs(root->left, res);
        int rs = dfs(root->right, res);
        
        res=max(res, ls+rs);
        return 1+max(ls, rs);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int ans=0;
        dfs(root, ans);
        return ans;
    }
};
