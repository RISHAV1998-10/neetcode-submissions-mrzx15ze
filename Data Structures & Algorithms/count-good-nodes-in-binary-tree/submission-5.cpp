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
    void dfs(TreeNode* node, int &cnt, int maxVal){
        if(!node)
            return;

        if(node->val >= maxVal){
            cnt++;
            cout<<"val: "<<node->val<<" maxVal: "<<maxVal<<"\n";
        }

        maxVal=max(maxVal, node->val);
        dfs(node->left, cnt, maxVal);        
        dfs(node->right, cnt, maxVal);        
    }

    int goodNodes(TreeNode* root) {
        if(!root)
            return 0;

        int cnt = 0;
        dfs(root, cnt, INT_MIN);
        return cnt;
    }
};
