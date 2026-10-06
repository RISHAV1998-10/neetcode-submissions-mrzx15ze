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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int,ListNode*>>, greater<>> minH;
        for(ListNode* node : lists){
            if(node)
                minH.push({node->val, node});
        }

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while(!minH.empty()){
            auto [val, node] = minH.top();
            minH.pop();

            curr->next = node;
            if(node->next)
                minH.push({node->next->val, node->next});
            
            curr=curr->next;
        }

        return dummy->next;

    }
};
