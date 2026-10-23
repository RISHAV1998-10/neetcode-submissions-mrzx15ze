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
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<>> pq;
        for(auto l : lists)
            if(l)
                pq.push({l->val, l});

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while(!pq.empty()){
            ListNode* node = pq.top().second;
            pq.pop();

            if(node->next)
                pq.push({node->next->val, node->next});

            curr->next = node;
            curr = curr->next;
        }

        return dummy->next;
    }
};
