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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }

    ListNode* mergeLL(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while(l1 && l2){
            curr->next = l1;
            l1=l1->next;
            curr=curr->next;

            curr->next=l2;
            l2=l2->next;
            curr=curr->next;

        }

        curr->next = l1 ? l1 : l2;

        return dummy->next;
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* l2 = slow->next;
        slow->next = NULL;
        l2 = reverse(l2);
        head = mergeLL(head, l2);
    }
};
