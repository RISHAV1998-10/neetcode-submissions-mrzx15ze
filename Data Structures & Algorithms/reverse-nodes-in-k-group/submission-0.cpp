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
        
        ListNode* slow = head;
        ListNode* fast = head;
        int cnt=0;
        ListNode* newHead = NULL;
        ListNode* prevGroupTail = NULL;
        while(fast){
            for(int i=1; i<k; i++){
                fast = fast->next;
                if(!fast)
                    return newHead;
            }
            ListNode* startNextGroup = fast->next;
            ListNode* startPrevGroup = slow;
            ListNode* endPrevGroup = fast;
            endPrevGroup->next = NULL;
            ListNode* nl = reverseLL(startPrevGroup);
            if(cnt==0)
                newHead = nl;
            else
                prevGroupTail->next = nl;
            prevGroupTail = startPrevGroup;
            startPrevGroup->next = startNextGroup;
            fast=startNextGroup;
            slow=fast;
            cnt++;
        }

        return newHead;
    }
};
