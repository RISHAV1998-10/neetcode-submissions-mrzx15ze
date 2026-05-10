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
    int dfs(TreeNode* node, int& val){
        if(!node)
            return 0;
        
        int lt = max(dfs(node->left, val), 0);
        int rt = max(dfs(node->right, val), 0);
        val=max(val, node->val+lt+rt);
        return node->val+max(lt,rt);
    }
    int maxPathSum(TreeNode* root) {
        if(!root)
            return 0;

        int val=root->val;
        dfs(root, val);
        return val;
    }
};
