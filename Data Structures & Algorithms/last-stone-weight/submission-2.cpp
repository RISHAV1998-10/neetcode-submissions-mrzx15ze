class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while(!pq.empty()){
            int t1 = pq.top();
            pq.pop();
            int t2=0;
            if(!pq.empty()){
                t2=pq.top();
                pq.pop();
                if(t1!=t2)
                    pq.push(abs(t1-t2));
            }
            else
                return t1;
        }

        return pq.empty() ? 0 : pq.top();        
    }
};
