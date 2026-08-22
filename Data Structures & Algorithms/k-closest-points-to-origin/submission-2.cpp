class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<int, vector<int>>> maxHeap;
        for(auto p: points){
            int d = p[0]*p[0] + p[1]*p[1];
            maxHeap.push({d, p});
            if(maxHeap.size() > k)
                maxHeap.pop();
        }

        while(!maxHeap.empty()){
            auto [d, p] = maxHeap.top();
            maxHeap.pop();
            res.push_back(p);
        }

        return res;
    }
};
