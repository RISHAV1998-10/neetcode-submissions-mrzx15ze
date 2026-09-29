class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for(int n: nums)
            hash[n]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        for(const auto& [num, freq] : hash){
            pq.push({freq, num});

            if(pq.size()>k)
                pq.pop();
        }

        vector<int> res;
        while(!pq.empty()){
            auto [freq, num] = pq.top();
            pq.pop();
            res.push_back(num);
        }

        return res;
    }
};
