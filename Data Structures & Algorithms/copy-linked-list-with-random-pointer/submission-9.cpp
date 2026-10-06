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
        unordered_map<Node*, Node*> copy;

        Node* curr = head;
        while(curr){
            Node* node = new Node(curr->val);
            copy[curr] = node;
            curr = curr->next;
        }

        curr = head;
        while(curr){
            Node* copynode = copy[curr];
            copynode->next = copy[curr->next];
            copynode->random = copy[curr->random];
            curr=curr->next;
        }

        return copy[head];
    }
};
