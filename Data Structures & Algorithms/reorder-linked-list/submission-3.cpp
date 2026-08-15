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
    ListNode* reverseLL(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr){
            ListNode* temp = curr->next;
            curr->next=prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
    
    ListNode* mergeLL(ListNode* list1, ListNode* list2){
        ListNode* head = list1;
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;

        while(list1 && list2){
            ListNode* temp1 = list1->next;
            ListNode* temp2 = list2->next;
            list1->next = list2;
            list2->next = temp1;
            list1 = temp1;
            list2 = temp2;
        }
        
        return head;
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow=slow->next;
            if(fast->next)
                fast=fast->next->next;
        }

        ListNode* list2 = slow->next;
        slow->next=NULL;
        list2 = reverseLL(list2);
        mergeLL(head, list2);
    }
};
