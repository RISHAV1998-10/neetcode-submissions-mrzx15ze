/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
private:
    ListNode* reverseLL(ListNode* l){
        ListNode* prev = NULL;
        ListNode* curr = l;
        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k==1)
            return head;
        
        ListNode* currGroupHead = head;
        ListNode* newHead = NULL;
        ListNode* prevGroupTail = NULL;

        while(currGroupHead){
            ListNode* currGroupTail = currGroupHead;
            for(int i=1; i<k; i++){
                currGroupTail=currGroupTail->next;
                if(!currGroupTail)
                    return newHead;
            }

            ListNode* nextGroupHead = currGroupTail->next;
            currGroupTail->next = NULL;
            ListNode* headReversed = reverseLL(currGroupHead);

            if(!newHead)
                newHead = currGroupTail;
            else
                prevGroupTail->next = currGroupTail;
            
            prevGroupTail = currGroupHead;
            currGroupHead->next = nextGroupHead;
            currGroupHead = nextGroupHead;
        }

        return newHead;
    }
};
