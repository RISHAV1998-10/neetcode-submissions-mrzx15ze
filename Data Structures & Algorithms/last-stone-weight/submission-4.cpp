class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while(pq.size()!=1 && !pq.empty()){
            int x = pq.top();
            pq.pop();
            int y = 0;
            if(!pq.empty()){
                y=pq.top();
                pq.pop();
            }
            if(x>y)
                pq.push(x-y);
        }

        return pq.empty() ? 0 : pq.top();
    }
};
