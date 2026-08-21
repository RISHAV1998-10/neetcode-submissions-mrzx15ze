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
    int helper(TreeNode* root, int currMax){
        if(!root)
            return 0;

        int rootans = 0;
        if(root->val >= currMax){
            rootans = 1;
            currMax = root->val;
        }
        int lans = helper(root->left, currMax);
        int rans = helper(root->right, currMax);
        return lans+rans+rootans;
    }
    int goodNodes(TreeNode* root) {
        return helper(root, root->val);
    }
};
