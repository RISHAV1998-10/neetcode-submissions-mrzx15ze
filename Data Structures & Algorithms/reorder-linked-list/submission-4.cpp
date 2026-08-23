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

    ListNode* mergeLL(ListNode* l1, ListNode* l2){
        ListNode* head = l1;
        while(l1 && l2){
            ListNode* t1 = l1->next;
            ListNode* t2 = l2->next;
            l1->next = l2;
            l2->next = t1;
            l1 = t1;
            l2 = t2;
        }

        return head;
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* newLL = slow->next;
        slow->next = NULL;
        newLL = reverseLL(newLL);
        head = mergeLL(head, newLL);
    }
};
