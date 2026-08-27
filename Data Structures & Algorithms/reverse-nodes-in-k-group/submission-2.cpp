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
public:
    ListNode* reverse(ListNode* l){
        ListNode* prev = nullptr;
        ListNode* curr = l;
        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr=temp;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* newHead = nullptr;
        ListNode* currGroupHead = head;
        ListNode* prevGroupTail = nullptr;
        while(currGroupHead){
            ListNode* currGroupTail = currGroupHead;
            for(int i=1; i<k; i++){
                if(!currGroupTail->next){
                    prevGroupTail->next = currGroupHead;
                    return newHead ? newHead : head;
                }
                currGroupTail=currGroupTail->next;
            }

            ListNode* nextGroupHead = currGroupTail->next;
            currGroupTail->next=nullptr;
            ListNode* reverseHead = reverse(currGroupHead);
            if(!newHead)
                newHead = reverseHead;
            else
                prevGroupTail->next = reverseHead;

            prevGroupTail=currGroupHead;
            currGroupHead=nextGroupHead;
        }
        return newHead;
    }
};
