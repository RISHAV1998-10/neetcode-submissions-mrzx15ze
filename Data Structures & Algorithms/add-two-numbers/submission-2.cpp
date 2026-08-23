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
        ListNode* l = new ListNode(0);
        ListNode* curr = l;
        int c = 0;
        while(l1||l2||c){
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;
            int sum = v1+v2+c;
            ListNode* node = new ListNode(sum%10);
            c = sum/10;
            curr->next = node;
            curr = curr->next;
            if(l1)
                l1=l1->next;
            if(l2)
                l2=l2->next;
        }
        ListNode* ans = l->next;
        delete l;
        return ans;
    }
};
