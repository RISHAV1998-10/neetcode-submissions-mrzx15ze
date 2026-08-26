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
    unordered_map<int, int> inMap;
    int preIdx=0;
    TreeNode* dfs(vector<int>& preorder, int leftInOrd, int rightInOrd){
        if(leftInOrd > rightInOrd)
            return nullptr;

        int nodeVal = preorder[preIdx];
        preIdx++;
        int inMid = inMap[nodeVal];
        int leftPreOrdsize = inMid - leftInOrd;
        TreeNode* node = new TreeNode(nodeVal);
        node->left = dfs(preorder, leftInOrd, inMid-1);
        node->right = dfs(preorder, inMid+1, rightInOrd);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i=0; i<n; i++)
            inMap[inorder[i]]=i;
        
        return dfs(preorder, 0, n-1);
    }
};
