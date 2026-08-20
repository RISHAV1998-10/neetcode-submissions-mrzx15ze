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
    ListNode* merge2Lists(ListNode* list1, ListNode* list2){
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while(list1 && list2){
            if(list1->val > list2->val){
                curr->next = list2;
                list2=list2->next;
            }
            else{
                curr->next = list1;
                list1=list1->next;
            }

            curr=curr->next;
        }

        curr->next = list1 ? list1 : list2;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;
        
        int interval = 1;
        while(interval < lists.size()){
            for(int i=0; i+interval<lists.size(); i+=interval*2)
                lists[i] = merge2Lists(lists[i], lists[i+interval]);

            interval*=2;
        }
        
        return lists[0];
    }
};
