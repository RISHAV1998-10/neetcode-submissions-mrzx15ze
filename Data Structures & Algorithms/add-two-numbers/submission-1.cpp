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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* curr3 = dummy;
        int carry = 0;

        while(curr1 || curr2 || carry){
            int val1 = curr1!=NULL ? curr1->val : 0;
            int val2 = curr2!=NULL ? curr2->val : 0;
            int sum = carry+val1+val2;
            curr3->next = new ListNode(sum%10);            
            carry = sum/10;

            if(curr1) curr1 = curr1->next;
            if(curr2) curr2 = curr2->next;
            curr3 = curr3->next;
        }

        return dummy->next;
    }
};
