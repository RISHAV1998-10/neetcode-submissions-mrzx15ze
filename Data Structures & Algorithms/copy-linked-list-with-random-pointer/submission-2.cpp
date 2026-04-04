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
        hash[NULL]=NULL;
        Node* temp = head;

        while(temp){
            Node* copyNode = new Node(temp->val);
            hash[temp] = copyNode;
            temp = temp->next;
        }

        Node* copyHead = hash[head];
        Node* curr = head; 

        while(curr){
            Node* copy = hash[curr];
            copy->next=hash[curr->next];
            copy->random=hash[curr->random];
            curr = curr->next;
        }
        

        return copyHead;
    }
};
