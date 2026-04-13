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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> q;
        // q.push(root);
        TreeNode* curr = root;

        while(!q.empty() || curr!=NULL){
            while(curr!=NULL){
                q.push(curr);
                curr=curr->left;
            }
            curr = q.top();
            q.pop();
            k--;
            if(k==0)
                return curr->val;
            
            curr = curr->right;
        }

        return 0;
    }
};
