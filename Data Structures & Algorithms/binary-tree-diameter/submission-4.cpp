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
    int findHt(TreeNode* root, int &dia){
        if(!root)
            return 0;

        int lh = findHt(root->left, dia);
        int rh = findHt(root->right, dia);
        dia = max(dia, lh+rh);
        return 1+max(lh,rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int dia =0 ;
        findHt(root, dia);

        return dia;
    }
};
