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
    unordered_map<int, int> inIdx;
    int preIdx = 0;
    TreeNode* dfs(vector<int>& preorder, int l, int r){
        if(l>r)
            return NULL;
        
        int rootVal = preorder[preIdx];
        preIdx++;
        int mid = inIdx[rootVal];
        TreeNode* root = new TreeNode(rootVal);
        root->left = dfs(preorder, l, mid-1);
        root->right = dfs(preorder, mid+1, r);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i=0; i<inorder.size(); i++)
            inIdx[inorder[i]]=i;

        return dfs(preorder, 0, n-1);
    }
};
