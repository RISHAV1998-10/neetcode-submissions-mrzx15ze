/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> hash;
        Node* curr = head;
        while(curr){
            Node* node = new Node(curr->val);
            hash[curr] = node;
            curr = curr->next;
        }

        for(auto [node, copy] : hash){
            copy->next = node->next ? hash[node->next] : NULL;
            copy->random = node->random ? hash[node->random] : NULL;
        }
        return hash[head];
    }
};
