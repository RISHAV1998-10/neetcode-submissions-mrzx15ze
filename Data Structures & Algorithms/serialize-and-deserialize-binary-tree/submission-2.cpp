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
private:
    void ser(TreeNode* node, string& s){
        if(!node){
            s+="#,";
            return;
        }

        s+=to_string(node->val)+",";
        ser(node->left, s);
        ser(node->right, s);
        return;
    }

    TreeNode* des(string& s, int& idx){
        if(s[idx]=='#'){
            idx+=2;
            return nullptr;
        }
        int j = s.find(',', idx);
        int x = stoi(s.substr(idx, j-idx));
        TreeNode* node = new TreeNode(x);
        idx=j+1;
        node->left = des(s, idx);
        node->right = des(s, idx);
        return node;
    }


public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        ser(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i=0;
        return des(data, i);
    }
};
