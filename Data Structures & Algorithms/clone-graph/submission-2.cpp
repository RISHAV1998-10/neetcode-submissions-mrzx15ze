/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> hash;
        return dfs(node, hash);
    }

    Node* dfs(Node* node, unordered_map<Node*, Node*>& hash){
        if(node == NULL)
            return NULL;

        // if(hash.count(node))
        //     return hash[node];
        
        Node* copy = new Node(node->val);
        hash[node] = copy;
        for(auto nei : node->neighbors){
            if(hash.find(nei)==hash.end()){
                copy->neighbors.push_back(dfs(nei, hash));
            }
            else{
                copy->neighbors.push_back(hash[nei]);
            }
        }
        return copy;
    }
};
