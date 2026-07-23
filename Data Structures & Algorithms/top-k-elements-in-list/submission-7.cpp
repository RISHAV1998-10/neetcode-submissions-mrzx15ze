class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for(int x: nums)
            hash[x]++;

        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

        for(auto &[key, val]: hash){
            pq.push({val, key});
            if(pq.size()>k)
                pq.pop();
        }

        vector<int> res;
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            res.push_back(node.second);
        }

        return res;
    }
};
