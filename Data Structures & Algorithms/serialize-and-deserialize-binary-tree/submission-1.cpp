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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "#";

        return to_string(root->val)+','+serialize(root->left)+','+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i=0;
        return build(data, i);
    }

    TreeNode* build(string& s, int& i){
        if(s[i]=='#'){
            i+=2;   // skips # and ,
            return NULL;
        }

        int j = s.find(',', i);
        int num = stoi(s.substr(i, j-i));
        i=j+1;

        TreeNode* root = new TreeNode(num);
        root->left = build(s, i);
        root->right = build(s, i);
        return root;
    }
};
