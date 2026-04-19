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
    void dfs(TreeNode* node, int maxVal, int& cnt){
        if(!node)
            return;
        
        if(node->val >= maxVal)
            cnt++;
        maxVal=max(maxVal, node->val);
        dfs(node->left, maxVal, cnt);
        dfs(node->right, maxVal, cnt);
    }

    int goodNodes(TreeNode* root) {
        if(!root)
            return 0;

        int cnt = 0;
        dfs(root, root->val, cnt);
        return cnt;
    }
};
