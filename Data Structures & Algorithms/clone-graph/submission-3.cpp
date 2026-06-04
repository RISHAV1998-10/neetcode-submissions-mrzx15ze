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
    Node* util(Node* node, unordered_map<Node*, Node*>& hash){

        if(hash.count(node))
            return hash[node];

        Node* copy = new Node(node->val);
        hash[node] = copy;
        for(Node* nei : node->neighbors)
            copy->neighbors.push_back(util(nei, hash));
        
        return copy;
    }

    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;

        unordered_map<Node*, Node*> hash;
        return util(node, hash);
    }
};
